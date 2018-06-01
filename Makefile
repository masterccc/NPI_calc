calculatrice : stack.o prefix.o lex.yy.o
	gcc -o calculatrice stack.o prefix.o lex.yy.o -lfl

stack.o :
	gcc -c stack.c

lex.yy.o:
	gcc -c lex.yy.c -lfl

clean:
	rm *.o
