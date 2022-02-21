all : mainLC

biblioLC.o : biblioLC.h biblioLC.c
	gcc -Wall -ggdb -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc -Wall -ggdb -c entreeSortieLC.c

mainLC : mainLC.c biblioLC.o entreeSortieLC.o
	gcc -Wall -ggdb -o mainLC biblioLC.o entreeSortieLC.o mainLC.c
	
biblioH.o : biblioH.h biblioH.c
	gcc -Wall -ggdb -c biblioH.c

entreeSortieH.o : entreeSortieH.c entreeSortieH.h biblioH.h
	gcc -Wall -ggdb -c entreeSortieH.c

mainH : mainH.c biblioH.o entreeSortieH.o
	gcc -Wall -ggdb -o mainH biblioH.o entreeSortieH.o mainH.c

clean :
	rm -rf *.o mainLC
