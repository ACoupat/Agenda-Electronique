#include <string.h>
#include <ctype.h>
// Cette fonction a pour but de mettre un mot en majuscule
void MAJ(char mot[150])
{
    int i=0;
    char MOT[150] ;

    while (mot[i]!='\0')
    {
       MOT[i] = toupper(mot[i]);
        i++;
    }
    strcpy(mot,MOT);
}
