#include "parser.h"

bool no_error = true;
static int symbol_iterator = 0;

symbol_t new_symbol(char* name, idf_t type)
{
    symbol_t sym;
    sym.symbol_name = (char*) malloc(strlen(name)*sizeof(char));
    strcpy(sym.symbol_name, name);
    //printf("iter : %d", symbol_iterator);
    return sym;
}

bool isDeclared(char* name)
{
    int i;
    for(i = 0; i < symbol_iterator; i++)
    {
        if(!strcmp(tab_symbol[i].symbol_name, name))
        {
            printf("\nerror sm : %s is declared\n", name);
            no_error = false;
            return true;
        }
    }
    return false;
}

bool isConst(char* name)
{
    int i;
    for(i = 0; i < symbol_iterator; i++)
    {
        if(!strcmp(tab_symbol[i].symbol_name, name))
            if(tab_symbol[i].symbol_type == TCONST)
                return true;
        else return false;
    }
}

void print_token()
{
    if(current_token.code != EMPTY_TOKEN) printf("--> %s\t\t\t\t%s\n", current_token.name,  Token_code[current_token.code]);
}

void get_next_token()
{
    do{
        scaning();
    } while(current_token.code == EMPTY_TOKEN);
    //print_token();
}

void test_symbol(token_code_t code_token, error_code_t error_code)
{
    last_token = (char*) malloc(strlen(current_token.name)*sizeof(char));
    strcpy(last_token, current_token.name);
    if(current_token.code == code_token)
    {
        get_next_token();
    }
    else
    {
        print_error(error_code);
        no_error = false;
    }
}

void _program()
{
    //PROGRAM ::= program ID ; BLOCK.

    //Demarage
    setCurrent_token_NULL(); //Initialisation de token
    read_char(file);         //Lire le premier caractere
    get_next_token();        //Lire le premier token

    test_symbol(PROGRAM_TOKEN, ERROR_PROGRAM_TOKEN);
    test_symbol(ID_TOKEN, ERROR_ID_TOKEN);

    if(!isDeclared(last_token)) tab_symbol[symbol_iterator++] = new_symbol(last_token, TPROG);

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

            if(!isDeclared(last_token)) tab_symbol[symbol_iterator++] = new_symbol(last_token, TCONST);

            test_symbol(EG_TOKEN, ERROR_EG_TOKEN);
            test_symbol(NUMBER_TOKEN, ERROR_NUMBER_TOKEN);
            test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
            while(current_token.code == ID_TOKEN)
            {
                if(!isDeclared(current_token.name)) tab_symbol[symbol_iterator++] = new_symbol(current_token.name, TCONST);

                get_next_token();
                test_symbol(EG_TOKEN, ERROR_EG_TOKEN);
                test_symbol(NUMBER_TOKEN, ERROR_NUMBER_TOKEN);
                test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
            }
        break;

        case VAR_TOKEN      : break;
        case BEGIN_TOKEN    : break;
        default             : printf("\nCONSTS_ERROR\n"); break;
    }
}

void _vars()
{
    switch(current_token.code)
    {
        case VAR_TOKEN :
            get_next_token();
            test_symbol(ID_TOKEN, ERROR_ID_TOKEN);

            if(!isDeclared(last_token)) tab_symbol[symbol_iterator++] = new_symbol(last_token, TVAR);

            while(current_token.code == VIR_TOKEN)
            {
                get_next_token();
                test_symbol(ID_TOKEN, ERROR_ID_TOKEN);

                if(!isDeclared(last_token)) tab_symbol[symbol_iterator++] = new_symbol(last_token, TVAR);
            }
            test_symbol(PV_TOKEN, ERROR_PV_TOKEN);
        break;

        case BEGIN_TOKEN : break;
        default : printf("\nVARS_ERROR\n"); break;
    }
}

void _insts()
{
    test_symbol(BEGIN_TOKEN, ERROR_BEGIN_TOKEN);
    _inst();
    while(current_token.code == PV_TOKEN)
    {
        get_next_token();
        _inst();
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
        case END_TOKEN   : /*epsilon*/  break;
        default          : printf("\nINST_ERROR\n");    break;
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
    while(current_token.code == VIR_TOKEN)
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
    while(current_token.code == VIR_TOKEN)
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
       current_token.code == SUPEG_TOKEN)
    {
        get_next_token();
        _expr();
    }
}

void _expr()
{
    _term();
    while(current_token.code == PLUS_TOKEN  ||
          current_token.code == MOINS_TOKEN)
    {
        get_next_token();
        _term();
    }
}

void _term()
{
    _fact();
    while(current_token.code == MULT_TOKEN  ||
          current_token.code == DIV_TOKEN)
    {
        get_next_token();
        _fact();
    }
}

void _fact()
{
    switch(current_token.code)
    {
        case ID_TOKEN     : get_next_token();  break;
        case NUMBER_TOKEN : get_next_token();  break;
        case PO_TOKEN     :
            get_next_token();
            _expr();
            test_symbol(PF_TOKEN, ERROR_PF_TOKEN);
        break;
        default : printf("\nFACT_ERROR\n"); break;
    }
}

void parsering()
{
    _program();
    if (current_token.code == FIN_TOKEN && no_error)
        printf("\nBRAVO : le programme est correcte\n");
    else
        printf("\nPAS BRAVO : fin de programme erronee\n");
}
