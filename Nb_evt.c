#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Cette fonction compte le nombre d'évènements du jour */

int Nb_evt(char CritereDate[])
{
    int compteur=0;
    char LigneComp[150] ;
    FILE* fichier = NULL ;


    fichier=fopen("BDD.txt","r");

    if (fichier != NULL)
    {
        rewind(fichier);
        while(fgetc(fichier)!=EOF)
        {
            fseek(fichier,-1,SEEK_CUR);
            fgets(LigneComp,150,fichier);
            if (strstr(LigneComp,CritereDate)!=NULL)  // on parcourt le fichier et on compte le nombre de lignes contenant la date du jour
            {
                compteur ++;

            }
        }
        fclose(fichier);
    }
    else
    {
        system("cls");
        printf("Ouverture echouee");
    }
    return compteur; // la valeur retournée est affichée dans le menu principal
}
