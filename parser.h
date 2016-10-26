#ifndef PARSER_H
#define PARSER_H

#include "scaner.h"

extern token_t current_token;
extern char    current_char;

void parsering(void);
void print_token(void);

#endif // PARSER_H
