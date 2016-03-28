/* Ces fonctions servent � simplifier le code de la fonction AfficheMenu
en permettant de cr�er facilement diff�rents types de lignes pour les
bordures du menu.*/

#include <stdio.h>
#include <stdlib.h>

void Ligne(char caractere, int nombreDeLignes,int longueurLigne) // Cr�e une (ou plusieurs) ligne(s) de la longueur souhait�e avec le caract�re souhait�
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
void LigneVideDoubleBarre(int nombreLignes) // Cr�e une (ou plusieurs) ligne(s) vide(s) avec des bordures de chaque c�t�
{
    int i;
    for (i=0;i<nombreLignes;i++)
    {
         printf("%c                                                                              %c",186,186);
    }
}

void LigneRaccord()  // Cr�e un ligne de raccord entre deux "cases"
{

      printf("%c",204);
      Ligne(205,1,78);
      printf("%c",185);
}
