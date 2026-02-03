all: palindrome

palindrome: palindrome.o list.o
	gcc palindrome.o list.o -o palindrome

palindrome.o: palindrome.c
	gcc -c palindrome.c -o palindrome.o

list.o: list.c
	gcc -c list.c -o list.o

clean:
	rm -rf *.o list
