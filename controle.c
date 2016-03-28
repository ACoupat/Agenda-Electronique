#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "vide_buffer.h"
/* Cette fonction permet de contrôler le format de l'heure et de la date, ainsi que leur validité, la fonction retourne 1
 si une condition n'est pas bonne. */
int controle (char typo, char texte[], int *v1, int *v2,int *v3)
{
    int i,erreur=0;
    struct tm DATE;
    time_t secondes;

    secondes=time(NULL);
    DATE=*localtime(&secondes);

    if (typo == 'D') // Si l'on veut contrôler la date
    {
        char jour [3];
        char mois [3];
        char annee [5];


        for (i=0;i<11;i++)
        {
            if ((texte[i]<'0' || texte[i]>'9') && (texte[2]!='/' || texte [5]!='/')) // Si le texte entré n'est pas un nombre
                erreur = 1;

                /* On recopie le texte entré à l'exception des '/' dans 3 variables différentes */
            if (i<2)
            {
                jour [i] = texte[i];
            }
            if (i>2 && i<=4)
            {
                mois [i-3] = texte[i];
            }
            if (i>5)
            {
                annee [i-6] = texte[i];

            }


        }
        *v1 = (int) strtol(jour,NULL,10); // On retourne 3 valeurs pour le jour, le mois, l'année à l'aide de trois pointeurs.
        *v2 = (int) strtol(mois,NULL,10);
        *v3 = (int) strtol(annee,NULL,10);

        if(*v3<DATE.tm_year+1900) /* On controle si la date de l'évènement est inférieure à la date d'aujourd'hui */
        {
            erreur=1;
        }
        else if (*v3==DATE.tm_year+1900)
        {
            if(*v2<DATE.tm_mon+1)
            {
                erreur=1;
            }
            else if (*v2==DATE.tm_mon+1)
            {
                if (*v1<DATE.tm_mday)
                    erreur = 1;
            }
        }


    }
    else if (typo == 'H') // Si l'on veut contrôler l'heure de l'évènement.
    {
        char heure [3];
        char min [3];
        for (i=0;i<6;i++) /* On contrôle juste si l'utilisateur n'a pas rentré de lettres, le contrôle des valeurs pour heure et min est fait dans le main */
        {
            if ((texte[i]<'0' || texte[i]>'9') && texte[2]!=':')
                erreur = 1;
            if (i<2)
            {
                heure [i] = texte[i];
            }
            else if (i>2 && i<=4)
            {
                min [i-3] = texte [i];
            }

        }
        *v1 = strtol(heure,NULL,10); /* On retourne l'heure et le nombre de minutes à l'aide de deux pointeurs */
        *v2 = strtol(min,NULL,10);
    }
    return erreur ;
}







