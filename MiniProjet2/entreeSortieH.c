#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"


BiblioH *charger_n_entrees(char *nomfic, int n, int m) {
    FILE *f = fopen(nomfic, "r");
    char buffer[256];
    char titre[256];
    char auteur[256];
    BiblioH *b = creer_biblio(m);
    int num;

    int i=0;
    while (i<n && fgets(buffer,256,f))  {
        if (sscanf(buffer, "%d %s %s", &num, titre, auteur) == 3)   {
            inserer(b, num, titre, auteur);
        } else {
            printf("Erreur charger_n_entrees : ligne %d format de ligne incorrect\n",i);
            fclose(f);
            return b;
        }
        i++;
    }
    fclose(f);
    return b;
}

void enregistrer_biblio(BiblioH *b, char *nomfic) {
    FILE *f = fopen(nomfic,"w");
    LivreH *l;
    for (int i=0; i<b->m; i++) {
        l = b->T[i];
        while (l)   {
            fprintf(f,"%d %s %s\n",l->num,l->titre,l->auteur);
            l = l->suiv;
        }
    }
}