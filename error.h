#ifndef ERROR_H
#define ERROR_H

#include "token.h"

static int error_iterator;
extern int ligne_number;

char* Error_code[SIZE_TOKEN];

typedef enum _sm_error {
    DEJA_DECLAREE,
    MAL_INITIALISEE
} sm_error_t;

typedef struct _sm_error_list {
    char* id_name;
    int   ligne;
    sm_error_t error_type;
} sm_error_list;

sm_error_list error_list[100];

typedef enum {
     ERROR_INDEFINED_TOKEN,
     ERROR_COMMENT_INCOMPLET ,
     ERROR_PROGRAM_TOKEN,
     ERROR_CONST_TOKEN,
     ERROR_VAR_TOKEN,
     ERROR_BEGIN_TOKEN,
     ERROR_END_TOKEN,
     ERROR_IF_TOKEN,
     ERROR_THEN_TOKEN,
     ERROR_WHILE_TOKEN,
     ERROR_DO_TOKEN,
     ERROR_READ_TOKEN,
     ERROR_WRITE_TOKEN,
     ERROR_PV_TOKEN,
     ERROR_PT_TOKEN,
     ERROR_PLUS_TOKEN,
     ERROR_MOINS_TOKEN,
     ERROR_MULT_TOKEN,
     ERROR_DIV_TOKEN,
     ERROR_VIR_TOKEN,
     ERROR_EG_TOKEN,
     ERROR_AFF_TOKEN,
     ERROR_INF_TOKEN,
     ERROR_INFEG_TOKEN,
     ERROR_SUP_TOKEN,
     ERROR_SUPEG_TOKEN,
     ERROR_DIFF_TOKEN,
     ERROR_PO_TOKEN,
     ERROR_PF_TOKEN,
     ERROR_FIN_TOKEN,
     ERROR_NUMBER_TOKEN,
     ERROR_ID_TOKEN,
} error_code_t;

void print_error(error_code_t);
void print_sm_error(char*,int, char*);
/*void add_sm_error(sm_error_t, int, char*);
void print_sm_error();
int  get_sm_error_number();*/

#endif // ERROR_H
