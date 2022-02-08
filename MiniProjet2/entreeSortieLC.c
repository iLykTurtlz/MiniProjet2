#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"


Biblio *charger_n_entrees(char *nomfic, int n) {
    FILE *f = fopen(nomfic, "r");
    char buffer[256];
    char titre[256];
    char auteur[256];
    Biblio *b = creer_biblio();
    int num;

    int i=0;
    while (i<n && fgets(buffer,256,f))  {
        if (sscanf(buffer, "%d %s %s", &num, titre, auteur) == 3)   {
            inserer_en_tete(b, num, titre, auteur);
        } else {
            printf("Erreur charger_n_entrees : format de ligne incorrect\n");
            fclose(f);
            return NULL;
        }
        i++;
    }
    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio *b, char *nomfic) {
    FILE *f = fopen(nomfic,"w");
    Livre *ptr = b -> L;
    while (ptr) {
        fprintf(f,"%d %s %s\n",ptr->num,ptr->titre,ptr->auteur);
        ptr = ptr->suiv;
    }
}

