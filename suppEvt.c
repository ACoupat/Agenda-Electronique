#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AfficheMenu.h"

void SuppEvt(int n,char critere[],int mode)
{
    char LigneComp[150];
    FILE *fichier = NULL;
    FILE *fichier2= NULL;
    int compteur=0,i;
    int compteurLigne=0;
    int numeroLigne=1;
    char c;


    fichier=fopen("BDD.txt","r+");

        if (fichier !=NULL)
        {
                rewind(fichier);
            while (compteur<n && fgetc(fichier)!=EOF) // On recherche la ligne � supprimer � partir du critere et du numero (voir ExtraitLigne)
            {

                fgets(LigneComp,100,fichier);
                compteurLigne++;// on compte le nombre de lignes pour savoir o� se trouve la ligne � supprimer

                if(strstr(LigneComp,critere)!=NULL)
                {
                    compteur++;
                }

            }

            rewind(fichier);
            fichier2=fopen("BDD_tmp.txt","w+");// On ouvre un deuxi�me fichier dans lequel on va recopier
            rewind(fichier);                   // le contenu du premier moins la ligne que l'on souhaite
            while (fgetc(fichier)!=EOF)        // supprimer.
            {
                fseek(fichier,-1,SEEK_CUR);
                c=fgetc(fichier);

                if(numeroLigne!=compteurLigne) // on copie le premier fichier dans le deuxi�me caract�re par caract�re
                {
                    fputc(c,fichier2);
                }
                                             // tout en comptant les lignes. Si le num�ro de la ligne � copier correspond
                if (c=='\n')                   // au num�ro de la ligne � supprimer on ne copie pas les carcat�res .
                {
                    numeroLigne++;
                }


            }


            fclose(fichier);
            fclose(fichier2);
            remove("BDD.txt");                              // On efface le premier fichier et on renomme le deuxieme comme le premier pour pouvoir le r�utiliser ult�rieurement
            rename("BDD_tmp.txt","BDD.txt");

            system("cls");
            for (i=0;i<7;i++)
            {
                printf("\n");
            }
            if (mode==3)// On affiche un message diff�rent suivant si l'on est dans le menu de suppression ou de modification

            {
                Ligne(205,1,80);
                printf("\n\n\t\t\t Suppression effectuee\n\n\n");
                Ligne(205,1,80);
            }
            else if (mode==4)
            {
                Ligne(205,1,80);
                printf("\n\n\t\tModification effectuee avec succes\n\n\n");
                Ligne(205,1,80);
            }

        }
        else
        {
            printf("Ouverture impossible");
        }

}
