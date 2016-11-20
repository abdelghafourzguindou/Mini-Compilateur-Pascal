#include "error.h"

static int error_iterator = 0;

void add_sm_error(sm_error_t this_error, int ligne_number, char* _name)
{
    sm_error_list new_error;
    new_error.error_type    = this_error;
    new_error.id_name       = _name;
    new_error.ligne         = ligne_number;

    if(error_iterator <= 10) error_list[error_iterator++] = new_error;
}

void print_sm_error()
{
    int i;
    for(i = 0; i < error_iterator; i++)
    {
        printf("error ligne %d : %s is %d", error_list[i].ligne, error_list[i].id_name, error_list[i].error_type);
    }
}

int  get_sm_error_number()
{
    return error_iterator;
}
