#include <stdio.h>
#include <stdlib.h>
#include "FonctionsAffichage.h"
#include "IsNumeric.h"
#include <string.h>
#include "vide_buffer.h"

void AfficheListe(char critere[],int *n,int nb_evt,int mode)// Affiche la liste des événements correspondant au critère de recherche
{
    int compteur=0,i=0;
    char LigneComp[150] ;
    char numero[10];
    FILE* fichier = NULL ;



    system("cls");

    if (strcmp(critere,"")==0) // Si le critère rentré est nul
    {
        Ligne(205,1,80);
        printf("\n                        Tous les evenements \n\n");
        Ligne(205,1,80);
    }
    else if (mode==5 && nb_evt==1) // S'il y a un évènement aujourd'hui et qu'on veut les évènements du jour
    {
        Ligne(205,1,80);
        printf("\n                      %d evenement aujourd'hui \n\n",nb_evt);
        Ligne(205,1,80);
    }
    else if (mode==5 && nb_evt==0) // S'il n'y a pas d'évènement aujourd'hui et qu'on veut les évènements du jour
    {
        Ligne(205,1,80);
        printf("\n                      Aucun evenement aujourd'hui \n\n");
        Ligne(205,1,80);
    }
    else if (mode==5 && nb_evt!=1) // S'il y a plusieurs évènements aujourd'hui et qu'on veut les évènements du jour
    {
        Ligne(205,1,80);
        printf("\n                      %d evenements aujourd'hui \n\n",nb_evt);
        Ligne(205,1,80);
    }

    else
    {

        Ligne(205,1,80);
        printf("\n                        Recherche : %s\n\n",critere); // Affiche le critère de recherche au dessus des résultats
        Ligne(205,1,80);

    }

    fichier=fopen("BDD.txt","r");

    if (fichier != NULL) // Dans cette fonction, nous allons lister et numéroter les différents évènements qui correspondent
    {                    // au critère de recherche.

        rewind(fichier); // on revient au début du fichier
        while(fgetc(fichier)!=EOF) // tant que l'on est pas à la fin du fichier
        {
            fseek(fichier,-1,SEEK_CUR); // on se place au début de la ligne
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
        if (fgetc(fichier)==EOF && compteur == 0) // S'il n'y a aucun résultat pour la recherche.
        {
            printf("\n\n\n\t\tAucun resultat pour votre recherche\n\n\n");

        }
        else
        {

            printf("\n\n\n Retourner au menu ? (M) / Continuer ? (C)"); // On a le choix de retourner au menu sans avoir choisi
            switch (mode)                                               // un évènement, ou de continuer pour pouvoir consulter un évènement
            {


                case 3: // Si l'on veut supprimer un élément
                    printf("\n\n (Vous ne pourrez plus revenir en arriere avant d'avoir supprime un evenement)");
                break;

                case 4: // Si l'on veut modifier un évènement
                    printf("\n\n (Vous ne pourrez plus revenir en arriere avant d'avoir modifie un evenement)");
                break;

            }

            *n=fgetc(stdin); // Ce pointeur retourne le choix de l'utilisateur
            while (*n!= 'M' && *n !='c' && *n!= 'm' && *n !='C')
            {
                printf("\nIncorrect, veuillez reessayer \n"); // contrôle d'acquisition
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
                        while (IsNumeric(numero)==0) // Tant que la chaine de caractères entrée n'est pas un nombre
                        {
                            printf("\nIncorrect, veuillez reessayer");
                            fgets(numero,9,stdin);
                        }
                        *n=(int)strtol(numero,NULL,10); // Ce pointeur retourne le choix de l'utilisateur (numéro de l'évènement)

                    }while(*n<1 || *n>compteur);


            }

        }

    }
    else
    {
        printf("Ouverture echouee"); // Si le fichier BDD.txt n'existe pas
    }

}
