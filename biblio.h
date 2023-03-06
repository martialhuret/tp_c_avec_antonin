#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H

#include "livre.h" // inclusion des biblios

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct {
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque
} T_Bibliotheque;

//PROTOTYPES

void init(T_Bibliotheque *ptrB);


/*******************************************************************************************/
/*Fonction n°1 */
/*Description :Permet d'ajouter un livre dans notre bibliotheque */
/*******************************************************************************************/
int ajouterLivre(T_Bibliotheque *ptrB);


/*******************************************************************************************/
/*Fonction n°2 */
/*Description : Permet d'afficher la bibliothèque actuelle */
/*******************************************************************************************/
int afficherBibliotheque(const T_Bibliotheque *ptrB);

/*******************************************************************************************/
/*Fonction n°3 */
/*Description : Permet de rechercher un livre en fonction de son titre */
/*******************************************************************************************/
int * rechercherLivre(const T_Bibliotheque *ptrB,const T_Titre title); 

/*******************************************************************************************/
/*Fonction n°4 */
/*Description :Permet de rechercher un livre en fonction de son auteur */
/*******************************************************************************************/
void rechercheLivreAuteur(const T_Bibliotheque *ptrB ,const T_Aut auteur); 

/*******************************************************************************************/
/*Fonction n°5 */
/*Description :Permet de supprimer un livre en fonction de son titre*/
/*******************************************************************************************/
int supprimerLivre(T_Bibliotheque *ptrB,const T_Titre title); 

/*******************************************************************************************/
/*Fonction n°6 */
/*Description Permet d'emprunter un livre en fonction de son titre et de son nom d'auteur */
/*******************************************************************************************/
int emprunterLivre(T_Bibliotheque *ptrB,const T_Titre title,const T_Aut name); 

/*******************************************************************************************/
/*Fonction n°7 */
/*Description :Permet de rendre un livre en fonction de son titre et de son nom d'auteur */
/*******************************************************************************************/
int rendreLivre(T_Bibliotheque *ptrB,const T_Titre title,const T_Aut name); 

/*******************************************************************************************/
/*Fonction n°8 */
/*Description :Permet de trier les livres en fonction de leurs titre */
/*******************************************************************************************/
void trierLivresParTitre(T_Bibliotheque *ptrB); 

/*******************************************************************************************/
/*Fonction n°9 */
/*Description :Permet de trier les livres en fonction de leurs auteur */
/*******************************************************************************************/
void trierLivresParAuteur(T_Bibliotheque *ptrB);

/*******************************************************************************************/
/*Fonction n°10 */
/*Description :Permet de trier les livres en fonction de leurs Annees*/
/*******************************************************************************************/
void trierLivresParAnnee(T_Bibliotheque *ptrB); 

/*******************************************************************************************/
/*Fonction n°11 */
/*Description :Permet d'afficher tout les livres dispo*/
/*******************************************************************************************/
int  afficherLivreDispo(const T_Bibliotheque *ptrB);

/*******************************************************************************************/
/*Fonction n°12 */
/*Description :Permet d'afficher tout les livres en retard*/
/*******************************************************************************************/
void  afficherLivreRetard(const T_Bibliotheque *ptrB);
#endif