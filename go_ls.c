#include <string.h>
#include "main_struct.h"
#include "file_struct.h"
#include "printing_functions.h"
#include "dir_functions.h"
#include <stdio.h>

void go_ls(main_struct* structure, int* ret_value){
    
    int index;
    int last = structure->arr_size;
    int print_last = last;
    
    index = structure->arr_size - 1;
    //print out the wrong directories first
    while(index >= 0){
        print_wrong_directs(structure->directories[index], &last);
         if ((print_last != last) && (last != 0)){
            printf("\n");
            print_last = last;
        }
        index--;
    };


    index = structure->arr_size - 1;
    while(index >= 0){
        print_non_directs(structure->directories[index], &last);
        if ((print_last != last) && (last != 0)){
            printf("\n");
            print_last = last;
        }
    
        index--;
    }

    


  
    index = structure->arr_size - 1;
    while(index >= 0){
        if (if_dir_ok(structure->directories[index]) == 1){
            printf("%s:\n", structure->directories[index]);
            last--;
        *ret_value = main_ls(structure,structure->directories[index]);
            if(last != 0){
            printf("\n\n");
            } else {
            printf("\n");
            }    
        }
        index--;
    }
}

