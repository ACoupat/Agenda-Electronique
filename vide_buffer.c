#include <stdio.h>
#include <stdlib.h>

// Cette fonction vide le buffer, en effet cela s'avère utilie car des bugs peuvent survenir lors de l'acquisition si on ne le fait pas
void vide_buffer()
{
    int c = 0;

    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
