#!/bin/bash


PATH_TO_SOLUTION_FOLDER="solutions"
PATH_TO_OUTPUTS="outputs"
PATH_TO_INPUTS="inputs"




COMPILER_FILE_NAME="gocompiler"
EXECUTABLE_FILE_NAME=$COMPILER_FILE_NAME


RED="\x1B[31m"
GREEN="\x1B[32m"
RESET="\x1B[0m"
BLUE="\x1B[34m"

TRUE=1
FALSE=0


META_1="meta1"
META_2="meta2"
META_3="meta3"
META_4="meta4"

STOP_ON_FAILED_TEST=$FALSE
DIFF=$TRUE
OUTPUT_TO_TERMINAL=$FALSE
META=$META_1
META_NAO_EXISTENTE=""

FILE_PATH=""

COMPILER_FLAGS=""
COMPILE=$TRUE

DELETE_EXECUTABLE=$TRUE





function compile() {
        flex ${EXECUTABLE_FILE_NAME}.l && yacc -y -d -t -v ${COMPILER_FILE_NAME}.y && clang-7 -g -Wall -Wno-unused-function -o ${COMPILER_FILE_NAME} *.c

        
}


function run()  {
    if [ "$FILE_PATH" = "" ]
    then
        run_tests
    else
        test_file
    fi        

    if [ $DELETE_EXECUTABLE -eq $TRUE ]; then
        rm ${EXECUTABLE_FILE_NAME} lex.yy.c
    fi
}

function test_file() {
    file=$(basename "$FILE_PATH")
    file_no_ext=${file%.*}
    if [ $OUTPUT_TO_TERMINAL -eq $TRUE ]
    then
        ./${EXECUTABLE_FILE_NAME} ${COMPILER_FLAGS} < $FILE_PATH
    else
        ./${EXECUTABLE_FILE_NAME} ${COMPILER_FLAGS} < $FILE_PATH &> ${META}/${PATH_TO_OUTPUTS}/${file_no_ext}.out
    fi

    
    if [ $DIFF -eq $TRUE ]
    then
        if [[ -d "$META" ]]
        then
            if [ -f "${META}/${file_no_ext}.out" ]
                then
                    diff -y --strip-trailing-cr -s ${META}/${PATH_TO_OUTPUTS}/${file_no_ext}.out ${META}/${file_no_ext}.out &>DIFFOUT
                    
                    if [ $? -eq 0 ]; then
                        echo -e ✅ "${GREEN}TEST PASSED!!${RESET}" $FILE_PATH
                    else
                        echo -e ❌ "${RED}TEST FAILED!!${RESET}" $FILE_PATH
                    fi
                # rm DIFFOUT
            fi
        else
            echo "Directory $META does not exist"
        fi
    fi
}

function run_tests() {
    for file_path in ${META}/${PATH_TO_INPUTS}/*.dgo; do
        if  [[ -d "${META}/${PATH_TO_INPUTS}" ]]
        then
            file=$(basename "$file_path")
            file_no_ext=${file%.*}
            # echo $file
            if [ $OUTPUT_TO_TERMINAL -eq $TRUE ]
            then
                ./${EXECUTABLE_FILE_NAME} ${COMPILER_FLAGS} < ${META}/${PATH_TO_INPUTS}/${file_no_ext}.dgo
            else
                ./${EXECUTABLE_FILE_NAME} ${COMPILER_FLAGS} < ${META}/${PATH_TO_INPUTS}/${file_no_ext}.dgo &> ${META}/${PATH_TO_OUTPUTS}/${file_no_ext}.out
            fi

            if [ $DIFF -eq $TRUE ]
            then
                    diff -y --strip-trailing-cr -s ${META}/${file_no_ext}.out ${META}/${file_no_ext}.out &>DIFFOUT
                    
                    if [ $? -eq 0 ]; then
                        echo -e ${GREEN}✔ "TEST PASSED!!${RESET}" ${file_no_ext}.dgo
                    else
                        echo -e ${RED}❌ "TEST FAILED!!${RESET}" ${file_no_ext}.dgo
                        if [ $STOP_ON_FAILED_TEST -eq $TRUE ]; then
                            exit
                        fi
                    fi
                    rm DIFFOUT
            fi
        else
            echo "Directories \"$META/$PATH_TO_INPUTS\" and/or \"$META/$PATH_TO_OUTPUTS\" and/or \"$META/$PATH_TO_SOLUTION_FOLDER\" do not exist"
        fi
    done
}

function main() {
    if [ $COMPILE -eq $TRUE ];then
        compile
    fi
    run
}


for option in "$@"; do
    case $option in
        # não faz o diff
        --no-diff)
            DIFF=$FALSE
            ;;
        # output no terminal
        --terminal-output | -to)
            OUTPUT_TO_TERMINAL=$TRUE
            ;;
        # analisa um ficheiro específico
        -f=*)
            FILE_PATH="${option#*=}"
            ;;

        # path para o folder de solutions    
        --solutions=*)
            PATH_TO_SOLUTION_FOLDER="${option#*=}"
            ;;
        # path para o folder de inputs    
        --inputs=*)
            PATH_TO_INPUTS="${option#*=}"
            ;;
        # path para o folder de outputs    
        --outputs=*)
            PATH_TO_OUTPUTS="${option#*=}"
            ;;
        # Análise lexical
        -l)
            COMPILER_FLAGS+=" -l"
            ;;
        # Análise sintática
        -t)
            COMPILER_FLAGS+=" -t"
            if [ $META != $META_3 ]; then
                META=$META_2
            fi
            ;;
        # Análise sintática
        -s)
            COMPILER_FLAGS+=" -s"
            META=$META_3
            ;;
        # A meta 
        --meta | -m)
            META="m${option#*=}"
            ;;
        --stop-on-fail | -sof)
            STOP_ON_FAILED_TEST=$TRUE
            ;;
        
        --no-compile | -nc)
            COMPILE=$FALSE
            ;;

        --exe=*)
            EXECUTABLE_FILE_NAME="${option#*=}"
            DELETE_EXECUTABLE=$FALSE
            ;;
        
    esac
done

main

exit


