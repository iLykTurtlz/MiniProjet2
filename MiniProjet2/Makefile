all : mainLC

biblioLC.o : biblioLC.h biblioLC.c
	gcc -Wall -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -Wall -c entreeSortieLC.c

mainLC : main.c biblioLC.o entreeSortieLC.o
	gcc -Wall -o mainLC biblioLC.o entreeSortieLC.o main.c

clean :
	rm -rf *.o mainLC
