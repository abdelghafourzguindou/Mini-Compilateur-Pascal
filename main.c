#include <stdio.h>
#include <stdlib.h>

#include "parser.h"


int main()
{

    file = fopen("test_pascal.p", "r");

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
