#ifndef BIBLIOLC_H
#define BIBLIOLC_H

typedef struct livre {
    int num;
    char * titre;
    char * auteur;
    struct livre * suiv;
} Livre;

typedef struct {
    Livre *L;
} Biblio;

Livre *creer_livre(int num, char *titre, char *auteur);
void liberer_livre(Livre *l);
Biblio *creer_biblio();
void liberer_biblio(Biblio *b);
void inserer_en_tete(Biblio *b, int num, char *titre, char *auteur);
void afficher_biblio(Biblio *b);
void afficher_livre(Livre *l);
void rechercher_livre_num(Biblio * b, int num);
Livre *rechercher_livre_titre(Biblio * b, char *titre);
Biblio *rechercher_auteur(Biblio *b, char *auteur);
Biblio *rechercher_auteur(Biblio *b, char *auteur);
void supprimer_livre(Biblio *b, int num, char *auteur, char *titre);

#endif