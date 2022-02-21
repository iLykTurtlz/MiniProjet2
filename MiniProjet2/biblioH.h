#ifndef BIBLIOH_H
#define BIBLIOH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//#define //A ((sqrt(5)-1)/2.0);    //nb d'or -1



typedef struct livreh {
    int clef;
    int num;
    char *titre;
    char *auteur;
    struct livreh *suiv;
} LivreH;

typedef struct table {
    int nE; /*nombre d'elements contenus dans la table de hachage*/
    int m; /*taille de la table de hachage*/
    LivreH **T;/*table de hachage avec resolution des collisions par chainage*/
} BiblioH;

int fonctionClef(char *auteur);
LivreH *creer_livre(int num, char *titre, char *auteur);
BiblioH *creer_biblio(int m);
void liberer_liste(LivreH *l);
void liberer_biblio(BiblioH *b);
int fonctionHachage(int cle, int m);
void inserer_en_tete(LivreH *liste, LivreH *livre);
void inserer_copie_en_tete(LivreH *liste, int num, char *titre, char *auteur)
void inserer(BiblioH *b, int num, char *titre, char *auteur);

void afficher_livre(LivreH *l);
void afficher_biblio(BiblioH *b);
LivreH *rechercher_livre_num(BiblioH *b, int num);
LivreH *rechercher_livre_titre(BiblioH *b, char *titre);
LivreH *rechercher_livre_auteur(BiblioH *b, char *auteur);
LivreH *recherche_liste_titre_auteur(LivreH *liste, char *titre, char *auteur)
void supprimer_livre(BiblioH *b, int num, char *titre, char *auteur);
void fusionner_biblio(BiblioH *b1, BiblioH *b2);
 LivreH *plusieurs_exemp(BiblioH *b);


#endif
