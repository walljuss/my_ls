#include <string.h>
#include "comparing_functions.h"
#include <stdbool.h>

//returns true/1 if the first char comes first lexiographically-or they are identical, returns false otherwise
bool compare_strs(char* a, char* b){
    int i = 0;
    while( a[i] != '\0'  ){
        if(b[i] == '\0'){
            return 0;
        }
        if(a[i] > b[i]){
            return 0;
        } else if (a[i] == b[i]){
            i++;
            continue;
        } else {
            return 1;
        }
    i++;
    }
    return 1;
}


bool if_same(char* a, char* b){
    if (strlen(a) != strlen(b)){
        return 0;
    }
    int i = 0;
    while(a[i] != '\0'){
        if (a[i] != b[i]){
            return 0;
        }
        i++;
    }
    return 1;
}


bool if_space(char* d){
    size_t i = 0;
    while(i<strlen(d)){
        if(d[i] == ' '){
            return 1;
        }
        i++;
    }
    return 0;
}
