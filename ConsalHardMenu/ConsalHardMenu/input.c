#include<stdio.h>
#include <malloc.h>
int* input(char* filepath, int* mass, int size, int* new_size, FILE* input_file) {
    *new_size = 0;
    mass = NULL;
    errno_t error;
    error = fopen_s(&input_file, filepath, "r+");
    if (input_file == NULL) {
        printf("Error in input file. Error %d\n", error);
    }
    else {
        fscanf_s(input_file, "%d", &size);
        mass = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            if (fscanf_s(input_file, "%d", &mass[i]) != 1) {
                printf("Error\n");
                return 0;
            }
        }
        fclose(input_file);
    }
    *new_size = size;
    return mass;
}