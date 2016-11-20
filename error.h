#ifndef ERROR_H
#define ERROR_H

static int error_iterator;

typedef enum _sm_error {
    DEJA_DECLAREE,
    MAL_INITIALISEE
} sm_error_t;

typedef struct _sm_error_list {
    char* id_name;
    int   ligne;
    sm_error_t error_type;
} sm_error_list;

sm_error_list error_list[10];

void add_sm_error(sm_error_t, int, char*);
void print_sm_error();
int  get_sm_error_number();

#endif // ERROR_H
