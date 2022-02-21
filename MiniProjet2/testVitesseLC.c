
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <time.h>


int main(int argc, char **argv) {
    FILE *stream = fopen("vitesseLC.","w");
    if (stream == NULL) {
        fprintf(stderr,"Erreur de l'ouverture du fichier\n");
        exit(1);
    }
    if (argc != )   {
        fprintf(stderr, "usage : %s <nom_du_fichier> <nb_de_lignes> <taille_table_hachage> ")
    }




    return 0;
}