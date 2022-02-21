all : mainLC testLC mainH testH

biblioLC.o : biblioLC.h biblioLC.c
	gcc -Wall -ggdb -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -Wall -ggdb -c entreeSortieLC.c

testLC :  testLC.c biblioLC.o entreeSortieLC.o
	gcc -Wall -ggdb -o testLC biblioLC.o entreeSortieLC.o testLC.c

mainLC : mainLC.c biblioLC.o entreeSortieLC.o
	gcc -Wall -ggdb -o mainLC biblioLC.o entreeSortieLC.o mainLC.c
	
biblioH.o : biblioH.h biblioH.c
	gcc -Wall -ggdb -c biblioH.c

entreeSortieH.o : entreeSortieH.c entreeSortieH.h biblioH.h
	gcc -Wall -ggdb -c entreeSortieH.c

testH :  testH.c biblioH.o entreeSortieH.o
	gcc -Wall -ggdb -o testH biblioH.o entreeSortieH.o testH.c

mainH : mainH.c biblioH.o entreeSortieH.o
	gcc -Wall -ggdb -o mainH biblioH.o entreeSortieH.o mainH.c

clean :
	rm -rf *.o mainLC
