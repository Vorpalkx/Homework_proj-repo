all: rhyme

rhyme: rhyme.o cyclic_list.o
	gcc rhyme.o cyclic_list.o -o rhyme

rhyme.o: rhyme.c
	gcc -c rhyme.c -o rhyme.o

cyclic_list.o: ../List/cyclic_list.c
	gcc -c ../List/cyclic_list.c -o cyclic_list.o

clean:
	rm -rf *.o rhyme
