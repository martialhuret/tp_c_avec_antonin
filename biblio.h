#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H

#include "livre.h"

#define CAPACITE_BIBLIO 2 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct {
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque
} T_Bibliotheque;

//prototypes
void init(T_Bibliotheque *ptrB);

int ajouterLivre(T_Bibliotheque *ptrB);

int  afficherBibliotheque(const T_Bibliotheque *ptrB);

int rechercherLivre(const T_Bibliotheque *ptrB,const T_Titre title); //fonction 3

void rechercheLivreAuteur(const T_Bibliotheque *ptrB ,const T_Aut auteur); //fonction 4

int supprimerLivre(T_Bibliotheque *ptrB,const T_Titre title);  //fonction 5

int emprunterLivre(T_Bibliotheque *ptrB,const T_Titre title,const T_Aut name); //fonction 6

int rendreLivre(T_Bibliotheque *ptrB,const T_Titre title,const T_Aut name); //fonction 7

int estEmprunte(T_Bibliotheque *ptrB,const T_Titre title); //fonction en plus

void trierLivresParTitre(T_Bibliotheque *ptrB); //fonction 8

void trierLivresParAuteur(T_Bibliotheque *ptrB); //fonction 9

void trierLivresParAnnee(T_Bibliotheque *ptrB); //fonction 10

#endif