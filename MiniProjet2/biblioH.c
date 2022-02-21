
#include "biblioH.h"

int fonctionClef(char *auteur)  {
    int sum = 0;
    while (*auteur != '\0')   {
        sum += *auteur;
        auteur++;
    }
    return sum;
}

LivreH *creer_livre(int num, char *titre, char *auteur) {
    LivreH *new = (LivreH *)malloc(sizeof(LivreH));
    new->num = num;
    new->titre = strdup(titre);
    new->auteur = strdup(auteur);
    new->clef = fonctionClef(auteur);
    return new;
}

void liberer_livre(LivreH *l)   {
    free(l->titre);
    free(l->auteur);
    free(l);
}


BiblioH *creer_biblio(int m)    {
    /*m la taille de la table*/
    BiblioH *new = (BiblioH *)malloc(sizeof(BiblioH));
    new->nE = 0;
    new->m = m;
    new->T = (LivreH **)malloc(m*sizeof(LivreH *));
    for(int i=0; i<new->m; i++)  {
        new->T[i] = NULL;
    }
    return new;    
}

void liberer_liste(LivreH *l)   {
    LivreH *tmp;
    while(l)    {
        tmp = l;
        l = l->suiv;
        liberer_livre(tmp);
    }
}

void liberer_biblio(BiblioH *b) {
    for (int i=0; i<b->m; i++)  {
        liberer_liste(b->T[i]);
    }
    free(b->T);
    free(b);
}

int fonctionHachage(int cle, int m) {
    double A = ((sqrt(5)-1)/2.0);
    return (int)(m*(cle*(A)-(int)(cle*A)));
}

void inserer_en_tete(LivreH **liste, LivreH *livre)  {
    livre->suiv = *liste;
    *liste = livre;
}

void inserer_copie_en_tete(LivreH **liste, int num, char *titre, char *auteur)   {
    LivreH *l = creer_livre(num, titre, auteur);
    l -> suiv = *liste;
    *liste = l;
}

void inserer(BiblioH *b, int num, char *titre, char *auteur)    {
    LivreH *l = creer_livre(num,titre,auteur);
    int position = fonctionHachage(l->clef,b->m);
    inserer_en_tete(&b->T[position], l); 
}

void afficher_livre(LivreH *l)  {
    if (l == NULL)  {
        fprintf(stderr, "Erreur afficher_livre : livre vide\n");
    }
    printf("%d %s %s\n", l->num, l->titre, l->auteur);
}

void afficher_liste (LivreH *l)  {
    if (l == NULL)  {
        fprintf(stderr, "Erreur afficher_livre : liste vide\n");
    }
    while (l)   {
        afficher_livre(l);
        l = l->suiv;
    }
}

void afficher_biblio(BiblioH *b)    {
    int i;
    LivreH *l=NULL;
    for (i=0; i<b->m; i++)  {
        l = b->T[i];
        while(l)    {
            afficher_livre(l);
            l = l->suiv;
        }
    }

}

LivreH *rechercher_livre_num(BiblioH *b, int num)   {
    int i;
    LivreH *l=NULL;
    for (i=0; i<b->m; i++)  {
        l = b->T[i];
        while(l)    {
            if (l->num == num)
                return l;
            l = l->suiv;
        }
    }
    return l;
}

LivreH *rechercher_livre_titre(BiblioH *b, char *titre)   {
    int i;
    LivreH *l=NULL;
    for (i=0; i<b->m; i++)  {
        l = b->T[i];
        while(l)    {
            if (!strcmp(l->titre,titre))
                return l;
            l = l->suiv;
        }
    }
    return l;
}

LivreH *rechercher_auteur(BiblioH *b, char *auteur)   {
    int position = fonctionHachage(fonctionClef(auteur),b->m);
    LivreH *res = NULL;
    LivreH *l = b->T[position];
    while (l)   {
        if (!strcmp(l->auteur,auteur))  {
            inserer_en_tete(&res,l);
        }
        l = l->suiv;
    }
    return res;
}

LivreH *rechercher_liste_titre_auteur(LivreH *liste, char *titre, char *auteur) {
    LivreH *ptr  = liste;
    while (ptr && ((strcmp(titre, ptr->titre)) || (strcmp(auteur, ptr->auteur)))) {
        ptr = ptr->suiv;
    }
    return ptr;
}

void supprimer_livre(BiblioH *b, int num, char *titre, char *auteur)    {
    int position = fonctionHachage(fonctionClef(auteur),b->m);
    LivreH *curr = b->T[position]; /*on se place dans la liste des livres ayant la même clé, cad, potentiellement les même auteur*/
    LivreH *prev = NULL;
    
    /*cas où le premier livre correspond à celui demandé*/
    if (curr && (curr->num == num) && !strcmp(curr->auteur, auteur) && !strcmp(curr->titre, titre)) {
        prev = curr;
        curr = curr->suiv;
        liberer_livre(prev);
        printf("Suppression effectuée\n");
        b->T[position] = curr;
        return;
    }

    /*sinon on parcourt la bibliothèque tant que le livre actuel ne correspond pas à celui demandé et on le supprime s'il correspond*/
    while (curr)   {
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

void fusionner_biblio(BiblioH *b1, BiblioH *b2)   {
    /*on parcourt la bibliothèque 2 pour ajouter ses livres à la bibliothèque 1 avant de la libérer*/
    LivreH *ptr = NULL;

    for (int i=0; i<b2->m; i++) {
        ptr = b2->T[i];
        while(ptr)  {
            inserer(b1, ptr->num, ptr->titre, ptr->auteur);
            ptr = ptr->suiv;
        }
    }
    liberer_biblio(b2);
}

 LivreH *plusieurs_exemp(BiblioH *b)   {
    /*on parcourt les liste de la bibliothèque à la recherche de doublons qu'on ajoute, s'il existe, à la liste à renvoyer*/
    LivreH *doublons=NULL;
    LivreH *p1;
    LivreH *p2;
    int deja;

    for (int i=0; i<b->m; i++)  {
        p1 = b->T[i];
        while (p1)  {
            deja=0;
            p2 = p1->suiv; /*on part du prochain livre de la bibliothèque car ceux avant on déjà été traités*/
            
            /*si ce livre n'appartient pas à la liste, alors on doit cherché s'il a des doublons, sinon on passe directement au livre suivant*/
            if (rechercher_liste_titre_auteur(doublons,p1->titre,p1->auteur) == NULL)   {
                while (p2)  {
                    if (!strcmp(p1->titre, p2->titre) && !strcmp(p1->auteur, p2->auteur))   {
                        /*si deja est fausse, c'est le premier doublon trouvé donc on ajoute le doublon et le livre de référence, sinon juste le doublon*/
                        if (!deja)  {
                            inserer_copie_en_tete(&doublons, p1->num, p1->titre, p1->auteur);
                            deja = 1;
                        }
                        inserer_copie_en_tete(&doublons, p2->num, p2->titre, p2->auteur);
                    }
                    p2 = p2->suiv; 
                }
            } 
            p1 = p1->suiv;
        }
    }
    return doublons;
}


