#include "cutting.h"

void print_token(char *token, int ptr_debut, int ptr_fin)
{
    while(ptr_debut <= ptr_fin) printf("%c", token[ptr_debut++]);
}

void fileToTempon()
{
    char *m = (char*)malloc(MAX_LINE);
    int row = 1; // c'est le nombre de ligne

    FILE *F = fopen(nameFile, "r");

    while(fgets(m,MAX_LINE,F) != NULL)
    {
        decoupage(m, row);
        row++;
    }
}

int isSpeacial(char s)
{
    if (s == '+' ||
        s == '-' ||
        s == '*' ||
        s == '/' ||
        s == ':' ||
        s == '=' ||
        s == ';' ||
        s == ',' ||
        s == '.' ||
        s == '<' ||
        s == '>' ||
        s == '(' ||
        s == ')' ||
        s == ' ' ||
        s == '\n'||
        s == '{') return 1 ;
    return 0 ;
}

void decoupage(char *temp, int line)
{
    int ptr_debut = 0, ptr_fin = 0 ;
    int longueur_line = strlen(temp);

    for(ptr_fin = 0 ; ptr_fin < longueur_line ; ptr_fin++)
    {
        if(!isSpeacial(temp[ptr_fin]))
        {
            if(ptr_fin == longueur_line - 1) Filter_identifer_number(temp, ptr_debut, ptr_fin);
            continue;
        }
        else if(temp[ptr_fin] != '\n')
        {
            ///Trait the token temp[ptr_debut-->ptrfin-1]
            if(!isSpeacial(temp[ptr_debut])) Filter_identifer_number(temp, ptr_debut, ptr_fin-1);

            ///Trait the commentaire
            /*if(temp[ptr_fin] == '{' && temp[ptr_fin+1] == '*')
            {
                while(temp[ptr_fin] != '*' && temp[ptr_fin+1] != '}')
                {
                    ptr_fin++;
                }
                ptr_debut = ptr_fin + 2;
            }*/

            ///Trait the space
            if(temp[ptr_fin] == ' ')
            {
                ptr_debut = ptr_fin + 1;
            }
            ///for the special symbol :=, <>, <=, >=
            else if(( temp[ptr_fin] == ':' && temp[ptr_fin+1] == '=') ||
                    ( temp[ptr_fin] == '<' && temp[ptr_fin+1] == '>') ||
                    ((temp[ptr_fin] == '<' || temp[ptr_fin]   == '>') && temp[ptr_fin+1] == '='))
            {
                //Traite de symbole
                getSpecialSymbol(temp, ptr_fin, ptr_fin+1);
                ptr_debut = ptr_fin + 2 ;
                ptr_fin++;
            }
            else
            {
                //Traite
                getSpecialSymbol(temp, ptr_fin, ptr_fin);
                ptr_debut = ptr_fin+1;
            }
        }
        else continue;
    }
}

void Filter_identifer_number(char* temp, int ptr_debut, int ptr_fin)
{   
    print_token(temp, ptr_debut, ptr_fin);

    if(isdigit(temp[ptr_debut]))
    {
        if(IsNumber(temp, ptr_debut, ptr_fin))
        {
            printf("\t\t\tNUMBER\n");
        }
        else
        {
            printf("\t\t\tERROR\n");
        }
    }
    else if(isalpha(temp[ptr_debut]))
    {
        char *unlex = IsKeyWord(temp, ptr_debut, ptr_fin);
        if(unlex != NULL)
        {
            printf("\t\t\t%s\n", unlex);
        }
        else if(IsIdentifier(temp, ptr_debut, ptr_fin))
        {
            printf("\t\t\tIDENTIFIER\n");
        }
        else
        {
            printf("\t\t\tERROR\n");
        }
    }
    else
    {
        printf("\t\t\tERROR\n");
    }
}

void getSpecialSymbol(char* str, int ptrs, int ptrf)
{
    print_token(str, ptrs, ptrf);

    char *k = isSpeacialSymbol(str, ptrs, ptrf);
    if(k != NULL) printf("\t\t\t%s\n", k);
    else printf("\t\t\tERROR\n");
}
