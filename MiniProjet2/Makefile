all : mainLC

biblioLC.o : biblioLC.h biblioLC.c
	gcc -Wall -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -Wall -c entreeSortieLC.c

mainLC : mainLC.c biblioLC.o entreeSortieLC.o
	gcc -Wall -o mainLC biblioLC.o entreeSortieLC.o mainLC.c
	
biblioH.o : biblioH.h biblioH.c
	gcc -Wall -c biblioH.c

entreeSortieH.o : entreeSortieH.c entreeSortieH.h biblioH.h
	gcc -Wall -c entreeSortieH.c

mainH : mainH.c biblioH.o entreeSortieH.o
	gcc -Wall -o mainH biblioH.o entreeSortieH.o mainH.c

clean :
	rm -rf *.o mainLC
