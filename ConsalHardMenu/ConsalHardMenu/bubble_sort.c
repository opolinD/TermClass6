void bubble_sort(int* mass, int size, int* count_swap, int* count_comp) {
    *count_swap = 0;
    *count_comp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            (*count_comp)++;
            if (mass[i] < mass[j]) {
                int cas = mass[i];
                mass[i] = mass[j];
                mass[j] = cas;
                (*count_swap)++;
            }
        }
    }
}