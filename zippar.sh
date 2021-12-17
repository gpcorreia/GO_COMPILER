#!/bin/sh
rm lex.yy.c y.tab.h y.tab.c
zip -r ./gocompiler.zip ./gocompiler.l ./gocompiler.y *.c *.h