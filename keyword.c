#include "keyword.h"

char* KeyWords[MAX_KEY_WORD][2] = {
                        {"program", "PROGRAM_TOKEN"},
                        {"const",   "CONST_TOKEN"},
                        {"var",     "VAR_TOKEN"},
                        {"begin",   "BEGIN_TOKEN"},
                        {"end",     "END_TOKEN"},
                        {"if",      "IF_TOKEN"},
                        {"then",    "THEN_TOKEN"},
                        {"while",   "WHILE_TOKEN"},
                        {"do",      "DO_TOKEN"},
                        {"read",    "READ_TOKEN"},
                        {"write",   "WRITE_TOKEN"}
                       };

char* SpcialSymbol[MAX_SPECIAL_CARACTER][2] = {
                        {";",   "PV_TOKEN"},
                        {".",   "PT_TOKEN"},
                        {"+",   "PLUS_TOKEN"},
                        {"-",   "MOINS_TOKEN"},
                        {"*",   "MULT_TOKEN"},
                        {"/",   "DIV_TOKEN"},
                        {",",   "VIR_TOKEN"},
                        {"=",   "EG_TOKEN"},
                        {":=",  "AFF_TOKEN"},
                        {"<",   "INF_TOKEN"},
                        {"<=",  "INFEG_TOKEN"},
                        {">",   "SUP_TOKEN"},
                        {">=",  "SUPEG_TOKEN"},
                        {"<>",  "DIFF_TOKEN"},
                        {"(",   "PO_TOKEN"},
                        {")",   "PF_TOKEN"},
                        {"EOF", "FIN_TOKEN"}
                       };

char *toString(char* temp, int ptrs, int ptrf)
{
    int lenght = ptrf - ptrs + 1;
    char *str = (char*) malloc((lenght)*sizeof(char));
    int i = 0;
    while(ptrs <= ptrf)
    {
        str[i] = temp[ptrs];
        ptrs++;
        i++;
    }
    str[i] = '\0';
    return str;
}

char* IsKeyWord(char* word, int ptrs, int ptrf)
{
    char *kword = toString(word, ptrs, ptrf);
    int i, j;
    for(i = 0; i<MAX_KEY_WORD; i++)
        if(strcmp(kword, KeyWords[i][0]) == 0) return KeyWords[i][1];
    return NULL;
}

int isSpeacialSymbol(char* symbol, int ptrs, int ptrf)
{
    char *Spec = toString(symbol, ptrs, ptrf);
    int i, j;
    for(i = 0; i<MAX_SPECIAL_CARACTER; i++)
        if(strcmp(Spec, SpcialSymbol[i][0]) == 0) return SpcialSymbol[i][1];
    return NULL;
}
