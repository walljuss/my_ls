#include "main_struct.h"
#include "comparing_functions.h"
#include "file_struct.h"

void replace_struct(File_struct* first, File_struct* second){
    File_struct temp;
    temp = *second;
    *second = *first;
    *first = temp;
}



void order_time(File_struct** struct_array, int number_el){
    int ite_1 = 0;
    int arr_loc = 0;
    while(ite_1<number_el){
        while(arr_loc<(number_el-1)){
            if ( struct_array[arr_loc]->st_mtim.tv_sec == struct_array[arr_loc+1]->st_mtim.tv_sec )
            {
                if (struct_array[arr_loc]->st_mtim.tv_nsec > struct_array[arr_loc+1]->st_mtim.tv_nsec ){
                    arr_loc++;
                    continue;
                } else if (struct_array[arr_loc]->st_mtim.tv_nsec == struct_array[arr_loc+1]->st_mtim.tv_nsec){
                    if (compare_strs(struct_array[arr_loc]->d_name, struct_array[arr_loc+1]->d_name) == 1){
                        arr_loc++;
                        continue;
                    } else {
                        replace_struct(struct_array[arr_loc], struct_array[arr_loc+1]);
                    }
                } else {
                    replace_struct(struct_array[arr_loc], struct_array[arr_loc+1]);
                }
            } else if (struct_array[arr_loc]->st_mtim.tv_sec > struct_array[arr_loc+1]->st_mtim.tv_sec)
            {   
               arr_loc++;
               continue;
            } else {
                replace_struct(struct_array[arr_loc], struct_array[arr_loc+1]);
            }
            arr_loc++;
        }
        arr_loc=0;
        ite_1++;
    }
}




void order_lexico(File_struct** struct_array, int number_el){
    int ite_1 = 0;
    int arr_loc = 0;
    
     while(ite_1<number_el)
    {
        while( arr_loc < (number_el-1) ) 
        {  
         if ( compare_strs(struct_array[arr_loc]->d_name, struct_array[arr_loc+1]->d_name) == 1){
             arr_loc++;
             continue;
         } else {
             replace_struct(struct_array[arr_loc], struct_array[arr_loc+1]);
         }
         arr_loc++;
        }
        arr_loc = 0;
        ite_1++;
    }

};

