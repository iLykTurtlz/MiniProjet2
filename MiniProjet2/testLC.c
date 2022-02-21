//Fichier test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"


int main(int argc, char **argv)  {

/*Tests biblioLC.c*/

//tests : creer_livre + afficher_livre + liberer_livre
printf("\n\ntests : creer_livre + afficher_livre + liberer_livre :\n");

/*test 1*/
printf("\nTest 1 :\n");
printf("On cree, affiche et libere un livre : 0 livre0 livre\n");
Livre *l = creer_livre(0, "livre0", "livre");
if (l==NULL){printf("creer_livre : fail test 1\n");}
else {printf("creer_livre : success test 1\n");}
afficher_livre(l);
liberer_livre(l);

/*test 2*/
printf("\nTest 2 :\n");
printf("On cree, affiche et libere un livre : 0 livre0 0\n");
l = creer_livre(0, "livre0", "0");
if (l==NULL){printf("creer_livre : fail test 2\n");}
else {printf("creer_livre : success test 2\n");}
afficher_livre(l);
liberer_livre(l);


//tests : creer_biblio + afficher_biblio + liberer_biblio
printf("\n\ntests : creer_biblio + afficher_biblio + liberer_biblio :\n");

/*test 3*/
printf("\nTest 3 :\n");
printf("On cree, affiche et libere une bibliotheque vide \n");
Biblio *b = creer_biblio();
if (b==NULL){printf("creer_biblio : fail test 3\n");}
else {printf("creer_biblio : success test 3\n");}
afficher_biblio(b);
liberer_biblio(b);


//tests : inserer_en_tete + supprimer_livre
printf("\n\ntests : inserer_en_tete + supprimer_livre :\n");

/*test 4*/
printf("\nTest 4 :\n");
printf("On cree, affiche, ajoute des livres, supprime des livres et libere une bibliotheque \n");
b = creer_biblio();
if (b==NULL){printf("creer_biblio : fail test 4\n");}
else {printf("creer_biblio : success test 4\n");}
afficher_biblio(b);
printf("On insere : 0 titre0 auteur0\n");
inserer_en_tete(b, 0, "titre0", "auteur0");
afficher_biblio(b);
printf("On insere : 1 titre1 auteur1\n");
inserer_en_tete(b, 1, "titre1", "auteur1");
afficher_biblio(b);
printf("On insere : 2 titre2 auteur2\n");
inserer_en_tete(b, 2, "titre2", "auteur2");
afficher_biblio(b);
printf("On supprime (element du milieu): 1 titre1 auteur1\n");
supprimer_livre(b, 1, "titre1", "auteur1");
afficher_biblio(b);
printf("On supprime (premier element): 2 titre2 auteur2\n");
supprimer_livre(b, 2, "titre2", "auteur2");
afficher_biblio(b);
liberer_biblio(b);


//tests : rechercher_livre_num + rechercher_livre_titre + rechercher_livre_titre_auteur + rechercher_auteur
printf("\n\ntests : rechercher_livre_num + rechercher_livre_titre + rechercher_livre_titre_auteur + rechercher_auteur :\n");

/*test 5*/
printf("\nTest 5 :\n");
printf("On cree, affiche, cherche des livres et libere une bibliotheque \n");
b = creer_biblio();
if (b==NULL){printf("creer_biblio : fail test 5\n");}
else {printf("creer_biblio : success test 5\n");}

printf("\n");

inserer_en_tete(b, 0, "titre0", "auteur0");
inserer_en_tete(b, 1, "titre1", "A1");
inserer_en_tete(b, 2, "titre2", "A1");
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
Biblio *b2 = rechercher_auteur(b, "A1");
afficher_biblio(b2);
printf(" rechercher_auteur (n'existe pas): auteur5 \n");
b2 = rechercher_auteur(b, "auteur5");
afficher_biblio(b2);

printf("\n");

printf("verfication de la bibliotheque initiale : pas de modification ?\n");
afficher_biblio(b);
liberer_biblio(b);
liberer_biblio(b2);


//tests : fusionner_biblio + plusieurs_exemp
printf("\n\ntests : fusionner_biblio + plusieurs_exemp:\n");

/*test 6*/
printf("\nTest 6 :\n");
printf("On cree, affiche fusionne libere deux bibliotheques \n");

printf("creation b1 \n");
b = creer_biblio();
inserer_en_tete(b, 0, "A", "A");
inserer_en_tete(b, 1, "C", "C");
inserer_en_tete(b, 0, "A", "A");
afficher_biblio(b);

printf("\n");
printf("creation b2 \n");
b2 = creer_biblio();
inserer_en_tete(b2, 5, "B", "B");
inserer_en_tete(b2, 1, "C", "C");
inserer_en_tete(b2, 3, "B", "B");
afficher_biblio(b2);

printf("\n");
printf("fusion des bibliotheques \n");
fusionner_biblio(b,b2);
afficher_biblio(b);
liberer_biblio(b2);

/*test 7*/
printf("\nTest 7 :\n");
printf("On cherche les doublons dans la nouvelle bibliotheque \n");

printf("\n");
printf("On affiche la bibliotheque : \n");
afficher_biblio(b);

printf("\n");
printf("On affiche les doublons de la bibliotheque : \n");
b2 = plusieurs_exemp(b) ;
if (b==NULL){printf("plusieurs_exemp : fail test 7\n");}
else {printf("plusieurs_exemp : success test 7\n");
afficher_biblio(b2);
}

liberer_biblio(b);
liberer_biblio(b2);
}
