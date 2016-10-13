
#include "cutting.h"

void print_token(char *token, int ptr_debut, int ptr_fin)
{
    printf("\n<ptrs = %d, ptrf = %d>\n", ptr_debut, ptr_fin);
    while(ptr_debut <= ptr_fin) printf("%c", token[ptr_debut++]);
}

void fileToTempon()
{
    pascalTabS = NULL;
    isComment  = false;

    char *m = (char*)malloc(MAX_LINE*sizeof(char));
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
        s == '\t'||
        s == '{') return 1 ;
    return 0 ;
}

void decoupage(char *temp, int line)
{
    int ptr_debut = 0, ptr_fin = 0 ;
    int longueur_line = strlen(temp);

    //printf("\nDECOPAGE ::: %s\n", temp);

    for(ptr_fin = 0; ptr_fin < longueur_line; ptr_fin++)
    {
        ///Trait the commentaire
        if(temp[ptr_fin] == '{' && temp[ptr_fin+1] == '*') {isComment = true;}
        if(temp[ptr_fin] == '*' && temp[ptr_fin+1] == '}') {isComment = false; ptr_fin += 2; }
        if(isComment) continue;

        if(!isSpeacial(temp[ptr_fin]))
        {
            if(ptr_fin == longueur_line - 1) Filter_identifer_number(temp, ptr_debut, ptr_fin);
            continue;
        }
        else
        {
            ///Trait the token temp[ptr_debut-->ptrfin-1]
            if(!isSpeacial(temp[ptr_debut])) Filter_identifer_number(temp, ptr_debut, ptr_fin-1);

            ///Trait the space and tab
            if(temp[ptr_fin] == ' ' || temp[ptr_fin] == '\t')
            {
                ptr_debut = ptr_fin + 1;
            }

            else if(temp[ptr_fin] == '\n')
            {
                continue;
            }

            ///for the special symbol :=, <>, <=, >=
            else if(( temp[ptr_fin] == ':' && temp[ptr_fin+1] == '=') ||
                    ( temp[ptr_fin] == '<' && temp[ptr_fin+1] == '>') ||
                    ((temp[ptr_fin] == '<' || temp[ptr_fin]   == '>') && temp[ptr_fin+1] == '='))
            {
                getSpecialSymbol(temp, ptr_fin, ptr_fin+1);
                ptr_debut = ptr_fin + 2 ;
                ptr_fin++;
            }
            else
            {
                getSpecialSymbol(temp, ptr_fin, ptr_fin);
                ptr_debut = ptr_fin+1;
            }
        }
    }
}

void addLexem(char *temp, int ptr_debut, int ptr_fin, char *unlex)
{
   // printf("unlex : %s\n", unlex);

    symbolTable_t *lex = (symbolTable_t*) malloc(sizeof(symbolTable_t));

    lex->lexem      = toString(temp, ptr_debut, ptr_fin);
    lex->lexUnity   = (char*) malloc(strlen(unlex)*sizeof(char));
    strcpy(lex->lexUnity, unlex);
    lex->nextLexem  = NULL;

    if(pascalTabS == NULL) pascalTabS = lex;
    else
    {
        symbolTable_t *next = pascalTabS;
        while(next->nextLexem != NULL) next = next->nextLexem;
        next->nextLexem = lex;
    }
}

void Filter_identifer_number(char* temp, int ptr_debut, int ptr_fin)
{   
    //print_token(temp, ptr_debut, ptr_fin);

    if(isdigit(temp[ptr_debut]))
    {
        if(IsNumber(temp, ptr_debut, ptr_fin))
        {
            //printf("\t\t\tNUMBER\n");
            addLexem(temp, ptr_debut, ptr_fin, "NUMBER");
        }
        else
        {
            //printf("\t\t\tERROR\n");
            addLexem(temp, ptr_debut, ptr_fin, "ERROR");
        }
    }
    else if(isalpha(temp[ptr_debut]))
    {
        char *unlex = IsKeyWord(temp, ptr_debut, ptr_fin);
        if(unlex != NULL)
        {
            //printf("\t\t\t%s\n", unlex);
            addLexem(temp, ptr_debut, ptr_fin, unlex);
        }
        else if(IsIdentifier(temp, ptr_debut, ptr_fin))
        {
            //printf("\t\t\tIDENTIFIER\n");
            addLexem(temp, ptr_debut, ptr_fin, "IDENTIFIER");

        }
        else
        {
            //printf("\t\t\tERROR\n");
            addLexem(temp, ptr_debut, ptr_fin, "ERROR");

        }
    }
    else
    {
        //printf("\t\t\tERROR\n");
        addLexem(temp, ptr_debut, ptr_fin, "ERROR");
    }
}

void getSpecialSymbol(char* str, int ptrs, int ptrf)
{
    //print_token(str, ptrs, ptrf);

    char *k = isSpeacialSymbol(str, ptrs, ptrf);
    if(k != NULL) addLexem(str, ptrs, ptrf, k); //printf("\t\t\t%s\n", k);
    else addLexem(str, ptrs, ptrf, "ERROR");    //printf("\t\t\tERROR\n");
}

void printLexTab()
{
    symbolTable_t *next = pascalTabS;
    while(next != NULL)
    {
        printf("\t%s\t\t\t\t%s\n", next->lexem, next->lexUnity);
        next = next->nextLexem;
    }
}
