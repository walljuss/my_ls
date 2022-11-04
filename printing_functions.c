#include <stdio.h>
#include "file_struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include "comparing_functions.h"


//checks if the directory exists, if not the prints out invalid directory
void print_wrong_directs(char* directory, int* order){
    DIR *dir;
    dir = opendir(directory);
    
   
    if (errno == ENOENT)
    {
        printf("%s: Invalid directory\n", directory);
        *order-=1;
    }
   
    closedir(dir);
}

//prints out the non-directory only
void print_non_directs(char* directory, int* order){
    DIR *dir;
    dir = opendir(directory);
    
   
if (errno == ENOTDIR)
    {
        printf("%s\n", directory);
        *order-=1;
    }
   
    closedir(dir);

}



void print_with_a(File_struct** dirs, int total_elements){
    int index = 0;
    while(index<total_elements) 
    {
                    if(if_space(dirs[index]->d_name) == 1){
                        printf("'");
                        printf("%s", dirs[index]->d_name);
                        printf("'  ");
                    } else {
                        printf("%s  ", dirs[index]->d_name);
                    }
                index++;
    }
}

void print_without_a(File_struct** dirs, int total_elements){
    int index = 0;
    while(index<total_elements)
            {
                if (dirs[index]->d_name[0]!='.')
                {
                if (if_space(dirs[index]->d_name) == 1){
                        printf("'");
                        printf("%s", dirs[index]->d_name);
                        printf("'  ");
                    } else {
                        printf("%s  ", dirs[index]->d_name);
                }
                   
                }
                index++;
            }
}

void print_without_options(File_struct** dirs, int total_elements){
    int index = 0;
    while(index<total_elements){
        if (dirs[index]->d_name[0]!='.'){
            if(if_space(dirs[index]->d_name) == 1){
                        printf("'");
                        printf("%s", dirs[index]->d_name);
                        printf("'  ");
                    } else {
                        printf("%s  ", dirs[index]->d_name);
                    }
        }
        index++;
    }
}