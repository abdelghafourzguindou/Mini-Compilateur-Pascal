#include "error.h"

static int error_iterator = 0;

char* Error_code[SIZE_TOKEN] =
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

void print_error(error_code_t error)
{
    printf("\n\nerror ligne %d : %s\n\n", ligne_number, Error_code[error]);
}

void print_sm_error(char* name, int row, char* error)
{
    printf("sm_error : %s in row %d is %s\n", name, row, error);
}

/*
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
*/
