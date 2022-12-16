#include<malloc.h>
void counting_sort(int* mass, int size, int* count_swap, int* count_comp) {
    *count_swap = 0;
    *count_comp = 0;
    int min = mass[0], max = mass[0];
    for (int i = 0; i < size; i++) {
        (*count_comp)++;
        if (mass[i] < min) {
            min = mass[i];
        }
        else if (mass[i] > max) {
            max = mass[i];
        }
    }
    int size_of_c = max - min + 1;
    int* counter = (int*)malloc(sizeof(int) * size_of_c);
    for (int i = 0; i < size_of_c; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        counter[mass[i] - min]++;
    }
    int k = 0;
    for (int i = 0; i < size_of_c; i++) {
        while (counter[i] > 0) {
            mass[k++] = min + i;
            counter[i]--;
        }
    }
    free(counter);
}