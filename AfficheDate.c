#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structures.h"
#include "RempliEvt.h"
#include "LigneFichier.h"
#include "AfficheDate.h"
#include "AfficheMenu.h"
#include "time.h"

void AfficheDate(char Date[],char CritereDate [], int *annee) // Fournit la date � afficher dans le menu ainsi que que le crit�re de recherche pour les �v�nements d'aujourd'hui
{
    struct tm date;
    time_t secondes;
    char jourLettres[15]="azerty";

    secondes=time(NULL);
    date=*localtime(&secondes);

    switch (date.tm_wday)       // D�termine la chaine de caract�res � afficher correspondant au jour de la semaine en fonction du jour en cours
    {
        case 0: strcpy(jourLettres,"Dim");
        break;
        case 1: strcpy(jourLettres,"Lun");
        break;
        case 2: strcpy(jourLettres,"Mar");
        break;
        case 3: strcpy(jourLettres,"Mer");
        break;
        case 4: strcpy(jourLettres,"Jeu");
        break;
        case 5: strcpy(jourLettres,"Ven");
        break;
        case 6: strcpy(jourLettres,"Sam");
        break;
    }

    sprintf(Date,"Date : %s %02d/%02d/%d",jourLettres,date.tm_mday,date.tm_mon+1,date.tm_year+1900); // Cha�ne de caract�res qui est affich�e dans le menu principal
    *annee=date.tm_year+1900; // cette variable sert pour le contr�le d'acquisition dans RempliEvt
    sprintf(CritereDate,"%02d/%02d/%02d",date.tm_mday,date.tm_mon+1,date.tm_year+1900);//Cha�ne de caract�res utilis�e pour afficher la liste des �v�nements si l'utilisateur choisit '5' dans le menu principal
}
