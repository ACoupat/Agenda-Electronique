int IsNumeric(char valeur[]) // vérifie si la chaîne entrée correspond à un nombre
{
    int i=0, erreur=1;

    while (valeur[i]!='\0')
    {

        if ((valeur[i]<'0' || valeur[i]>'9')&& valeur[i]!='\n')
        {
            erreur=0;
        }
        i++;
    }
    return erreur;
}
