#include <stdio.h>
#include <stdlib.h>

#include "parser.h"


int main()
{

    /*scaning();
    print_lex();*/

    file = fopen(nameFile, "r");

    if(file == NULL)
    {
        printf("ERROR FILE");
        exit(0);
    }

    parsering();




    printf("\n");
    system("PAUSE>null");
    return 0;
}
