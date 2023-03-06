# include "biblio.h"

//////////////////////////////////////////////////////////
void init(T_Bibliotheque *ptrB){
	ptrB->nbLivres=0;
	// ou (*ptrB).nbLivres=0;
}


//////////////////////////////////////////////////////////
int ajouterLivre(T_Bibliotheque *ptrB){
	if (ptrB->nbLivres<CAPACITE_BIBLIO){// reste t il de la place?
		saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
		ptrB->nbLivres++;
		return 1;
	}
	return 0;
}


//////////////////////////////////////////////////////////
int  afficherBibliotheque(const T_Bibliotheque *ptrB){
	int i;
	if(ptrB->nbLivres==0)
		return 0;
	else {
		for(i=0;i<ptrB->nbLivres;i++){
			afficherLivre( &(ptrB->etagere[i]));
			}
	return 1;
	}
}


//////////////////////////////////////////////////////////
int * rechercherLivre(const T_Bibliotheque *ptrB, const T_Titre title) {
    int i, derpos = -1, occu = 0;
    int *retour = NULL;
    if (ptrB->nbLivres == 0) {
        return NULL;
    } else {
        for (i = 0; i < ptrB->nbLivres; i++) {
            if (strncmp(title,(ptrB->etagere)[i].titre,MAX_TITRE) == 0) {
                derpos = i;
                occu++;
            }
        }
        retour = malloc(2 * sizeof(int));
        retour[0] = derpos;
        retour[1] = occu;
        return retour;
    }
}


//////////////////////////////////////////////////////////
void rechercheLivreAuteur(const T_Bibliotheque *ptrB ,const T_Aut auteur){
	//init var
	int i, cpt = 0;	

	//si la bibliothèque est nulle, on sort directement de la fonction
	if((ptrB->nbLivres)==0)return -1;
	
	//on recherche tout les livres de l'auteur 
	for(i=0; i<ptrB->nbLivres; i = i + 1){
		//condition qui va verifier l'auteur d'un livre
		if(strcmp(auteur,((ptrB->etagere)[i].auteur)) == 0){
			cpt = cpt + 1;
			printf("\n %s" ,(ptrB->etagere)[i].titre);	// on renvoie le titre de l'auteur
			printf("\n %s" ,(ptrB->etagere)[i].code);	// on renvoie le titre de le code
			printf("\n %s" ,(ptrB->etagere)[i].editeur);// on renvoie le titre de l'editeur
			printf("\n %d" ,(ptrB->etagere)[i].annee);  // on renvoie le titre de l'annee
		}
	}
	return 0;
}


//////////////////////////////////////////////////////////
int supprimerLivre(T_Bibliotheque *ptrB, const T_Titre title){
    int test = rechercherLivre(ptrB, title)[0];
    if (test == -1) return 0;
    else {
        strcpy(ptrB->etagere[test].titre,ptrB->etagere[(ptrB->nbLivres)-1].titre);
        ptrB->nbLivres--; 
    }
	return 1;
}

//////////////////////////////////////////////////////////
int emprunterLivre(T_Bibliotheque *ptrB, const T_Titre title, const T_Aut name) {
    int *positions = rechercherLivre(ptrB, title);
    if (positions == NULL) {
        return -1; // le livre n'existe pas dans la bibliothèque
    }
    int i;
    for (i = 0; i < positions[1]; i++) {
        int pos = positions[0] - i;
        if (strlen(((ptrB->etagere)[pos].emprunteur.nomemprunteur)) == 0) {
            strcpy((ptrB->etagere)[pos].emprunteur.nomemprunteur, name);
            free(positions);
			lireDateSysteme(&(ptrB->etagere)[pos].emprunteur);
            return 1;
        } else if (strcmp((ptrB->etagere)[pos].emprunteur.nomemprunteur, name) == 0) {
            free(positions);
            return 0; // l'emprunteur a déjà emprunté ce livre
        }
    }
    free(positions);
    return -1; // tous les exemplaires du livre sont déjà empruntés
}



//////////////////////////////////////////////////////////
int rendreLivre(T_Bibliotheque *ptrB, const T_Titre title, const T_Aut name) {
    int *positions = rechercherLivre(ptrB, title);
    if (positions == NULL) {
        return 0; // le livre n'existe pas dans la bibliothèque
    }
    int i;
    for (i = 0; i < positions[1]; i++) {
        int pos = positions[0] - i;
        if (strcmp((ptrB->etagere)[pos].emprunteur.nomemprunteur, name) == 0) {
            strcpy((ptrB->etagere)[pos].emprunteur.nomemprunteur, "");
            free(positions);
            return 1;
        }
    }
    free(positions);
    return 2; // le livre est emprunté par une autre personne ou tous les exemplaires sont déjà rendus
}


//////////////////////////////////////////////////////////
void trierLivresParTitre(T_Bibliotheque *ptrB){
	for (int i = 0; i < ptrB->nbLivres - 1; i++){
		int minIndex = i;
		for (int j = i + 1; j < ptrB->nbLivres; j++){
			if (strcmp(ptrB->etagere[j].titre, ptrB->etagere[minIndex].titre) < 0){
				minIndex = j;
			}
		}
		T_livre temp = ptrB->etagere[minIndex];
		ptrB->etagere[minIndex] = ptrB->etagere[i];
		ptrB->etagere[i] = temp;
	}
}


//////////////////////////////////////////////////////////
void trierLivresParAuteur(T_Bibliotheque *ptrB){
	for (int i = 0; i < ptrB->nbLivres - 1; i++){
		int minIndex = i;
		for (int j = i + 1; j < ptrB->nbLivres; j++){
			if (strcmp(ptrB->etagere[j].auteur, ptrB->etagere[minIndex].auteur) < 0){
				minIndex = j;
			}
		}
		T_livre temp = ptrB->etagere[minIndex];
		ptrB->etagere[minIndex] = ptrB->etagere[i];
		ptrB->etagere[i] = temp;
	}
}


//////////////////////////////////////////////////////////
void trierLivresParAnnee(T_Bibliotheque *ptrB){
	for (int i = 0; i < ptrB->nbLivres - 1; i++){
		int minIndex = i;
		for (int j = i + 1; j < ptrB->nbLivres; j++){
			if (ptrB->etagere[j].annee < ptrB->etagere[minIndex].annee){
				minIndex = j;
			}
		}
		T_livre temp = ptrB->etagere[minIndex];
		ptrB->etagere[minIndex] = ptrB->etagere[i];
		ptrB->etagere[i] = temp;
	}
}

//////////////////////////////////////////////////////////

int afficherLivreDispo(const T_Bibliotheque *ptrB)
{
	//init var
	int i;
	int cpt = 0;

	//si le nombre de livre est nul on renvoie 0, car rien a afficher
	if(ptrB->nbLivres==0)
		return 0;

	//sinon on lance la boucle de recherche
	else {
		for(i=0;i<ptrB->nbLivres;i++)
		{
			//si le livre n'est pas emprunté, on l'affiche 
			if(strlen(((ptrB->etagere)[i].emprunteur.nomemprunteur)) == 0)
			{
			    afficherLivre( &(ptrB->etagere[i]));
				cpt++;
			}	
		}
	//cas ou aucun livre n'a été affiché 
	if (cpt == 0) printf("Aucun livre disponible!");
	}
}


void  afficherLivreRetard(const T_Bibliotheque *ptrB){
	//init var
	int i;
	char j[9],m[10],h[9],mer[11],vir[2];
    int JourJ,a,cmp=0;

    system("date > Ddate"	);
    FILE * fic=NULL;  // pointeur de fichier
    fic=fopen("Ddate","r"); //fileOpen en mode 'r'EAD

    //ici , si fic vaut NULL, alors le fopen a indiquÃ©
    //que le fichier Ddate n'est pas accessible
    if (fic!=NULL){
        while(!feof(fic)){
            //fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);
            fscanf(fic,"%s %d %s %d %s",j,&JourJ,m,&a,h);	
        }
        fclose(fic);
	int nbjour=30;
	int B_JourJ=JourJ;
	if ((strcmp(m,"janvier")==0) || (strcmp(m,"mars")==0) || (strcmp(m,"mai")==0) || (strcmp(m,"juillet")==0) || (strcmp(m,"aout")==0) || (strcmp(m,"octobre")==0) || (strcmp(m,"decembre")==0)) nbjour=31;

	if (strcmp(m,"fevrier")==0){
		if (((a-2020)%4)==0) nbjour = 29;
		else nbjour = 28;
	}

	if ((strcmp(m,"avril")==0) || (strcmp(m,"juin")==0) || (strcmp(m,"septembre")==0) || (strcmp(m,"novembre")==0) ) nbjour=30;
	
	T_Emp E;

	if (strcmp(m,"janvier")==0) E.lemois=janvier;
	if (strcmp(m,"fevrier")==0) E.lemois=fevrier;
	if (strcmp(m,"mars")==0) E.lemois=mars;
	if (strcmp(m,"avril")==0) E.lemois=avril;
	if (strcmp(m,"mai")==0) E.lemois=mai;
	if (strcmp(m,"juin")==0) E.lemois=juin;
	if (strcmp(m,"juillet")==0) E.lemois=juillet;
	if (strcmp(m,"aout")==0) E.lemois=aout;
	if (strcmp(m,"septembre")==0) E.lemois=septembre;
	if (strcmp(m,"octobre")==0) E.lemois=octobre;
	if (strcmp(m,"novembre")==0) E.lemois=novembre;
	if (strcmp(m,"decembre")==0) E.lemois=decembre;
	
	for(i=0;i<ptrB->nbLivres;i++){
			JourJ=B_JourJ;
			int JourE = ((ptrB->etagere)[i].emprunteur.ladate);
			while(JourE != 0){
				if (JourE==nbjour) break;
				else {
					JourE++;
					JourJ++;
				}
			}

			JourJ -= nbjour;
			if(JourJ>7) {
				afficherLivre( &(ptrB->etagere[i])); 
				cmp++;}
			else if(E.lemois!=(ptrB->etagere)[i].emprunteur.lemois) {afficherLivre( &(ptrB->etagere[i])); cmp++;}
				
			}
			
	}

	if (cmp==0) printf("\nIl n'y a pas de livre en retard");
	
}
