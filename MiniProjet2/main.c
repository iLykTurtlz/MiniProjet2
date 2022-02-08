#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

int main(int argc, char **argv)  {
    if (argc != 3)  {
        printf("usage : %s <nom_du_fichier> <nb_de_lignes>",argv[0]);
        exit(1);
    }
    char nomfic[256];
    strcpy(nomfic,argv[1]);
    int nb = atoi(argv[2]);
    printf("%s %d\n",nomfic, nb);
    
    Biblio *b = charger_n_entrees(nomfic, nb);
    afficher_biblio(b);
    liberer_biblio(b);
    return 0;

}