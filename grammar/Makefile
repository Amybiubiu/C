OBJ = y.tab.c lex.yy.c
run: tcc
	./tcc

tcc: $(OBJ)
	gcc -o $@ $(OBJ)

lex.yy.c: scanner.l y.tab.c
	flex $<

y.tab.c: grammar.y
	bison -vdty $<
