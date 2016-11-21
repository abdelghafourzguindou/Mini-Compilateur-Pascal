#ifndef PARSER_H
#define PARSER_H

#include "scaner.h"

#define MAX_ERROR 100

bool no_error;
static int symbol_iterator;
token_t last_token;

//sm traitement
typedef enum
{
    TPROG,
    TCONST,
    TVAR
} idf_t;

typedef struct _sym
{
    char* symbol_name;
    idf_t symbol_type;
} symbol_t;

symbol_t tab_symbol[MAX_ERROR];

bool isDeclared(char*);
bool isConst(char*);
void add_symbol(sym_t);
symbol_t new_symbol(char*, idf_t);

void get_next_token();
void parsering(void);
void print_token();
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
