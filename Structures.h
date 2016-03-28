#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct evt evt;

struct evt                  // Cette structure contient toutes les informations d'un �v�nement
{
    char type[50];
    char date[20];
    char heure[10];
    char description[100];

};

typedef struct H H;
struct H    //Structure utilis�e pour l'acquisition de l'heure
{
    int h, m;
};

typedef struct D D;
struct D //Structure utilis�e pour l'acquisition de la date
{
    int jour, mois,an ;
};
#endif // STRUCTURES_H_INCLUDED
