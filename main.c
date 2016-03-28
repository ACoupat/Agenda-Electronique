#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structures.h"
#include "RempliEvt.h"
#include "LigneFichier.h"
#include "AfficheDate.h"
#include "AfficheMenu.h"
#include "ExtraitLigne.h"
#include "AfficheEvt.h"
#include "FonctionsAffichage.h"
#include "vide_buffer.h"
#include "Nb_evt.h"
#include "MAJ.h"
#include "AfficheListe.h"
#include "suppEvt.h"

int main()
{
    evt evenement;
    char LigneF[150];
    char choixMenu,n;
    char critere[50];
    char LigneComp[150];
    int resultat;
    char retourMenu;
    char CritereDate[20];
    char Date[22];
    int annee;
    FILE* fichier=NULL;

    do
    {
    system("cls"); // On efface la console
    AfficheDate(Date,CritereDate,&annee); // On "calcule" la date du jour
    choixMenu=AfficheMenu(Date,Nb_evt(CritereDate)); // On acquiert le choix de l'utilisateur
        do
        {
                switch(choixMenu)
            {


                case '1': // L'utilisateur veut faire une recherhe
                    printf("\n\nCritere de recherche (pour afficher tout appuyez sur Entree) :");
                    gets(critere); // on demande un crit�re de recherche � l'utilisateur
                    MAJ(critere);
                    AfficheListe(critere,&n,Nb_evt(CritereDate),1); // On affiche les �v�nements correspondant au crit�re
                    if (n!='m' && n!='M')
                    {
                        resultat=ExtraitLigne(n,critere,LigneComp); // On stocke l'�v�nement dans la chaine de caract�res LigneComp
                        if (resultat!=0)
                        {
                           AfficheEVT(LigneComp); // On affiche l'�v�nement demand� � partir de la variable chaine de caract�res LigneComp
                        }
                        printf("\n\n Nouvelle Recherche? (R) / Retourner au menu ? (M)");

                        do // contr�le d'acquisition
                        {
                            retourMenu = fgetc(stdin);

                        }while (retourMenu!='R' && retourMenu!='r' && retourMenu!='M' && retourMenu!='m');
                        vide_buffer();
                     }
                     else
                     {
                         vide_buffer();
                         retourMenu='M';
                     }


                break;

                case '2': // L'utilisateur veut ajouter un nouvel �v�nement

                    RempliEvt(&evenement,annee);
                    LigneFichier(evenement,LigneF,fichier);
                    printf("\n\n Ajouter un nouvel evenement ? (R) / Retourner au menu ? (M)"); /* On laisse � l'utilisateur le choix d'ajouter un autre
                                                                                                �v�nement ou de retourner au menu */

                    do // contr�le d'acquisition
                    {
                        retourMenu = fgetc(stdin);

                    }while (retourMenu!='R' && retourMenu!='r' && retourMenu!='M' && retourMenu!='m');
                    vide_buffer();

                break;



                case '3' : // L'utilisateur veut supprimer un �v�nement
                    printf("\n\nCritere de recherche (pour afficher tout appuyer sur Entree)");
                    gets(critere); // on demande un crit�re de recherche � l'utilisateur
                    MAJ(critere);
                    AfficheListe(critere,&n,Nb_evt(CritereDate),3); // On affiche les �v�nements correspondant au crit�re
                    if (n!='m' && n!='M')
                    {
                        resultat=ExtraitLigne(n,critere,LigneComp);
                        if (resultat!=0)
                        {
                           SuppEvt(n,critere,3); // On supprime l'�v�nement s�lectionn�
                        }

                        printf("\n\n Supprimer d'autres evenements ? (R) / Retourner au menu ? (M)");

                        do
                        {
                            retourMenu = fgetc(stdin);


                        }while (retourMenu!='R' && retourMenu!='r' && retourMenu!='M' && retourMenu!='m');
                        vide_buffer();
                    }
                    else
                    {
                        retourMenu='M';
                    }
                break;

              case '4': // L'utilisateur veut modifier un �v�nement
                        // On va d'abord supprimer l'�v�nement s�lectionn�, puis demander � l'utilisateur d'entrer le nouvel �v�nement
                    printf("\n\nCritere de recherche (pour afficher tout appuyer sur Entree)");
                    gets(critere);
                    MAJ(critere);
                    AfficheListe(critere,&n,Nb_evt(CritereDate),4);
                    if (n!='m' && n!='M')
                    {
                        resultat=ExtraitLigne(n,critere,LigneComp);
                        RempliEvt(&evenement, annee);
                        LigneFichier(evenement,LigneF,fichier);

                        if (resultat!=0)
                        {
                           SuppEvt(n,critere,4);
                        }

                        printf("\n\nModifier un autre evenement ? (R) / Retourner au menu ? (M)");

                        do
                        {

                            retourMenu = fgetc(stdin);


                        }while (retourMenu!='R' && retourMenu!='r' && retourMenu!='M' && retourMenu!='m');
                        vide_buffer();
                    }
                    else
                    {
                        retourMenu='M';
                    }


                break;


                case '5': // L'utilisateur veut consulter les �v�nements du jour.

                    AfficheListe(CritereDate,&n,Nb_evt(CritereDate),5); // affiche les �v�nements du jours num�rot�s (fonctionne comme une recherche avec la date en crit�re)
                     if (n!='m' && n!='M')
                    {
                        resultat=ExtraitLigne(n,CritereDate,LigneComp);
                        if (resultat!=0)
                        {
                           AfficheEVT(LigneComp);
                        }

                        printf("\n\n Retourner au menu ? (M)");

                        do
                       {

                         retourMenu = fgetc(stdin);

                       }while (retourMenu!='M' && retourMenu!='m');

                        vide_buffer();
                    }
                     else
                    {
                        retourMenu='M';
                    }

                break;
            }


            }while (retourMenu=='R' || retourMenu=='r');
    }while (retourMenu=='M' || retourMenu=='m');

    return 0;
}
