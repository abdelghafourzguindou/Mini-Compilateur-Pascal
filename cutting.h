#ifndef CUTTING_H
#define CUTTING_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "Automate.h"
#include "Keyword.h"

#define nameFile "Test.p"
#define MAX_LINE 150

typedef struct _symbolTable {
    char *lexem;
    char *lexUnity;
    struct _symbolTable *nextLexem;
} symbolTable_t;

symbolTable_t *pascalTabS;

void decoupage(char* , int );
void fileToTempon();
void print_token(char*, int, int);
void Filter_identifer_number(char*, int, int);
void getSpecialSymbol(char*, int, int);
symbolTable_t * addLexem(symbolTable_t *, char*, int, int, char*);
void printLexTab();


#endif // CUTTING_H
