#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"


Biblio *charger_n_entrees(char *nomfic, int n) {
    FILE *f = fopen(nomfic, "r");
    if (f==NULL){
        fprintf(stderr, "Erreur charger_n_entrees : ouverture du fichier\n");
        return NULL;
    }
    
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
            fprintf(stderr, "Erreur charger_n_entrees : ligne %d : format de ligne incorrect\n",i);
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
    if (f==NULL){
        fprintf(stderr, "Erreur charger_n_entrees : ouverture du fichier\n");
        return NULL;
    }
    
    Livre *ptr = b -> L;
    while (ptr) {
        fprintf(f,"%d %s %s\n",ptr->num,ptr->titre,ptr->auteur);
        ptr = ptr->suiv;
    }
}

