#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ExtraitLigne(int n,char critere [],char LigneComp[]) // Cette fonction récupère la ligne du fichier correspondant au choix de l'utilisateur
{
    FILE *fichier=NULL;

    int compteur=0,resultat=1;


    fichier=fopen("BDD.txt","r+");
    if (fichier != NULL)
    {
        rewind(fichier);
        while (compteur<n && fgetc(fichier)!=EOF)
        {

            fseek(fichier,-1,SEEK_CUR);
            fgets(LigneComp,100,fichier);      // on récupère la ligne du fichier dans la chaîne de caractères LigneComp

            if(strstr(LigneComp,critere)!=NULL)   // on compte le nombre de lignes du fichier où le critère apparait jusqu'à ce qu'on arrive au numéro demandé par l'utilisateur
            {
                compteur++;
            }

        }
        fclose(fichier);
    }
    else
    {
        printf("ouverture echouee");
    }
    if (fgetc(fichier)==EOF&&compteur==0) // Si aucune ligne ne correspond à la demande de l'utilisateur, la fonction retourne 0
    {
        resultat=0;
    }

   return resultat;
}

