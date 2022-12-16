#include<stdio.h>
void print_mass(int* mass, int size, char* filepath, char* filename, char* dir, FILE* output_file) {
    if (size < 21) {
        for (int i = 0; i < size; i++) {
            printf("%d ", mass[i]);
        }
        printf("\n");
    }
    else {
        //גûגמה ג פאיכ
        errno_t error1;
        error1 = fopen_s(&output_file, filepath, "w+");
        fprintf(output_file, "%d\n", size);
        for (int i = 0; i < size; i++) {
            fprintf(output_file, "%d ", mass[i]);
        }
        fclose(output_file);
    }
}