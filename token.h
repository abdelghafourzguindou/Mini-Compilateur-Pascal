#ifndef KEYWORD_H
#define KEYWORD_H

#include <string.h>

#define MAX_KEY_WORD 11
#define MAX_SPECIAL_CARACTER 16

typedef enum {
    PROGRAM_TOKEN,
    CONST_TOKEN,
    VAR_TOKEN,
    BEGIN_TOKEN,
    END_TOKEN,
    IF_TOKEN,
    THEN_TOKEN,
    WHILE_TOKEN,
    DO_TOKEN,
    READ_TOKEN,
    WRITE_TOKEN,
    PV_TOKEN,
    PT_TOKEN,
    PLUS_TOKEN,
    MOINS_TOKEN,
    MULT_TOKEN,
    DIV_TOKEN,
    VIR_TOKEN,
    EG_TOKEN,
    AFF_TOKEN,
    INF_TOKEN,
    INFEG_TOKEN,
    SUP_TOKEN,
    SUPEG_TOKEN,
    DIFF_TOKEN,
    PO_TOKEN,
    PF_TOKEN,
    FIN_TOKEN,
    NUMBER,
    IDENTIFIER,
    END_EOF,
    EMPTY_TOKEN,
    ERROR_TOKEN
}token_code_t;

token_code_t IsKeyWord(char*);
token_code_t isSpeacialSymbol(char*);


#endif // KEYWORD_H
