#include "parser.h"

void print_token()
{
    if(current_token.code != EMPTY_TOKEN) printf("\n%s\t\t\t%d", current_token.name, current_token.code);
}

void parsering()
{
    while(current_char != EOF)
    {
        scaning();
        print_token();
    }
}
