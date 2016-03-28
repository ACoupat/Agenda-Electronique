#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structures.h"
#include "RempliEvt.h"
#include "LigneFichier.h"
#include "AfficheDate.h"
#include "AfficheMenu.h"
#include "MAJ.h"
#include "FonctionsAffichage.h"
#include <conio.h>

int AfficheMenu(char Date[],int compteurEvtDate) // affiche le menu principal et retourne le choix de l'utilisateur sous forme de nombre traité comme un caractère
{

      char choix='0';

      printf("%c",201);
      Ligne(205,1,78);
      printf("%c",187);
      LigneVideDoubleBarre(1);
      printf("%c                              AGENDA ELECTRONIQUE                             %c",186,186);
      LigneVideDoubleBarre(1);

      LigneRaccord();

      LigneVideDoubleBarre(1);
      printf("%c                                %c",186,201);
      Ligne(205,1,43);
      printf("%c %c",187,186);
      printf("%c   1. Rechercher un evenement   %c                                           %c %c",186,186,186,186);


      switch (strlen(Date))
      {
          case 19: printf("%c                                %c %s                       %c %c",186,186,Date,186,186);    //  Ce bloc sert à adapter l'affichage du menu principal
          break;                                                                                                          //  en fonction de la longueur de la chaîne Date pour ne
          case 20: printf("%c                                %c %s                      %c %c",186,186,Date,186,186);     //  pas décaler les bordures
          break;
          case 21: printf("%c                                %c %s                     %c %c",186,186,Date,186,186);
          break;
          default :printf("%c                                %c   Date : indisponible                     %c %c",186,186,186,186);
      }



      printf("%c   2. Ajouter un evenement      %c                                           %c %c",186,186,186,186);
      printf("%c                                %c  Nombre d'evenements aujourd'hui : %d      %c %c",186,186,compteurEvtDate,186,186);
      printf("%c   3. Supprimer un evenement    %c                                           %c %c",186,186,186,186);
      printf("%c                                %c  5. Consulter les evenements du jour      %c %c",186,186,186,186);
      printf("%c   4. Modifier un evenement     %c                                           %c %c",186,186,186,186);
      printf("%c                                %c",186,200);
      Ligne(205,1,43);
      printf("%c %c",188,186);
      LigneVideDoubleBarre(1);
      printf("%c",200);
      Ligne(205,1,78);
      printf("%c\n",188);

    do
    {
      printf("\n   Votre choix ? (1,2,3,4,5) : ");
      choix=getch();
      printf("%c",choix);

    }while (choix<'1' || choix>'5'); // contrôle d'acquisition

    return choix;
}

