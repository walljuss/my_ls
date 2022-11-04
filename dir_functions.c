#include "main_struct.h"
#include "comparing_functions.h"
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include "dirent_struct.h"
#include <stdio.h>
#include "file_struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "order_functions.h"
#include "printing_functions.h"


/* 
if more than one arguments are given in my_ls it will check the tags, particularly a and t tags => true
if other than these tags are present, the i_tag -> true;
*/

void check_tags(int argc,char** argv, main_struct* ret_struct){
    int index = 0;
    while(index<argc){
        if(  ((argv[index][0] == '-') && (argv[index][1] != 'a') && (argv[index][1] != 't'))   ){
            ret_struct->i_tag = 1;
            printf("%s\n", argv[index]);
        } 
        if(if_same(argv[index], "-a") == 1){
            ret_struct->a_tag = 1;
        }
        if(if_same(argv [index], "-t") == 1){
            ret_struct->t_tag = 1;
        }
        if ( (if_same(argv[index],"-at") == 1) || (if_same(argv[index],"-ta") == 1) ){
            ret_struct->a_tag = 1;
            ret_struct->t_tag = 1;
        }
        index++;
    }
}

/*
counts the directories which were argumented when my_ls function is used
*/
int dir_count(int argc, char** argv){
    int index = 1;
    int total = 0;
    while(index<argc){
        if(argv[index][0]!='-'){
            total++;
        }
        index++;
    }
    return total;
}

/*
gets the directory names that are being ls-ed
*/
void get_dirs(int argc,char** argv, main_struct* ret_struct){
    int index = 1;
    int arr_loc = 0;
    while(index < argc){
        if (argv[index][0]!='-'){
            ret_struct->directories[arr_loc] = strdup(argv[index]);
            arr_loc++;  
            } 
        index++;
    }
}

//return 1 if dir is accessible, 0 if not
bool if_dir_ok(char* directory){
    DIR *dir;
    dir = opendir(directory);
       
    if (dir == NULL)
    {
        closedir(dir);
        return 0;
    }
    closedir(dir);
    return 1;
}

int count_total_files(char* dir_path){
    //dir stream;
    DIR *dir;

    int total_files = 0;
    //dirent structure temporary which will read the dir stream
    Dirent *struct_dirent;

    dir = opendir(dir_path);

    if (dir == NULL)
    {
        printf("Error! Unable to open directory. \"%s\"\n", dir_path);
        return 2; //exit(1)
    }
    while( (struct_dirent=readdir(dir)) != NULL){
        total_files++;
    }
    closedir(dir);
    return total_files;
}

void free_structs(File_struct** dirs, int total_elements){
    int index = 0;
    while(index<total_elements){
        free(dirs[index]);
        index++;
    }
    free(dirs);
}

void write_to_struct(File_struct** directories, char* dir_path, int total_files){
    DIR *dir;
    dir = opendir(dir_path);
    struct stat temp_stat;
    Dirent *temp_dirent;
    int index = 0;

    //copies each files/directory name into a struct directories[index].d_name;
    while( ( temp_dirent=readdir(dir)) != NULL )
    {
        strcpy(directories[index]->d_name, temp_dirent->d_name);
        index++;
    }
    //finish
    
    //copies the tvsec and tvnsec of last modified time/since a particular time
    index = 0;
    while(index<total_files){
        if (directories[index]->d_type != 10){
            stat(directories[index]->d_name, &temp_stat);
        } else {
            lstat(directories[index]->d_name, &temp_stat);
            
        };
        directories[index]->st_mtim.tv_sec = temp_stat.st_mtim.tv_sec;
        directories[index]->st_mtim.tv_nsec = temp_stat.st_mtim.tv_nsec;
        index++;
    }
    closedir(dir);
}


int main_ls(main_struct* structure, char* dir){
    int total_files = count_total_files(dir);
    int index = 0;
    File_struct** directories = malloc(sizeof(File_struct*)*total_files);
    while(index<total_files){
        directories[index] = malloc(sizeof(File_struct));
        index++;
    }
    write_to_struct(directories,dir,total_files);
    if ( (structure->a_tag == 1) && (structure->t_tag == 1) ){
        order_lexico(directories, total_files);
        order_time(directories, total_files);
        print_with_a(directories,total_files);
    } else if (structure->a_tag == 1){
        order_lexico(directories, total_files);
        print_with_a(directories,total_files);
    } else if (structure->t_tag == 1) {
        order_time(directories, total_files);
        print_without_a(directories, total_files);
    // else if (structure->a_tag == -1) { //when no arguments are given
    //     print_without_options(directories, total_files);
    } else {
        print_without_a(directories,total_files);
    }
    free_structs(directories, total_files);
    return 1;
}










