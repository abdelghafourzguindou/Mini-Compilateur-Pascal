#include "token.h"

token_code_t IsKeyWord(char* kword)
{
    //char *kword = cutToken(word, ptrs, ptrf);
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
    //char *kword = cutToken(symbol, ptrs, ptrf);
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
