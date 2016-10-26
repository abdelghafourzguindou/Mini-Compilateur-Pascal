#ifndef CUTTING_H
#define CUTTING_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "automate.h"
#include "token.h"

#define nameFile "test.p"

FILE* file;
char current_char;

typedef struct _token {
    char         name[20];
    token_code_t code;
} token_t;

token_t current_token;

bool isSpecial(char);
bool isEmpty(char);
bool isComment(char);

void append(char*, char);
void read_char(FILE*);
void read_word(void);
void read_number(void);
void read_special_symbol(void);
void read_comment(void);
void getSpecialSymbol(char*);
void scaning(void);
void setCurrent_token_NULL(void);


#endif // CUTTING_H
