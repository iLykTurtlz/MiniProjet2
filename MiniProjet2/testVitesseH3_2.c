
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"
#include <time.h>


int main(int argc, char **argv) {
    FILE *stream = fopen("vitesseH3_2.txt","w");
    if (stream == NULL) {
        fprintf(stderr,"Erreur de l'ouverture du fichier\n");
        exit(1);
    }
    if (argc != 6)   {
        fprintf(stderr, "usage : %s <nb_de_recherches> <num> <titre> <auteur> <1 si present, 0 si absent>", argv[0]);
        exit(1);
    }

    int nb_recherches = atoi(argv[1]);
    int numLivre = atoi(argv[2]);
    char titre[256];
    char auteur[256];
    strcpy(titre, argv[3]);
    strcpy(auteur, argv[4]);
    int presence = atoi(argv[5]);

    BiblioH *b;

    double tempsParNum=0., tempsParTitre=0., tempsParAuteur=0.;
    clock_t temps_initial, temps_final;
    LivreH *livre;

    int m = 100; /*taille de la table de hashage*/
    
    for (int i=0; i<30; i++) {
        /*création de la table*/
        b = charger_n_entrees("GdeBiblio.txt", 100000, m);

        /*chercher par numero*/
        for (int j=0; j<nb_recherches; j++) {
            temps_initial = clock();
            livre = rechercher_livre_num(b,numLivre);
            temps_final = clock();
            tempsParNum += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;
        }

        if (!livre != !presence) {   /*test si la presence ou absence est verifee*/
            fprintf(stderr,"erreur de recherche\n");
            liberer_biblio(b);
            return 1;
        }

        /*chercher par titre*/
        for (int j=0; j<nb_recherches; j++) {
            temps_initial = clock();
            livre = rechercher_livre_titre(b,titre);
            temps_final = clock();
            tempsParTitre += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;
        }


        if (!livre != !presence) {   /*test si la presence ou absence est verifee*/
            fprintf(stderr,"erreur de recherche\n");
            liberer_biblio(b);
            return 1;
        }

        /*chercher par auteur*/
        for (int j=0; j<nb_recherches; j++) {
            temps_initial = clock();
            livre = rechercher_auteur(b,auteur);
            temps_final = clock();
            tempsParAuteur += (double)(temps_final-temps_initial)/CLOCKS_PER_SEC;
        }


        if (!livre != !presence) {   /*test si la presence ou absence est verifee*/
            fprintf(stderr,"erreur de recherche\n");
            liberer_biblio(b);
            return 1;
        }
        fprintf(stream, "%d %f %f %f\n", m, tempsParNum, tempsParTitre, tempsParAuteur);
        m += 100;
        liberer_biblio(b);
    }
    fclose(stream);

    return 0;
}



