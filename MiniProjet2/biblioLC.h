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
void afficher_livre(Livre *l);
void afficher_biblio(Biblio *b);
Livre *rechercher_livre_num(Biblio * b, int num);
Livre *rechercher_livre_titre(Biblio * b, char *titre);
Livre *rechercher_livre_titre_auteur(Biblio * b, char *titre, char *auteur);
Biblio *rechercher_auteur(Biblio *b, char *auteur);
void supprimer_livre(Biblio *b, int num, char *titre, char *auteur);
void fusionner_biblio(Biblio *b1, Biblio *b2);
Livre *plusieurs_exemp(Biblio *b) ; /*je crois qu'elle ne fonctionne pas comme on voudrait... à revoir !*/

#endif
