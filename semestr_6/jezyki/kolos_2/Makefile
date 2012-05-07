all: main
	
main: main.tab.c lex.yy.c
	gcc main.tab.c -o main -lfl
main.tab.c: main.y lex.yy.c
	bison main.y
lex.yy.c: main.l
	flex main.l
clean:
	rm -f lex.yy.c main.tab.c
