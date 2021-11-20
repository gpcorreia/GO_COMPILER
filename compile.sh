lex gocompiler.l
yacc -d -t -v -y gocompiler.y
cc -o gocompiler y.tab.c lex.yy.c
./gocompiler -t < meta2/error_unbalanced_par.dgo
