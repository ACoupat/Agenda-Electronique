/* Ces fonctions servent à simplifier le code de la fonction AfficheMenu
en permettant de créer facilement différents types de lignes pour les
bordures du menu.*/

#include <stdio.h>
#include <stdlib.h>

void Ligne(char caractere, int nombreDeLignes,int longueurLigne) // Crée une (ou plusieurs) ligne(s) de la longueur souhaitée avec le caractère souhaité
{
    int i,j;
    if (longueurLigne>80)
    {
        longueurLigne=80;
    }
    for (i=0;i<nombreDeLignes;i++)
    {
        for (j=0;j<longueurLigne;j++)
        {
            printf("%c",caractere);
        }
    }
}
void LigneVideDoubleBarre(int nombreLignes) // Crée une (ou plusieurs) ligne(s) vide(s) avec des bordures de chaque côté
{
    int i;
    for (i=0;i<nombreLignes;i++)
    {
         printf("%c                                                                              %c",186,186);
    }
}

void LigneRaccord()  // Crée un ligne de raccord entre deux "cases"
{

      printf("%c",204);
      Ligne(205,1,78);
      printf("%c",185);
}
