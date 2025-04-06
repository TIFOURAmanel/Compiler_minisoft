flex lex.l

bison -d synt.y    

gcc lex.yy.c synt.tab.c -lfl -ly -o L3_Soft

L3_Soft.exe<test.txt