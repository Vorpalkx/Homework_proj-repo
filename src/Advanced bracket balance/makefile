all: balance

balance: main.o stack.o string_filling.o bracket_balance.o
	gcc main.o stack.o string_filling.o bracket_balance.o -o balance

main.o: main.c
	gcc -c main.c -o main.o

stack.o: ../Stack/stack.c
	gcc -c ../Stack/stack.c -o stack.o
	
string_array.o: string_array.c
	gcc -c string_filling.c -o string_filling.o

bracket_balance.o: bracket_balance.c
	gcc -c bracket_balance.c -o bracket_balance.o

clean:
	rm -rf *.o balance
