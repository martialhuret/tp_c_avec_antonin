#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), K_MaxAut);
lireChaine("EDITEUR :", (ptrL->editeur ), K_MaxEdit);
printf("ANNEE :");
scanf("%d",&(ptrL->annee));
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("EDITEUR :", (ptrL->editeur ));
printf(" - ");
printf("ANNEE : %d", (ptrL->annee ));
printf(" - ");
afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur ));
printf("\n");
}

