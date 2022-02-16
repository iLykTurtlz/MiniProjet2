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
    /*on parcourt la bibliothèque et on libère les livres un à un*/    
    Livre *curr = b -> L, *prev;
    while (curr) { 
        prev = curr;
        curr = curr -> suiv;
        liberer_livre(prev);
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
        fprintf(stderr, "Erreur afficher_livre : livre vide\n");
        return;
    }
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void afficher_biblio(Biblio *b) {
    /*on parcourt la bibliothèque et on affiche les livres un à un*/    
    Livre *ptr = b -> L;
    while (ptr) {
        afficher_livre(ptr);
        ptr = ptr->suiv;
    }
}

Livre *rechercher_livre_num(Biblio * b, int num)  {
    /*on parcourt la bibliothèque tant que le numéro du livre actuel ne correspond pas à celui demandé*/  
    Livre *ptr = b -> L;
    while (ptr && (ptr->num != num)) {
        ptr = ptr->suiv;
    }
    return ptr;  /*retourne le livre correspondant à la demande s'il existe ou null sinon*/
}

Livre *rechercher_livre_titre(Biblio * b, char *titre)  {
    /*on parcourt la bibliothèque tant que le titre du livre actuel ne correspond pas à celui demandé*/
    Livre *ptr = b -> L;
    while (ptr && (strcmp(titre, ptr->titre))) {
        ptr = ptr->suiv;
    }
    return ptr;  /*retourne le livre correspondant à la demande s'il existe ou null sinon*/
}

Biblio *rechercher_auteur(Biblio *b, char *auteur) {
    /*on parcourt la bibliothèque, dès que l'auteur du livre correspond à la demande on l'ajoute dans la nouvelle bibliothèque créée*/ 
    Biblio *new_biblio = creer_biblio();
    Livre *ptr = b -> L;
    while (ptr) {
        if (!strcmp(auteur, ptr->auteur))   {
            inserer_en_tete(new_biblio, ptr->num, ptr->titre, ptr->auteur);
        }
        ptr = ptr->suiv; 
    }
    return new_biblio;  /*retourne la bibliothèque des livres correspondant à la demande s'il en existe ou null sinon*/
}

void supprimer_livre(Biblio *b, int num, char *titre, char *auteur) {
    Livre *prev=NULL, *curr = b -> L;
    
    /*cas où le premier livre correspond à celui demandé*/
    if (curr && (curr->num == num) && !strcmp(curr->auteur, auteur) && !strcmp(curr->titre, titre)) {
        prev = curr;
        curr = curr->suiv;
        liberer_livre(prev);
        b -> L = curr;
        printf("Suppression effectuée\n");
        return;
    }
    
    /*sinon on parcourt la bibliothèque tant que le livre actuel ne correspond pas à celui demandé et on le supprime s'il correspond*/
    while (curr)    {
        prev = curr;
        curr = curr->suiv;
        if (curr && (curr->num == num) && !strcmp(curr->auteur, auteur) && !strcmp(curr->titre, titre)) {
            prev->suiv = curr->suiv;
            liberer_livre(curr);
            printf("Suppression effectuée\n");
            return;
        }
    }
    printf("Livre introuvable : Suppression non effectuée\n");
    return;
}

void fusionner_biblio(Biblio *b1, Biblio *b2) {
    /*on parcourt la bibliothèque 2 pour ajouter ses livres à la bibliothèque 1 avant de la libérer*/
    Livre *ptr = b2 -> L;
    while (ptr) {
        inserer_en_tete(b1, ptr->num, ptr->titre, ptr->auteur);
        ptr = ptr->suiv;
    }
    liberer_biblio(b2);
}

Livre *plusieurs_exemp(Biblio *b)   {
    /*pour chaque livre, on parcourt la bibliothèque à  la recherche de doublons qu'on ajoute, s'il existe, à la liste à renvoyer*/
    Biblio *doublons;
    Livre *p1 = b->L;
    Livre *p2;
    while (p1)  {
        p2 = b->L; /*on revient au début de la bibliothèque pour chaque livre*/
        while (p2 && (strcmp(p1->auteur, p2->auteur) || strcmp(p1->titre, p2->titre)))  { /*PROBLEME : TOUJOURS VERIFIE POUR LUI MEME !!!*/
            p2 = p2->suiv; 
        }
        if (p2) {
            inserer_en_tete(doublons, p1->num, p1->titre, p1->auteur);
        }
        p1 = p1->suiv;
    }
    return doublons->L;
}





