// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

//PROTOTYPES
void lectureFichierTXT();

void sauvegarde(T_Bibliotheque *ptrB);

void chargement(T_Bibliotheque *ptrB);


/////////////////////////////

//FONCTIONS

// fonction menu
int menu(){
	int choix;
	// au programme du TP7 :
	printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
	printf("\n 2 - afficher tous les livres de la bibliotheque "); 
	printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
	printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
	printf("\n 5 - supprimer un livre de la bibliotheque");
	// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


	// au programme du TP8 :
	// ajouter le champ emprunteur à votre structure T_Livre
	printf("\n 6 - emprunter un livre de la bibliotheque");
	printf("\n 7 - restituer/rendre un livre de la bibliotheque");
	printf("\n 8 - trier les livres (par titre)");
	printf("\n 9 - trier les livres (par auteur)");
	printf("\n 10 -trier les livres (par annee)");

	// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
	// vous pourrez alors faire les menus 11,12,etc...
	printf("\n 11- lister les livres disponibles "); 
	printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
	// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

	printf("\n 0 - QUITTER");
	printf("\n Votre choix : ");
	scanf("%d[^\n]",&choix);getchar();
	return choix;
}


// fonction sauvergarde  
void sauvegarde(T_Bibliotheque *ptrB){
	FILE *fic=NULL; //le type FILE
	int i;
	fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
	//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
	if (fic!=NULL){
		for(i=0;i<ptrB->nbLivres;i++){
			//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
			fwrite(  &(ptrB->etagere[i]),sizeof(T_livre),1,fic);
		}
		fclose(fic);
		puts("SAUVEGARDE REUSSIE ..............");
	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");
}


//fonction de chargement 
void chargement(T_Bibliotheque *ptrB){
	FILE *fic=NULL; //le type FILE
	int i=0;
	fic=fopen("baseLivres","r"); // r = le mode read
	//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
	if (fic!=NULL){
		do{
			fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
			i++;
		}while(!feof(fic));
		fclose(fic);
		ptrB->nbLivres=i-1;
		puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");
}


//fonction de lecture du fichier txt 
void lectureFichierTXT(){
	//int M=100;
	FILE *fic=NULL; //le type FILE
	//char chaine[M];
	//char chaine2[M];
	char c;
	fic=fopen("fic.txt","rt"); // r = le mode read   w = mode write (avec ecrasement)
	//fopen renvoie NULL si probleme (fichier effac� , disque non accessible ...
	
	if (fic!=NULL){
		do {
			//fgets(chaine,M,fic);   //fputs pour �crire dans un fichier txt
			//fscanf(fic,"%s",chaine); //fprintf pour �crire dans un fichier txt
			//	fscanf(fic,"%s %s",chaine,chaine2);
			fscanf(fic,"%c",&c);
			//fscanf(fic,"%c",&chaine[0]);
			//	if (!feof(fic))
			//printf("\n\t >%s--%s<",chaine,chaine2);
			printf(">%c<",c);
		} while(!feof(fic));
	
		fclose(fic);
		puts("\nLECTURE REUSSIE ..............");
	}
	else puts("ECHEC DE LECTURE DU FICHIER TXT !!!!!  ");
}


/////////////////////////////

//PROGRAMME PRINCIPAL

int main(){
	//lectureFichierTXT();
	int reponse,chx;
	T_Bibliotheque B; 
	init(&B);

	//chargement d'un fichier de structure(s) T_livre
	chargement(&B); 

	do{
		chx= menu();
		switch(chx){
			case 1 : 	
					reponse = ajouterLivre(&B);
					if (reponse==1) printf(" ajout reussi !!");  // cas ou l'ajout est réussi 
					else printf("impossible d ajouter (bibliotheque pleine)");  // cas ou la bibliotheque est pleine 
					printf("\n");
					sauvegarde(&B);	//sauvergarde du fichier
					break;
							
			case 2 : 	
					reponse=afficherBibliotheque(&B);
					if (reponse==0) printf("La bibliotheque est vide");  // cas ou la biblio est vide
					break;

			case 3 : 
					//demande à l'utilisateur
					T_Titre title;
					lireChaine("Quel est le titre du livre recherché ?",title, MAX_TITRE );
							
					//recherche du nom dans la bibliothèque puis utilisation de la fonction afficher livre : 
					int position = rechercherLivre(&B,title)[0];
					int occu = rechercherLivre(&B,title)[1];
					if (position!=-1) printf("Le dernier livre correspondant à ce nom se situe à la place numéro %d dans l'étagère. Il y en a %d dans la bibliothèque",position,occu);
					else printf("Le livre n'est pas dans le tableau");
					break;

			case 4 :
					// init var
					T_Aut auteur;
					
					//Saisir d'un nom d'auteur pour la recherche des titres:
					lireChaine("Veuillez saisir un auteur: ",auteur, K_MaxAut );

					// cas ou l'auteur possède des livres 
					// si l'auteur n'est pas trouvé, on renvoie une liste vide
					printf("\n Voici la liste de tout les livres de cet auteur: "); 
					rechercheLivreAuteur(&B, auteur);
					break;

			case 5 : 
					//demande à l'utilisateur
					lireChaine("Quel est le titre du livre a supprimer ?",title, MAX_TITRE );

					//recherche du nom dans la bibliothèque puis utilisation de la fonction supp livre : 
					int supp = supprimerLivre(&B,title);
					if (supp!=0) printf("Le livre %s est supprimé",title);
					else printf("La suppression est impossible");
					printf("\n");
					sauvegarde(&B);	//sauvergarde du fichier
					break;

			case 6 : 	
					//emprunter un livre 
					T_Aut nom;
					printf("\nQuel est le titre du livre que vous voulez emprunter ?");
					scanf("%[^\n]s",title);getchar();
					printf("\nQuel est votre nom ?");
					scanf("%[^\n]s",nom);getchar();		
					int test = emprunterLivre(&B,title,nom);
					if (test == 1){
						printf("\n Votre livre %s a bien été emprunté !", title);
						sauvegarde(&B);	//sauvergarde du fichier
					}
					else printf("\n Le livre n'a pas pu être emprunté car il n'est pas encore disponible !");
					printf("\n");
					break;
			
			case 7 :
					//restituer un livre
					lireChaine("Quel est le titre du livre que vous souhaitez restituer?: ",title, MAX_TITRE);
					lireChaine("Quel est votre nom ?",nom,K_MaxAut);
					test = rendreLivre (&B,title,nom);
					if (test == 1){
						printf("\n Votre livre %s a bien été rendu !", title);
						sauvegarde(&B);	//sauvergarde du fichier
					}
					if (test == 2) printf("\n Ce n'est pas vous qui avez emprunté ce livre");
					if (test == 0) printf("\n Le livre n'a pas pu être rendu car il n'est pas emprunté !");
					printf("\n");
					
					break;

			case 8 : 
					//trier les livres (par Titre)	
					trierLivresParTitre(&B);
					printf("Voici l'annuaire trié par titre : \n");
					afficherBibliotheque(&B);	
					printf("\n");
					sauvegarde(&B);	//sauvergarde du fichier
					break;
	
			case 9 : 
					//trier les livres (par auteur)
					trierLivresParAuteur(&B);
					printf("Voici l'annuaire trié par auteur : \n");
					afficherBibliotheque(&B);	
					printf("\n");
					sauvegarde(&B);	//sauvergarde du fichier
					break;


			case 10 : 
					//trier les livres (par annee)
					trierLivresParAnnee(&B);
					printf("Voici l'annuaire trié par année : \n");
					afficherBibliotheque(&B);	
					printf("\n");
					sauvegarde(&B);	//sauvergarde du fichier
					break;

			case 11 : 
					//lister les livres dispos 
					afficherLivreDispo(&B);
					break;
					
			break;	

			case 12 : 
					afficherLivreRetard(&B);
					//lister les empruns en retard  
			break;	

		}
	} while(chx!=0);  //condition d'arrêt
	
	sauvegarde(&B);	//sauvergarde du fichier

	return 0;
}