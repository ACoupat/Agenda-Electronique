#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ExtraitLigne(int n,char critere [],char LigneComp[]) // Cette fonction r�cup�re la ligne du fichier correspondant au choix de l'utilisateur
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
            fgets(LigneComp,100,fichier);      // on r�cup�re la ligne du fichier dans la cha�ne de caract�res LigneComp

            if(strstr(LigneComp,critere)!=NULL)   // on compte le nombre de lignes du fichier o� le crit�re apparait jusqu'� ce qu'on arrive au num�ro demand� par l'utilisateur
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
    if (fgetc(fichier)==EOF&&compteur==0) // Si aucune ligne ne correspond � la demande de l'utilisateur, la fonction retourne 0
    {
        resultat=0;
    }

   return resultat;
}

