#ifndef PARSER_H
#define PARSER_H

#include "scaner.h"

extern token_t current_token;
extern char    current_char;

void get_next_token();
void parsering(void);
void print_token(void);
void test_symbol(token_code_t, error_code_t);
void _program();
void _identifer();
void _block();
void _consts();
void _vars();
void _insts();
void _number();



#endif // PARSER_H
