lex gocompiler.l
yacc -d gocompiler.y
cc -o gocompiler *.c
./gocompiler -s < meta3/inputs/factorial.dgo > meta3/isso/factorial.out
cat meta3/isso/factorial.out