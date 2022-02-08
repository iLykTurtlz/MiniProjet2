all : main

biblioLC.o : biblioLC.h biblioLC.c
	gcc -Wall -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -Wall -c entreeSortieLC.c

main : main.c biblioLC.o entreeSortieLC.o
	gcc -Wall -o main biblioLC.o entreeSortieLC.o main.c

clean :
	rm -rf *.o main
