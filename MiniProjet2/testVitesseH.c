
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"
#include <time.h>


int main(int argc, char **argv) {
    FILE *stream = fopen("vitesseLC3_1.txt","w");
    if (stream == NULL) {
        fprintf(stderr,"Erreur de l'ouverture du fichier\n");
        exit(1);
    }
    if (argc != 5)   {
        fprintf(stderr, "usage : %s <nb_de_recherches> <num> <titre> <auteur>", argv[0]);
        exit(1);
    }

    int nb_recherches = atoi(arg[1]);
    int numLivre = atoi(arg[2]);
    char titre[256];
    char auteur[256];
    strcpy(titre, arg[3]);
    strcpy(auteur, arg[4]);
    BiblioH *b= charger_n_entrees("GdeBiblio.txt", 100000, 500);

    double tempsParNum=0., tempsParTitre=0., tempsParAuteur=0.;
    clock_t temps_initial, temps_final;
    LivreH *livre;


    
    for (int i=0; i<nb_recherches; i++) {
        /*chercher par numero*/
        temps_initial = clock();
        livre = rechercher_livre_num(b,numLivre);
        temps_final = clock();
        tempsParNum += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;

        if (!livre) {   /*test facile à modifier pour les cas où le livre est présent ou absent*/
            fprintf(stderr,"erreur de recherche\n");
            liberer_biblio(b);
            return 1;
        }

        /*chercher par titre*/
        temps_initial = clock();
        livre = rechercher_livre_titre(b,titre);
        temps_final = clock();
        tempsParTitre += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;


        if (!livre) {   /*test facile à modifier pour les cas où le livre est présent ou absent*/
            fprintf(stderr,"erreur de recherche\n");
            liberer_biblio(b);
            return 1;
        }

        /*chercher par auteur*/
        temps_initial = clock();
        livre = rechercher_livre_auteur(b,auteur);
        temps_final = clock();
        tempsParAuteur += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;


        if (!livre) {   /*test facile à modifier pour les cas où le livre est présent ou absent*/
            fprintf(stderr,"erreur de recherche\n");
            liberer_biblio(b);
            return 1;
        }
    }












    return 0;
}


