#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H

#include "livre.h"

#define CAPACITE_BIBLIO 2 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct {
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque
} T_Bibliotheque;

//PROTOTYPES

void init(T_Bibliotheque *ptrB);

int ajouterLivre(T_Bibliotheque *ptrB);

int  afficherBibliotheque(const T_Bibliotheque *ptrB);

/*******************************************************************************************/
/*Fonction n°3 */
/*Description : */
/*******************************************************************************************/
int rechercherLivre(const T_Bibliotheque *ptrB,const T_Titre title); 

/*******************************************************************************************/
/*Fonction n°4 */
/*Description : */
/*******************************************************************************************/
void rechercheLivreAuteur(const T_Bibliotheque *ptrB ,const T_Aut auteur); 

/*******************************************************************************************/
/*Fonction n°5 */
/*Description : */
/*******************************************************************************************/
int supprimerLivre(T_Bibliotheque *ptrB,const T_Titre title); 

/*******************************************************************************************/
/*Fonction n°6 */
/*Description : */
/*******************************************************************************************/
int emprunterLivre(T_Bibliotheque *ptrB,const T_Titre title,const T_Aut name); 

/*******************************************************************************************/
/*Fonction n°7 */
/*Description : */
/*******************************************************************************************/
int rendreLivre(T_Bibliotheque *ptrB,const T_Titre title,const T_Aut name); 

/*******************************************************************************************/
/*Fonction supplémentaire */
/*Description : */
/*******************************************************************************************/
int estEmprunte(T_Bibliotheque *ptrB,const T_Titre title); //fonction en plus

/*******************************************************************************************/
/*Fonction n°8 */
/*Description : */
/*******************************************************************************************/
void trierLivresParTitre(T_Bibliotheque *ptrB); 

/*******************************************************************************************/
/*Fonction n°9 */
/*Description : */
/*******************************************************************************************/
void trierLivresParAuteur(T_Bibliotheque *ptrB);

/*******************************************************************************************/
/*Fonction n°10 */
/*Description : */
/*******************************************************************************************/
void trierLivresParAnnee(T_Bibliotheque *ptrB); 

#endif