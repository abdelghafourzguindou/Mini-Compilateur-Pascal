#ifndef PARSER_H
#define PARSER_H

#include "scaner.h"

extern token_t current_token;
extern char    current_char;
extern void    scaning();

void get_next_token();
void parsering(void);
void print_token(void);
void test_symbol(token_code_t, error_code_t);
void _program();
void _block();
void _consts();
void _vars();
void _insts();
void _inst();
void _affect();
void _if();
void _while();
void _write();
void _read();
void _cond();
void _expr();
void _term();
void _fact();


#endif // PARSER_H
