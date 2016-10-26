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
    test_symbol(PROGRAM_TOKEN, ERROR_PROGRAM_TOKEN);
    test_symbol(ID_TOKEN, ERROR_ID_TOKEN);
    test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
    _block();
    test_symbol(PT_TOKEN, ERROR_PT_TOKEN);
}

void _identifer()
{

}

void _block()
{

}

void _consts()
{

}

void _vars()
{

}

void _insts()
{

}

void _number()
{

}


void parsering()
{
    while(current_char != EOF)
    {
        get_next_token();
        print_token();
    }
}
