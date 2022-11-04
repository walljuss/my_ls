#include "main_struct.h"
#include <stdbool.h>
#include "file_struct.h"




#ifndef DIR_FUNCTIONS_H
#define DIR_FUNCTIONS_H


void check_tags(int agc, char** argv, main_struct* ret_struct);

int dir_count(int argc, char** argv);

void get_dirs(int argc,char** argv, main_struct* ret_struct);

bool if_dir_ok(char* dir);

int main_ls(main_struct* structure, char* dir);

void write_to_struct(File_struct** directories, char* dir_path, int total_files);

int count_total_files(char* dir_path);

void free_structs(File_struct** dirs, int total_elements);

#endif // DIR_FUNCTIONS_H