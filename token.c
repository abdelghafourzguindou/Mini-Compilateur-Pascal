#include "token.h"

token_code_t IsKeyWord(char* kword)
{
    token_code_t token;

    if     (!strcmp(kword, "program"))  token = PROGRAM_TOKEN;
    else if(!strcmp(kword, "const"))    token = CONST_TOKEN;
    else if(!strcmp(kword, "var"))      token = VAR_TOKEN;
    else if(!strcmp(kword, "begin"))    token = BEGIN_TOKEN;
    else if(!strcmp(kword, "end"))      token = END_TOKEN;
    else if(!strcmp(kword, "if"))       token = IF_TOKEN;
    else if(!strcmp(kword, "then"))     token = THEN_TOKEN;
    else if(!strcmp(kword, "while"))    token = WHILE_TOKEN;
    else if(!strcmp(kword, "do"))       token = DO_TOKEN;
    else if(!strcmp(kword, "read"))     token = READ_TOKEN;
    else if(!strcmp(kword, "write"))    token = WRITE_TOKEN;
    else                                token = ERROR_TOKEN;

    return token;
}

char* Token_code[SIZE_TOKEN] =
{
    "PROGRAM_TOKEN",
    "CONST_TOKEN",
    "VAR_TOKEN",
    "BEGIN_TOKEN",
    "END_TOKEN",
    "IF_TOKEN",
    "THEN_TOKEN",
    "WHILE_TOKEN",
    "DO_TOKEN",
    "READ_TOKEN",
    "WRITE_TOKEN",
    "PV_TOKEN",
    "PT_TOKEN",
    "PLUS_TOKEN",
    "MOINS_TOKEN",
    "MULT_TOKEN",
    "DIV_TOKEN",
    "VIR_TOKEN",
    "EG_TOKEN",
    "AFF_TOKEN",
    "INF_TOKEN",
    "INFEG_TOKEN",
    "SUP_TOKEN",
    "SUPEG_TOKEN",
    "DIFF_TOKEN",
    "PO_TOKEN",
    "PF_TOKEN",
    "FIN_TOKEN",
    "NUMBER_TOKEN",
    "ID_TOKEN",
    "EMPTY_TOKEN",
    "ERROR_TOKEN"
};
