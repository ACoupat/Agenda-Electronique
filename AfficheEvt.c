#include "FonctionsAffichage.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
void AfficheEVT(char LigneFichier[])// Affiche un �v�nement sous une forme plus lisible � partir de la ligne correspondante extraite du fichier
{
    int i=0,j;

    system("cls");
    Ligne(205,1,80);
    printf("\n    Description de l'evenement :");
    while (LigneFichier[i]!='|')                            // Chaque bloc while copie le contenu de la cha�ne LigneFichier
    {                                                       // jusqu'� ce qu'il rencontre un s�parateur ' | ' ou le '\n' de
        printf("%c",LigneFichier[i]);                       // fin de ligne.
        i++;
    }
    i++;
    printf("\n\n    Date de l'evenement :");
    while (LigneFichier[i]!='|')
    {
        printf("%c",LigneFichier[i]);
        i++;
    }
    i++;
    printf("\n\n    Heure de l'evenement :");
    while (LigneFichier[i]!='|')
    {
        printf("%c",LigneFichier[i]);
        i++;
    }
    i++;
    printf("\n\n    Type d'evenement :");
    while (LigneFichier[i]!='\n')
    {
        printf("%c",LigneFichier[i]);
        i++;
    }
    printf("\n\n");
    Ligne(205,1,80);
       for(j=0;j<3;j++)
    {
        printf("\n");
    }
}
