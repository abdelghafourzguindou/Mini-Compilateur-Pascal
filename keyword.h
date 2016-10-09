#ifndef KEYWORD_H
#define KEYWORD_H

#include <string.h>

#define MAX_KEY_WORD 11
#define MAX_SPECIAL_CARACTER 16

char* KeyWords[MAX_KEY_WORD][2];
char* SpcialSymbol[MAX_SPECIAL_CARACTER][2];

char *toString(char*, int, int);
char *IsKeyWord(char*, int, int);
int isSpeacialSymbol(char*, int, int);


#endif // KEYWORD_H
