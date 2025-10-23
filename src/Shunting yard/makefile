all: postfix

postfix: stack.o filling_expression.o main.o
	gcc stack.o filling_expression.o main.o -o postfix

stack.o: ../Stack/stack.c
	gcc -c ../Stack/stack.c -o stack.o

filling_expression.o: filling_expression.c
	gcc -c filling_expression.c -o filling_expression.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm -rf *.o postfix
