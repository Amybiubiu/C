run: scanner
	./scanner < test.txt

scanner: lex.yy.c
	gcc -o $@ $<

lex.yy.c: scanner.l
	flex $<