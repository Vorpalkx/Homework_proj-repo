all: sort

sort: main.o filling_array.o quick_sort.o
	gcc main.o filling_array.o quick_sort.o -o sort

main.o: main.c
	gcc -c main.c

filling_array.o: filling_array.c
	gcc -c filling_array.c

quick_sort.o: quick_sort.s
	gcc -c quick_sort.s -o quick_sort.o

clean:
	rm -rf *.o sort
