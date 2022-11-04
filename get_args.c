#include "dir_functions.h"
#include "main_struct.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void get_args(int argc, char** argv, main_struct* structure){
    
        structure->a_tag = 0;
        structure->t_tag = 0;
        structure->i_tag = 0;

    if (argc == 1){
        
        structure->directories = malloc(sizeof(char*));
        structure->directories[0] = strdup(".");
        structure->arr_size = 1;
    } else {
        
        check_tags(argc, argv, structure);
        /*
        if directory names are not argumented in the given ls function
        then directory being printed is switched to current one .
        */
        if (dir_count(argc, argv) == 0){
            structure->directories = malloc(sizeof(char*));
            structure->directories[0] = strdup(".");
            structure->arr_size = 1;
        } else {
            structure->arr_size = dir_count(argc, argv);
            structure->directories = malloc(sizeof(char*)*structure->arr_size);
            get_dirs(argc, argv, structure);

        }
    }
}

 