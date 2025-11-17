all: list

list: main.o list.o functional_menu.o test_functional_menu.o
	gcc main.o list.o functional_menu.o test_functional_menu.o -o list

main.o: main.c
	gcc -c main.c -o main.o

list.o: ../List/list.c
	gcc -c ../List/list.c -o list.o

functional_menu.o: functional_menu.c
	gcc -c functional_menu.c -o functional_menu.o

test_functional_menu.o: test_functional_menu.c
	gcc -c test_functional_menu.c -o test_functional_menu.o

clean:
	rm -rf *.o list
