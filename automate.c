#include "automate.h"

void filling_Identifier_Automata()
{
    Trans_Tab    = (int**) malloc(2*sizeof(int*));
    Trans_Tab[0] = (int*)  malloc(MAX_CARACTER*sizeof(int));
    Trans_Tab[1] = (int*)  malloc(MAX_CARACTER*sizeof(int));

    int i,j;

    for(i=0; i<2; i++) for(j=0; j<255; j++)     Trans_Tab[i][j] = -1;
    ///pour a ....z
    for(j=0; j<2; j++) for(i=97; i<=122; i++)   Trans_Tab[j][i] = 1;
    ///pour A .......Z
    for(j=0; j<2; j++) for(i=65; i<=90; i++)    Trans_Tab[j][i] = 1;
    ///pour 0 ...........9
    for(i=48; i<=57; i++) Trans_Tab[1][i] = 1;
}

int IsIdentifier(char *word, int startptr, int finalptr)
{
    filling_Identifier_Automata();

    int e = 0, r, i = startptr;
    char s = word[i];
    while((Trans_Tab[e][(int)(s)]!=-1) && (i<finalptr))
    {
        r = (int)(s);
        e = Trans_Tab[e][r];
        i++;
        s = word[i];
    }
    r = (int)(s);
    e = Trans_Tab[e][r];
    if((e==1)) return 1;
    return 0;
}

void filling_Number_Automata()
{
    Trans_Tab    = (int**) malloc(4*sizeof(int*));
    Trans_Tab[0] = (int*)  malloc(MAX_CARACTER*sizeof(int));
    Trans_Tab[1] = (int*)  malloc(MAX_CARACTER*sizeof(int));
    Trans_Tab[2] = (int*)  malloc(MAX_CARACTER*sizeof(int));
    Trans_Tab[3] = (int*)  malloc(MAX_CARACTER*sizeof(int));

    int i, j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<256; j++)
            Trans_Tab[i][j] = -1;
    }

    for(i=(int)'0'; i<=(int)'9'; i++)
    {
        Trans_Tab[0][i] = 1;
        Trans_Tab[1][i] = 1;
        Trans_Tab[2][i] = 3;
        Trans_Tab[3][i] = 3;
    }
    Trans_Tab[1][(int)'.'] = 2;
}

int IsNumber(char* Number, int startptr, int finalptr)
{
    filling_Number_Automata();

    int i      = startptr;
    int state  = 0;
    int symbol = (int)(Number[i]);

    while(i < finalptr && Trans_Tab[state][symbol] != -1)
    {
        state  = Trans_Tab[state][symbol];
        symbol = (int)(Number[i]);
        i++;
    }
    state  = Trans_Tab[state][symbol];
    symbol = (int)(Number[i]);
    if((state == 3 || state == 1) && Trans_Tab[state][(int)(Number[i])] != -1) return 1;
    return 0;
}

