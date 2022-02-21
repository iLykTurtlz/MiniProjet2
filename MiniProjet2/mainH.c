#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"

void menu() {
    printf("0-sortie du programme\n");
    printf("1-Afficher la bibliothèque\n");
    printf("2-Inserer un ouvrage\n");
    printf("3-Supprimer un ouvrage\n");
    printf("4-Rechercher un ouvrage par son numéro d’enregistrement\n");
    printf("5-Rechercher un ouvrage par son titre\n");
    printf("6-Rechercher les ouvrages d'un auteur\n");
    printf("\n"); 


}


int main(int argc, char **argv)  {
    if (argc != 4)  {
        printf("usage : %s <nom_du_fichier> <nb_de_lignes> <taille_table_hachage>\n",argv[0]);
        exit(1);
    }
    /*on récupère les arguments*/
    char nomfic[256];
    strcpy(nomfic,argv[1]);
    int nb = atoi(argv[2]);
    int taille_table = atoi(argv[3]);
    
    BiblioH *b = charger_n_entrees(nomfic, nb, taille_table);
    /*il faudrait gérer les cas où on n'a pas pu chargé le fichier ! (mais c'est pas b==NULL je crois car on peut vouloir chargé 0 lignes...*/
    
    /*Gestion des requêtes de l'utilisateur*/
    LivreH *livre;
    //BiblioH *resB;
    int rep;
    int num;
    char buffer[256];
    char titre[256];
    char auteur[256];
    
    do {
        menu();
        
        fgets(buffer,256,stdin);
        if (sscanf(buffer, " %d", &rep) != 1)   {
            fprintf(stderr, "Erreur format de réponse : Veuillez saisir le numéro d'une des options proposées.\n");
            continue; 
        }     
        switch (rep)    {
            case 1: /*Affichage*/
                printf("Affichage de la bibliothèque :\n");
                afficher_biblio(b);
                break;
            case 2:/*Insertion*/
                printf("Veuillez ecrire le numero, le titre et l'auteur de l'ouvrage à insérer.\n");
                fgets(buffer,256,stdin);
                if (sscanf(buffer," %d %s %s",&num,titre,auteur)==3)    {
                    inserer(b,num,titre,auteur);
                    printf("Ajout effectué.\n");
                } else {
                    printf("Erreur de format : ajout impossible\n");
                }
                break;
            case 3: /*Supression*/
                printf("Veuillez ecrire le numero, le titre et l'auteur de l'ouvrage à supprimer.\n");
                fgets(buffer,256,stdin);
                if (sscanf(buffer," %d %s %s",&num,titre,auteur)==3)    {
                   supprimer_livre(b,num,titre,auteur);
                } else {
                    printf("Erreur de format : suppression impossible\n");
                }
                break;
            case 4: /*Rechercher numéro */
                printf("Veuillez ecrire le numero du livre recherché.\n");
                fgets(buffer,256,stdin);
                if (sscanf(buffer," %d",&num)==1)   {
                    livre = rechercher_livre_num(b,num);
                    printf("Recherche effectuée. Résultat : \n");
                    afficher_livre(livre);                    
                } else {
                    printf("Erreur de format : recherche impossible\n");
                }
                break;
            case 5: /*Rechercher titre */
                printf("Veuillez ecrire le titre du livre recherché.\n");
                fgets(buffer,256,stdin);
                if (sscanf(buffer," %s",titre)==1)   {
                    livre = rechercher_livre_titre(b,titre);
                    printf("Recherche effectuée. Résultat : \n");
                    afficher_livre(livre);                    
                } else {
                    printf("Erreur de format : recherche impossible\n");
                }
                break;
            case 6: /*Rechercher auteur */
                printf("Veuillez ecrire l'auteur recherché.\n");
                fgets(buffer,256,stdin);
                if (sscanf(buffer," %s",auteur)==1)   {
                    livre = rechercher_auteur(b,auteur);
                    printf("Recherche effectuée. Résultat : \n");
                    afficher_liste  (livre);                    
                } else {
                    printf("Erreur de format : recherche impossible\n");
                }
                break;        
        }
    } while (rep != 0);
    
    printf("Merci, et au revoir.\n");
    liberer_biblio(b);
    return 0;
}
