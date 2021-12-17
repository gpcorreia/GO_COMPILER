#ifndef SEMANTICS_H
#define SEMANTICS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "gocompiler.h"
#include "symbols_table.h"

table_elem *symbols_table;

table_elem *check_root(Tree *head);
void prepare2anoted(Tree *func);
varDecl *check_var_decl(Tree *varDecl_node);
funcDecl *check_func_decl(Tree *funcHeader);
void print_tabel(table_elem *root);

#endif