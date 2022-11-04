#include "file_struct.h"

#ifndef ORDER_FUNCTIONS
#define ORDER_FUNCTIONS

void order_time(File_struct** struct_array, int number_el);
void order_lexico(File_struct** struct_array, int number_el);
void replace_struct(File_struct* first, File_struct* second);

#endif //ORDER_FUNCTIONS