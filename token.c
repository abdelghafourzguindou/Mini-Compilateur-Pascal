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

token_code_t isSpeacialSymbol(char* kword)
{
    token_code_t token;

    if     (!strcmp(kword, ";"))        token = PV_TOKEN;
    else if(!strcmp(kword, "."))        token = PT_TOKEN;
    else if(!strcmp(kword, "+"))        token = PLUS_TOKEN;
    else if(!strcmp(kword, "-"))        token = MOINS_TOKEN;
    else if(!strcmp(kword, "*"))        token = MULT_TOKEN;
    else if(!strcmp(kword, "/"))        token = DIV_TOKEN;
    else if(!strcmp(kword, ","))        token = VIR_TOKEN;
    else if(!strcmp(kword, "="))        token = EG_TOKEN;
    else if(!strcmp(kword, ":="))       token = AFF_TOKEN;
    else if(!strcmp(kword, "<"))        token = INF_TOKEN;
    else if(!strcmp(kword, "<="))       token = INFEG_TOKEN;
    else if(!strcmp(kword, ">"))        token = SUP_TOKEN;
    else if(!strcmp(kword, ">="))       token = SUPEG_TOKEN;
    else if(!strcmp(kword, "<>"))       token = DIFF_TOKEN;
    else if(!strcmp(kword, "("))        token = PO_TOKEN;
    else if(!strcmp(kword, ")"))        token = PF_TOKEN;
    else                                token = ERROR_TOKEN;

    return token;
}

char* Token_code[32] =
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
} ;

char* Error_code[32] =
{
    "ERROR_INDEFINED_TOKEN",
    "ERROR_COMMENT_INCOMPLET" ,
    "ERROR_PROGRAM_TOKEN",
    "ERROR_CONST_TOKEN",
    "ERROR_VAR_TOKEN",
    "ERROR_BEGIN_TOKEN",
    "ERROR_END_TOKEN",
    "ERROR_IF_TOKEN",
    "ERROR_THEN_TOKEN",
    "ERROR_WHILE_TOKEN",
    "ERROR_DO_TOKEN",
    "ERROR_READ_TOKEN",
    "ERROR_WRITE_TOKEN",
    "ERROR_PV_TOKEN",
    "ERROR_PT_TOKEN",
    "ERROR_PLUS_TOKEN",
    "ERROR_MOINS_TOKEN",
    "ERROR_MULT_TOKEN",
    "ERROR_DIV_TOKEN",
    "ERROR_VIR_TOKEN",
    "ERROR_EG_TOKEN",
    "ERROR_AFF_TOKEN",
    "ERROR_INF_TOKEN",
    "ERROR_INFEG_TOKEN",
    "ERROR_SUP_TOKEN",
    "ERROR_SUPEG_TOKEN",
    "ERROR_DIFF_TOKEN",
    "ERROR_PO_TOKEN",
    "ERROR_PF_TOKEN",
    "ERROR_FIN_TOKEN",
    "ERROR_NUMBER_TOKEN",
    "ERROR_ID_TOKEN"
};
