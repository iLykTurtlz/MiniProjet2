
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <time.h>


int main(int argc, char **argv) {
    FILE *stream = fopen("vitesseLC3_3.txt","w");
    if (stream == NULL) {
        fprintf(stderr,"Erreur de l'ouverture du fichier\n");
        exit(1);
    }
    if (argc != 3)   {
        fprintf(stderr, "usage : %s <nb_de_recherches> <nb_lignes_max>", argv[0]);
        exit(1);
    }

    int nb_recherches = atoi(argv[1]);
    int nb_lignes_max = atoi(argv[2]);
    
    Biblio *b;
 
    double temps;
    clock_t temps_initial, temps_final;
    Biblio *res;


    
    for (int n=1000; n<=nb_lignes_max; n+=1000) {
        temps = 0.;
        b = charger_n_entrees("GdeBiblio.txt", n);
        for (int j=0; j<nb_recherches; j++) {
            temps_initial = clock();
            res = plusieurs_exemp(b);
            temps_final = clock();
            temps += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;
        }
        fprintf(stream, "%d %f\n", n, temps);
        liberer_biblio(b);
    }
    fclose(stream);
    return 0;
}
