//Fichier test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"


int main(int argc, char **argv)  {

/*Tests biblioH.c*/

//tests : fonctionClef
printf("\n\ntests : fonctionClef :\n");

/*test 0*/
printf("\nTest 0 :\n");
printf("On verifie la clef recu : pour AB elle devrait renvoyer 131\n");
printf("fonctionClef('AB') renvoie %d\n", fonctionClef("AB"));
printf("On verifie la clef recu : pour Paul elle devrait renvoyer 402\n");
printf("fonctionClef('Paul') renvoie %d\n", fonctionClef("Paul"));


//tests : creer_livre + afficher_livre + liberer_livre
printf("\n\ntests : creer_livre + afficher_livre + liberer_livre :\n");

/*test 1*/
printf("\nTest 1 :\n");
printf("On cree, affiche et libere un livre : 0 livre0 livre\n");
LivreH *l = creer_livre(0, "titre", "auteur");
if (l==NULL){printf("creer_livre : fail test 1\n");}
else {printf("creer_livre : success test 1\n");}
afficher_livre(l);
liberer_livre(l);

/*test 2*/
printf("\nTest 2 :\n");
printf("On cree, affiche et libere un livre : 5 titre5 5\n");
l = creer_livre(5, "titre5", "5");
if (l==NULL){printf("creer_livre : fail test 2\n");}
else {printf("creer_livre : success test 2\n");}
afficher_livre(l);
liberer_livre(l);

//tests : creer_biblio + afficher_biblio + liberer_biblio
printf("\n\ntests : creer_biblio + afficher_biblio + liberer_biblio :\n");

/*test 3*/
printf("\nTest 3 :\n");
printf("On cree, affiche et libere une bibliotheque vide \n");
BiblioH *b = creer_biblio(20);
if (b==NULL){printf("creer_biblio : fail test 3\n");}
else {printf("creer_biblio : success test 3\n");}
afficher_biblio(b);
liberer_biblio(b);


//tests : inserer_en_tete + supprimer_livre
printf("\n\ntests : inserer_en_tete + supprimer_livre :\n");

/*test 4*/
printf("\nTest 4 :\n");
printf("On cree, affiche, ajoute des livres, supprime des livres et libere une bibliotheque \n");
b = creer_biblio(20);
if (b==NULL){printf("creer_biblio : fail test 4\n");}
else {printf("creer_biblio : success test 4\n");}
afficher_biblio(b);

printf("On insere : 0 titre0 auteur0\n");
inserer(b, 0, "titre0", "auteur0");
afficher_biblio(b);

printf("On insere : 1 titre1 auteur1\n");
inserer(b, 1, "titre1", "auteur1");
afficher_biblio(b);

printf("On insere : 2 titre2 auteur2\n");
inserer(b, 2, "titre2", "auteur2");
afficher_biblio(b);

printf("On supprime : 1 titre1 auteur1\n");
supprimer_livre(b, 1, "titre1", "auteur1");
afficher_biblio(b);

printf("On supprime : 2 titre2 auteur2\n");
supprimer_livre(b, 2, "titre2", "auteur2");
afficher_biblio(b);

liberer_biblio(b);


//tests : rechercher_livre_num + rechercher_livre_titre + rechercher_livre_titre_auteur + rechercher_auteur 
printf("\n\ntests : rechercher_livre_num + rechercher_livre_titre + rechercher_livre_titre_auteur + rechercher_auteur :\n");

/*test 5*/
printf("\nTest 5 :\n");
printf("On cree, affiche, cherche des livres et libere une bibliotheque \n");
b = creer_biblio(20);
if (b==NULL){printf("creer_biblio : fail test 5\n");}
else {printf("creer_biblio : success test 5\n");}

printf("\n");

inserer(b, 0, "titre0", "A0");
inserer(b, 1, "titre1", "A1");
inserer(b, 2, "titre2", "A1");
afficher_biblio(b);

printf("\n");

printf(" rechercher_livre_num (existe): 0 \n");
l = rechercher_livre_num(b, 0);
afficher_livre(l);
printf(" rechercher_livre_num (n'existe pas): 5 \n");
l = rechercher_livre_num(b, 5);
afficher_livre(l);

printf("\n");

printf(" rechercher_livre_titre (existe): titre0 \n");
l = rechercher_livre_titre(b, "titre0");
afficher_livre(l);
printf(" rechercher_livre_titre (n'existe pas): titre5 \n");
l = rechercher_livre_titre(b, "titre5");
afficher_livre(l);

printf("\n");

printf(" rechercher_auteur (existe): A1 \n");
l = rechercher_auteur(b, "A1");
afficher_liste(l);
printf(" rechercher_auteur (n'existe pas): auteur5 \n");
l = rechercher_auteur(b, "auteur5");
afficher_liste(l);

printf("\n");

printf("verfication de la bibliotheque initiale : pas de modification ?\n");
afficher_biblio(b);
liberer_biblio(b);
}

/*

void liberer_liste(LivreH *l);
int fonctionHachage(int cle, int m);
void inserer_en_tete(LivreH **liste, LivreH *livre);
void inserer_copie_en_tete(LivreH **liste, int num, char *titre, char *auteur);



void afficher_liste (LivreH *l);
LivreH *rechercher_liste_titre_auteur(LivreH *liste, char *titre, char *auteur);


void fusionner_biblio(BiblioH *b1, BiblioH *b2);
 LivreH *plusieurs_exemp(BiblioH *b);
 */