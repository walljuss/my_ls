#include <stdbool.h>

#ifndef MAIN_STRUCT
#define MAIN_STRUCT

typedef struct options {
    bool a_tag;
    bool t_tag;
    bool i_tag;
    int arr_size;
    char **directories;
} main_struct;

#endif //MAIN_STRUCT