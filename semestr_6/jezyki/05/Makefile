main: lex.yy.c main.tab.c
	gcc main.tab.c -lfl -Wall -o main
lex.yy.c: main.l
	flex main.l
main.tab.c: main.y
	bison main.y
clean:
	rm -fr lex.yy.c main.tab.c
