#include "parser.h"

void print_token()
{
    if(current_token.code != EMPTY_TOKEN) printf("\n%s\t\t\t%d", current_token.name, current_token.code);
}

void get_next_token()
{
    scaning();
}

void test_symbol(token_code_t code_token, error_code_t error_code)
{
    if(current_token.code == code_token) get_next_token();
    //else ERROR(error_code);
}

void _program()
{
    //PROGRAM ::= program ID ; BLOCK.
    test_symbol(PROGRAM_TOKEN, ERROR_PROGRAM_TOKEN);
    test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
    test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
    _block();
    test_symbol(PT_TOKEN, ERROR_PT_TOKEN);
}

void _block()
{
    //BLOCK ::= CONSTS VARS INSTS
    _consts();
    _vars();
    _insts();
}

void _consts()
{
    switch(current_token.code)
    {
        case CONST_TOKEN    :
            get_next_token();
            test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
            test_symbol(EG_TOKEN, ERROR_EG_TOKEN);
            test_symbol(NUMBER_TOKEN, ERROR_NUMBER_TOKEN);
            test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
            while(current_token.code == ID_TOKEN)
            {
                get_next_token();
                test_symbol(EG_TOKEN, ERROR_EG_TOKEN);
                test_symbol(NUMBER_TOKEN, ERROR_NUMBER_TOKEN);
                test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
            }
        break;

        case VAR_TOKEN      : break;
        case BEGIN_TOKEN    : break;
        default             : /*error(CONST_VAR_BEGIN_ERR);*/ break;
    }
}

void _vars()
{
    switch(current_token.code)
    {
        case VAR_TOKEN :
            get_next_token();
            test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
            test_symbol(VIR_TOKEN, ERROR_VIR_TOKEN);
            while(current_token.code == ID_TOKEN)
            {
                get_next_token();
                test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
                test_symbol(VIR_TOKEN, ERROR_VIR_TOKEN);
            }
            test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
        break;

        case BEGIN_TOKEN : break;
        default : /*error();*/ break;
    }
}

void _insts()
{
    test_symbol(BEGIN_TOKEN, ERROR_BEGIN_TOKEN);
    _inst();
    test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
    while(current_token.code == PV_TOKEN)
    {
        test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
    }
    test_symbol(END_TOKEN, ERROR_END_TOKEN);
}

void _inst()
{
    switch(current_token.code)
    {
        case BEGIN_TOKEN : _insts();    break;
        case ID_TOKEN    : _affect();   break;
        case IF_TOKEN    : _if();       break;
        case WHILE_TOKEN : _while();    break;
        case WRITE_TOKEN : _write();    break;
        case READ_TOKEN  : _read();     break;
        case PV_TOKEN    : /*epsiland*/ break;
        default          : /*error*/    break;
    }
}

void _affect()
{
    test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
    test_symbol(AFF_TOKEN, ERROR_AFF_TOKEN);
    _expr();
}

void _if()
{
    test_symbol(IF_TOKEN, ERROR_IF_TOKEN);
    _cond();
    test_symbol(THEN_TOKEN, ERROR_THEN_TOKEN);
    _inst();
}

void _while()
{
    test_symbol(WHILE_TOKEN, ERROR_WHILE_TOKEN);
    _cond();
    test_symbol(DO_TOKEN, ERROR_DO_TOKEN);
    _inst();
}

void _write()
{
    test_symbol(WRITE_TOKEN, ERROR_WRITE_TOKEN);
    test_symbol(PO_TOKEN, ERROR_PO_TOKEN);
    _expr();
    while(current_token.code == PV_TOKEN)
    {
        _expr();
    }
    test_symbol(PF_TOKEN, ERROR_PF_TOKEN);
}

void _read()
{
    test_symbol(READ_TOKEN, ERROR_READ_TOKEN);
    test_symbol(PO_TOKEN, ERROR_PO_TOKEN);
    test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
    while(current_token.code == PV_TOKEN)
    {
        test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
    }
    test_symbol(PF_TOKEN, ERROR_PF_TOKEN);
}

void _cond()
{
    _expr();
    if(current_token.code == EG_TOKEN    ||
       current_token.code == DIFF_TOKEN  ||
       current_token.code == INF_TOKEN   ||
       current_token.code == SUP_TOKEN   ||
       current_token.code == INFEG_TOKEN ||
       current_token.code == SUPEG_TOKEN) _expr();
    else{/*error*/}
}

void _expr()
{
    _term();
    if(current_token.code == PLUS_TOKEN  ||
       current_token.code == MOINS_TOKEN) _term();
    else{/*error*/}
}

void _term()
{
    _fact();
    if(current_token.code == MULT_TOKEN  ||
       current_token.code == DIV_TOKEN) _fact();
    else{/*error*/}
}

void _fact()
{
    switch(current_token.code)
    {
        case ID_TOKEN     : test_symbol(ID_TOKEN, ERROR_ID_TOKEN);          break;
        case NUMBER_TOKEN : test_symbol(NUMBER_TOKEN, ERROR_NUMBER_TOKEN);  break;
        case PO_TOKEN     :
            get_next_token();
            _expr();
            test_symbol(PF_TOKEN, ERROR_PF_TOKEN);
        break;
        default : /*error*/ break;
    }
}

void parsering()
{
    while(current_char != EOF)
    {
        //_program();
        scaning();
        print_token();


    }
}
