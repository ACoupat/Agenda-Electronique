#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structures.h"
#include "RempliEvt.h"
#include "LigneFichier.h"
#include "AfficheDate.h"
#include "AfficheMenu.h"


void LigneFichier(evt evenement, char LigneFichier[],FILE* fichier) // Ecrit la ligne à écrire dans le fichier à partir de la structure evt evenement fournie
{
    sprintf(LigneFichier,"%s|%s|%s|%s\n",evenement.description,evenement.date,evenement.heure,evenement.type);
    fichier = fopen("BDD.txt","a");
    if (fichier != NULL)
    {
        fputs(LigneFichier,fichier);
        fclose(fichier);

    }
    else
    {
        printf("L'ouverture a echoue");
    }
}

// La ligne écrite dans le fichier sera de la forme :    DESCRIPTION|DATE|HEURE|TYPE\n
