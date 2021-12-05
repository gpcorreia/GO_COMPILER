lex gocompiler.l
yacc -d gocompiler.y
cc -o gocompiler y.tab.c lex.yy.c
./gocompiler -s < meta3/inputs/variable_func_assign_errors.dgo