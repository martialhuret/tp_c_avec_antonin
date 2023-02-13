# include "biblio.h"


void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}

return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i]));
			
			}


		
		return 1;
		}
}

int rechercherLivre(const T_Bibliotheque  *ptrB, const T_Titre title)
{
int i;
if(ptrB->nbLivres==0)
	return -1;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			if (strcmp(title,((ptrB->etagere)[i].titre))==0) return i;
			}
		}
return -1;
}



void rechercheLivreAuteur(const T_Bibliotheque *ptrB , const T_Aut auteur)
{
	//init var
	int i, cpt = 0;
	

	//si la bibliothèque est nulle, on sort directement de la fonction
	if((ptrB->nbLivres)==0)return -1;

	
	//on recherche tout les livres de l'auteur 
	for(i=0; i<ptrB->nbLivres; i = i + 1)
	{

		//condition qui va verifier l'auteur d'un livre
		if(strcmp(auteur,((ptrB->etagere)[i].auteur)) == 0)
		{
			cpt = cpt + 1;
			printf("\n %s" ,(ptrB->etagere)[i].titre);	// on renvoie le titre de l'auteur
			printf("\n %s" ,(ptrB->etagere)[i].code);	// on renvoie le titre de le code
			printf("\n %s" ,(ptrB->etagere)[i].editeur);// on renvoie le titre de l'editeur
			printf("\n %d" ,(ptrB->etagere)[i].annee);// on renvoie le titre de l'annee
		}
	}
	return 0;
}


int supprimerLivre (T_Bibliotheque *ptrB, const T_Titre *title){
    int test = rechercherLivre(ptrB, title);
    if (test == -1) return 0;
    else {
        strcpy(ptrB->etagere[test].titre,ptrB->etagere[(ptrB->nbLivres)-1].titre);
        ptrB->nbLivres--; 
    }
return 1;
}

int estEmprunte(T_Bibliotheque *ptrB, const T_Titre *title){
	int pos = rechercherLivre(ptrB, title);
	if (((ptrB->etagere)[pos].emprunteur)[0]=='\0') return -1;
	return pos;
}

int emprunterLivre (T_Bibliotheque *ptrB, const T_Titre *title, const T_Aut name){
	int pos = estEmprunte(ptrB,title);
    if (pos!=-1) strcpy((ptrB->etagere)[pos].emprunteur,name);
	
return 1;
}

int rendreLivre (T_Bibliotheque *ptrB, const T_Titre *title, const T_Aut name)
{	
	int pos = estEmprunte(ptrB,title);
	//verification que le livre est emprunté 
	if(pos== -1) ((ptrB->etagere)[pos].emprunteur[0])='\0';
return 0; 

}



void trierLivresParTitre(T_Bibliotheque *ptrB) {
  for (int i = 0; i < ptrB->nbLivres - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < ptrB->nbLivres; j++) {
      if (strcmp(ptrB->etagere[j].titre, ptrB->etagere[minIndex].titre) < 0) {
        minIndex = j;
      }
    }
    T_livre temp = ptrB->etagere[minIndex];
    ptrB->etagere[minIndex] = ptrB->etagere[i];
    ptrB->etagere[i] = temp;
  }
}

void trierLivresParAuteur(T_Bibliotheque *ptrB) {
  for (int i = 0; i < ptrB->nbLivres - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < ptrB->nbLivres; j++) {
      if (strcmp(ptrB->etagere[j].auteur, ptrB->etagere[minIndex].auteur) < 0) {
        minIndex = j;
      }
    }
    T_livre temp = ptrB->etagere[minIndex];
    ptrB->etagere[minIndex] = ptrB->etagere[i];
    ptrB->etagere[i] = temp;
  }
}

void trierLivresParAnnee(T_Bibliotheque *ptrB) {
  for (int i = 0; i < ptrB->nbLivres - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < ptrB->nbLivres; j++) {
      if (ptrB->etagere[j].annee < ptrB->etagere[minIndex].annee) {
        minIndex = j;
      }
    }
    T_livre temp = ptrB->etagere[minIndex];
    ptrB->etagere[minIndex] = ptrB->etagere[i];
    ptrB->etagere[i] = temp;
  }
}