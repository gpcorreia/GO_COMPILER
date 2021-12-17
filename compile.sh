lex gocompiler.l
yacc -d gocompiler.y
cc -o gocompiler *.c
./gocompiler -s < meta3/inputs/errors.dgo > meta3/isso/errors.out
cat meta3/isso/errors.out