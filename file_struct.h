#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

typedef struct {
    char d_name[256];
    unsigned char d_type;
    struct timespec st_mtim;
} File_struct;

#endif