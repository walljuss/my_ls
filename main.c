#include "main_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include "get_args.h"
#include "go_ls.h"
#include "printing_functions.h"

int main(int argc, char** argv){
    
    main_struct* arguments = malloc(sizeof(main_struct));
  

    int ret_value;
    get_args(argc, argv, arguments);
    if(arguments->i_tag == 1){
        printf("Please provide a valid tag\n");
    }
    else 
    {
     go_ls(arguments, &ret_value);
    }
        
    int index = 0;
    while(index<arguments->arr_size){  
        free(arguments->directories[index]);
        index++;
    }
    free(arguments->directories);
    free(arguments);
    

  
    return ret_value;
}

// typedef struct options {
//     bool a_tag;
//     bool t_tag;
//     bool i_tag;
//     int arr_size;
//     char **directories;
// } main_struct;