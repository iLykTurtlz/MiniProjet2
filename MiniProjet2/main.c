#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

void menu() {
    printf("0-sortie du programme\n");
    printf("1-Affichage\n");
    printf("2-Inserer ouvrage\n");
    printf("3-Supprimer ouvrage\n");
    printf("\n");


}


int main(int argc, char **argv)  {
    if (argc != 3)  {
        printf("usage : %s <nom_du_fichier> <nb_de_lignes>",argv[0]);
        exit(1);
    }
    char nomfic[256];
    strcpy(nomfic,argv[1]);
    int nb = atoi(argv[2]);
    printf("%s %d\n",nomfic, nb);
    
    Biblio *b = charger_n_entrees(nomfic, nb);

    int rep;
    int num;
    char titre[256];
    char auteur[256];
    do {
        menu();

        scanf(" %d",&rep);
        switch (rep)    {
            case 1:
                printf("Affichage :\n");
                afficher_biblio(b);
                break;
            case 2:
                printf("Veuillez ecrire le numero, le titre et l'auteur de l'ouvrage.\n");
                
                if (scanf(" %d %s %s",&num,titre,auteur)==3)    {
                    inserer_en_tete(b,num,titre,auteur);
                    printf("Ajout fait.\n");
                } else {
                    printf("Erreur format\n");
                }
                break;
            case 3:
                break;
        }
    } while (rep != 0);
    printf("Merci, et au revoir.\n");
    liberer_biblio(b);
    return 0;

}