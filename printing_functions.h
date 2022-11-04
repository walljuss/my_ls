#include "file_struct.h"

#ifndef PRINTING_FUNCTIONS_H
#define PRINTING_FUNCTIONS_H

void print_wrong_directs(char* dir, int* order);

void print_non_directs(char* dir, int* order);

void print_with_a(File_struct** dirs, int total_elements);

void print_without_a(File_struct** dirs, int total_elements);

void print_without_options(File_struct** dirs, int total_elements);


#endif