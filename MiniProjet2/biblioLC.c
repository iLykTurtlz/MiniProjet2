#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre *creer_livre(int num, char *titre, char *auteur)  {
    Livre *l = (Livre *)malloc(sizeof(Livre));
    l -> num = num;
    l -> titre = strdup(titre);
    l -> auteur = strdup(auteur);
    l -> suiv = NULL;
    return l;
}

void liberer_livre(Livre *l)    {
    free(l -> titre);
    free(l -> auteur);
    free(l);
}

Biblio *creer_biblio()  {
    Biblio * b = (Biblio *)malloc(sizeof(Biblio));
    b -> L = NULL;
    return b;
}

void liberer_biblio(Biblio *b)  {
    Livre *cour = b -> L, *prec;
    while (cour) {
        prec = cour;
        cour = cour -> suiv;
        liberer_livre(prec);
    }
    free(b);
}

void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur) {
    Livre *l = creer_livre(num, titre, auteur);
    l -> suiv =  b -> L;
    b -> L = l;
}

void afficher_livre(Livre *l)   {
    if (l == NULL)  {
        printf("Erreur, livre vide\n");
        return;
    }
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio *b) {
    Livre *ptr = b -> L;
    while (ptr) {
        afficher_livre(ptr);
        ptr = ptr->suiv;
    }
}

Livre *rechercher_livre_num(Biblio * b, int num)  {
    Livre *ptr = b -> L;
    while (ptr && (ptr->num != num)) {
        ptr = ptr->suiv;
    }
    return ptr;
}

Livre *rechercher_livre_titre(Biblio * b, char *titre)  {
    Livre *ptr = b -> L;
    while (ptr && (strcmp(titre, ptr->titre))) {
        ptr = ptr->suiv;
    }
    return ptr;
}

Biblio *rechercher_auteur(Biblio *b, char *auteur) {
    Biblio *new=creer_biblio();
    Livre *ptr = b -> L;
    while (ptr) {
        if (!strcmp(auteur, ptr->auteur))   {
            inserer_en_tete(new, ptr->num, ptr->titre, ptr->auteur);
        }
        ptr = ptr->suiv;
    }
    return new;
}

void supprimer_livre(Biblio *b, int num, char *auteur, char *titre) {
    Livre *prec=NULL, *cour = b -> L;
    if (cour && (cour->num == num) && !strcmp(cour->auteur, auteur) && !strcmp(cour->titre, titre)) {
        prec = cour;
        cour = cour->suiv;
        liberer_livre(prec);
        b -> L = cour;
        return;
    }
    while (cour)    {
        prec = cour;
        cour = cour->suiv;
        if (cour && (cour->num == num) && !strcmp(cour->auteur, auteur) && !strcmp(cour->titre, titre)) {
            prec->suiv = cour->suiv;
            liberer_livre(cour);
            return;
        }
    }
    return;
}

void fusionner_biblio(Biblio *b1, Biblio *b2) {
    Livre *ptr = b2 -> L;
    while (ptr) {
        inserer_en_tete(b1, ptr->num, ptr->titre, ptr->auteur);
        ptr = ptr->suiv;
    }
    liberer_biblio(b2);
}

Livre *plusieurs_exemp(Biblio *b)   {
    Biblio *r;
    Livre *p1 = b->L;
    Livre *p2;
    while (p1)  {
        p2 = b->L;
        while (p2 && (strcmp(p1->auteur, p2->auteur) || strcmp(p1->titre, p2->titre)))  {
            p2 = p2->suiv;
        }
        if (p2) {
            inserer_en_tete(r, p1->num, p1->titre, p1->auteur);
        }
        p1 = p1->suiv;
    }
    return r->L;
}





