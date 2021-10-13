# Compiladores 2021/22

Este repositório reúne os **casos de teste criados por estudantes** para verificarem os compiladores.

* Cada estudante deve contribuir com programas que lhe tenham sido úteis.
* Partilhar um caso de teste por meta é suficiente: qualidade é melhor do que quantidade.
* É necessário testar variáveis, funções, operadores, condições, erros, etc.
* Os programas a compilar devem ter extensão **.go** ou **.dgo**

O **diff** facilita a identificação de diferenças entre o resultado correto e o resultado obtido:

**gocompiler -l &lt; factorial.dgo | diff factorial.out -**

**Nota 1:** devem ter espírito crítico relativamente aos ficheiros **.out** com os resultados esperados.

**Nota 2:** a ferramenta **gdb** é muito útil para diagnosticar erros de programação.

**Nota 3:** para começar a contribuir para este repositório faz-se fork, clone, branch, commit, push, merge request (via web).
