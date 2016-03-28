#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structures.h"
#include "RempliEvt.h"
#include "LigneFichier.h"
#include "AfficheDate.h"
#include "AfficheMenu.h"
#include "vide_buffer.h"
#include "MAJ.h"
#include "controle.h"
#include <time.h>
void RempliEvt(evt *evenementAjout, int annee)// Remplit la structure evenement fournie avec toutes les informations
{

    H heure;
    D d;
    char date[50];
    char hour[10];
    struct tm DATE;
    time_t secondes;
    secondes=time(NULL); // Initialisation requise pour utiliser la structures tm
    DATE=*localtime(&secondes);

    system("cls");

    printf("Entrez la description de l'evenement :\n"); // Acquisition de la description
    gets(evenementAjout->description);
    MAJ(evenementAjout->description);

    printf("Entrez la date de l'evenement sous la forme jj / mm / aaaa :\n"); // Acquisition de la date

    do // On contrôle le texte entré ainsi que sa validité (voir fonction controle conditions de la boucle )
    {
         fgets(date,11,stdin);
    }
    while (controle('D',date,&(d.jour),&(d.mois),&(d.an)) || d.jour < 0 || d.jour > 31 || d.mois < 0 || d.mois > 12);

    sprintf(evenementAjout->date,"%02d/%02d/%d",d.jour,d.mois,d.an);

    printf("Entrez l'heure de l'evenement sous la forme hh:mm :\n"); // Acquisition de la date


    do // Contrôle du texte via la fonction controle et controle de la validité grace aux opérateurs logiques.
    // On contrôle également que l'heure entrée ne soit pas inférieure à l'heure acutelle si la date est celle du jour en cours
    {
        fgets(hour,6,stdin);
    }
    while (controle ('H',hour,&(heure.h),&(heure.m),NULL) || heure.h < 0 || heure.h > 24 || heure.m < 0 || heure.m > 60 || (d.an == DATE.tm_year+1900  && d.jour == DATE.tm_mday && d.mois == DATE.tm_mon+1 && heure.h <= DATE.tm_hour && heure.m < DATE.tm_min));

    sprintf(evenementAjout->heure,"%02d:%02d",heure.h,heure.m);

    vide_buffer();
    printf("Entrez le type de l'evenement :\n");
    gets(evenementAjout->type);
    MAJ(evenementAjout->type);


}
