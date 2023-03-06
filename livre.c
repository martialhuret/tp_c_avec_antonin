#include "livre.h"

//////////////////////////////////////////////////////////
void saisirLivre(T_livre * ptrL){
    lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
    lireChaine("AUTEUR :", (ptrL->auteur ), K_MaxAut);
    lireChaine("EDITEUR :", (ptrL->editeur ), K_MaxEdit);
    printf("ANNEE :");
    scanf("%d",&(ptrL->annee));
    strcpy(ptrL->emprunteur.nomemprunteur,"");
}



void afficherLivre(T_livre *L){

    char jour[13],mois[13];
    
    printf("\nTitre du livre : %s",L->titre);
    printf("\nAuteur du livre : %s",L->auteur);
    printf("\nEditeur du livre : %s",L->editeur);
    printf("\nAnnée du livre : %d",L->annee);

    if (strlen(L->emprunteur.nomemprunteur)!=0){
        printf("\nEmprunteur du livre : %s",L->emprunteur.nomemprunteur);
        printf("\nEmprunt réalisé le : ");
    
        switch(L->emprunteur.lejour){
            case 0 :  strcpy(jour,"lundi");break;
            case 1 :  strcpy(jour,"mardi");break;
            case 2 :  strcpy(jour,"mercredi");break;
            case 3 :  strcpy(jour,"jeudi");break;
            case 4 :  strcpy(jour,"vendredi");break;
            case 5 :  strcpy(jour,"samedi");break;
            case 6 :  strcpy(jour,"dimanche");break;
            default : strcpy(jour,"jour inconnu");break;
        }
        
        printf("%s ",jour);
        printf("%d ",L->emprunteur.ladate);


        switch(L->emprunteur.lemois){
            case 0 :  strcpy(mois,"janvier");break;
            case 1 :  strcpy(mois,"fevrier");break;
            case 2 :  strcpy(mois,"mars");break;
            case 3 :  strcpy(mois,"avril");break;
            case 4 :  strcpy(mois,"mai");break;
            case 5 :  strcpy(mois,"juin");break;
            case 6 :  strcpy(mois,"juillet");break;
            case 7 :  strcpy(mois,"aout");break;
            case 8 :  strcpy(mois,"septembre");break;
            case 9 :  strcpy(mois,"octobre");break;
            case 10 :  strcpy(mois,"novembre");break;
            case 11 :  strcpy(mois,"decembre");break;

            default : strcpy(jour,"mois inconnu");break;
        }
        
        printf("%s ",mois);
        printf("%d\n\n",L->emprunteur.lannee);
    }
}





void lireDateSysteme(T_Emp *E){
    char j[9],m[10],h[9],mer[11],vir[2];
    int d,a;

    system("date > ladate"	);
    FILE * fic=NULL;  // pointeur de fichier
    fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

    //ici , si fic vaut NULL, alors le fopen a indiquÃ©
    //que le fichier ladate n'est pas accessible
    if (fic!=NULL){
        while(!feof(fic)){
            //fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);
            fscanf(fic,"%s %d %s %d %s",j,&d,m,&a,h);		
            //if (!feof(fic)) printf("\n-->LU : %s- %d- %s- %d- %s",j,d,m,a,h);		
        }
        fclose(fic);
        
        if (strstr(j,"lundi")==0) E->lejour=lundi;
        if (strstr(j,"mardi")==0) E->lejour=mardi;
        if (strstr(j,"mercredi")==0) E->lejour=mercredi;
        if (strstr(j,"jeudi")==0) E->lejour=jeudi;
        if (strstr(j,"vendredi")==0) E->lejour=vendredi;
        if (strstr(j,"samedi")==0) E->lejour=samedi;
        if (strstr(j,"dimanche")==0) E->lejour=dimanche;

        E->ladate=d;

        if (strcmp(m,"janvier")==0) E->lemois=janvier;
        if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
        if (strcmp(m,"mars")==0) E->lemois=mars;
        if (strcmp(m,"avril")==0) E->lemois=avril;
        if (strcmp(m,"mai")==0) E->lemois=mai;
        if (strcmp(m,"juin")==0) E->lemois=juin;
        if (strcmp(m,"juillet")==0) E->lemois=juillet;
        if (strcmp(m,"aout")==0) E->lemois=aout;
        if (strcmp(m,"septembre")==0) E->lemois=septembre;
        if (strcmp(m,"octobre")==0) E->lemois=octobre;
        if (strcmp(m,"novembre")==0) E->lemois=novembre;
        if (strcmp(m,"decembre")==0) E->lemois=decembre;


        E->lannee=a;
    }
    else{
        printf("n souci avec la date systeme !!");
        
        //on range une date irréelle 
        E->lejour=dimanche;
        E->ladate=99;
        E->lemois=decembre;
        E->lannee=-999;
    }

}
