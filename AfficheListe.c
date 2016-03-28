#include <stdio.h>
#include <stdlib.h>
#include "FonctionsAffichage.h"
#include "IsNumeric.h"
#include <string.h>
#include "vide_buffer.h"

void AfficheListe(char critere[],int *n,int nb_evt,int mode)// Affiche la liste des �v�nements correspondant au crit�re de recherche
{
    int compteur=0,i=0;
    char LigneComp[150] ;
    char numero[10];
    FILE* fichier = NULL ;



    system("cls");

    if (strcmp(critere,"")==0) // Si le crit�re rentr� est nul
    {
        Ligne(205,1,80);
        printf("\n                        Tous les evenements \n\n");
        Ligne(205,1,80);
    }
    else if (mode==5 && nb_evt==1) // S'il y a un �v�nement aujourd'hui et qu'on veut les �v�nements du jour
    {
        Ligne(205,1,80);
        printf("\n                      %d evenement aujourd'hui \n\n",nb_evt);
        Ligne(205,1,80);
    }
    else if (mode==5 && nb_evt==0) // S'il n'y a pas d'�v�nement aujourd'hui et qu'on veut les �v�nements du jour
    {
        Ligne(205,1,80);
        printf("\n                      Aucun evenement aujourd'hui \n\n");
        Ligne(205,1,80);
    }
    else if (mode==5 && nb_evt!=1) // S'il y a plusieurs �v�nements aujourd'hui et qu'on veut les �v�nements du jour
    {
        Ligne(205,1,80);
        printf("\n                      %d evenements aujourd'hui \n\n",nb_evt);
        Ligne(205,1,80);
    }

    else
    {

        Ligne(205,1,80);
        printf("\n                        Recherche : %s\n\n",critere); // Affiche le crit�re de recherche au dessus des r�sultats
        Ligne(205,1,80);

    }

    fichier=fopen("BDD.txt","r");

    if (fichier != NULL) // Dans cette fonction, nous allons lister et num�roter les diff�rents �v�nements qui correspondent
    {                    // au crit�re de recherche.

        rewind(fichier); // on revient au d�but du fichier
        while(fgetc(fichier)!=EOF) // tant que l'on est pas � la fin du fichier
        {
            fseek(fichier,-1,SEEK_CUR); // on se place au d�but de la ligne
            fgets(LigneComp,150,fichier);
            if (strstr(LigneComp,critere)!=NULL)
            {
                compteur ++;
                printf("\n\n      %d. ",compteur);
                i=0;
                while(LigneComp[i]!='|')
                {
                    printf("%c",LigneComp[i]);
                    i++;

                }
            }
        }
        fclose(fichier);
        if (fgetc(fichier)==EOF && compteur == 0) // S'il n'y a aucun r�sultat pour la recherche.
        {
            printf("\n\n\n\t\tAucun resultat pour votre recherche\n\n\n");

        }
        else
        {

            printf("\n\n\n Retourner au menu ? (M) / Continuer ? (C)"); // On a le choix de retourner au menu sans avoir choisi
            switch (mode)                                               // un �v�nement, ou de continuer pour pouvoir consulter un �v�nement
            {


                case 3: // Si l'on veut supprimer un �l�ment
                    printf("\n\n (Vous ne pourrez plus revenir en arriere avant d'avoir supprime un evenement)");
                break;

                case 4: // Si l'on veut modifier un �v�nement
                    printf("\n\n (Vous ne pourrez plus revenir en arriere avant d'avoir modifie un evenement)");
                break;

            }

            *n=fgetc(stdin); // Ce pointeur retourne le choix de l'utilisateur
            while (*n!= 'M' && *n !='c' && *n!= 'm' && *n !='C')
            {
                printf("\nIncorrect, veuillez reessayer \n"); // contr�le d'acquisition
                vide_buffer();
                *n=fgetc(stdin);
            }

            if (*n=='c' || *n == 'C')
            {
                vide_buffer();
                switch (mode)
                {
                    case 1:
                        printf("\n\nQuel evenement souhaitez-vous voir en detail ? (entrez le n%c)\n",167);
                    break;

                    case 3:
                        printf("\n\nQuel evenement souhaitez-vous supprimer ? (entrez le n%c)\n",167);
                    break;

                    case 4:
                        printf("\n\nQuel evenement souhaitez-vous modifier ? (entrez le n%c)\n",167);
                    break;
                    case 5:
                        printf("\n\nQuel evenement souhaitez-vous voir en detail ? (entrez le n%c)\n",167);
                    break;
                }

                    do
                    {
                        fgets(numero,9,stdin); // Acquisition du choix de l'utilsateur
                        while (IsNumeric(numero)==0) // Tant que la chaine de caract�res entr�e n'est pas un nombre
                        {
                            printf("\nIncorrect, veuillez reessayer");
                            fgets(numero,9,stdin);
                        }
                        *n=(int)strtol(numero,NULL,10); // Ce pointeur retourne le choix de l'utilisateur (num�ro de l'�v�nement)

                    }while(*n<1 || *n>compteur);


            }

        }

    }
    else
    {
        printf("Ouverture echouee"); // Si le fichier BDD.txt n'existe pas
    }

}
