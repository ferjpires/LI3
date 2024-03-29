#include "utils/output.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *create_output_path(int line){
    // creating file name
    char *path = malloc(50 * sizeof(char));
    char stringLine[10];
    sprintf(stringLine, "%d", line);

    strcpy(path,"Resultados/command");
    strcat(path,stringLine);
    strcat(path,"_output.txt");

    return path;
}

char *create_test_output_path(int line){
    // creating file name
    char *path = malloc(50 * sizeof(char));
    char stringLine[10];
    sprintf(stringLine, "%d", line);

    strcpy(path,"command");
    strcat(path,stringLine);
    strcat(path,"_output.txt");

    return path;
}