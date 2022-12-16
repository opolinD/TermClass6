void shell_sort(int* mass, int size, int* count_swap, int* count_comp) {
    *count_swap = 0;
    *count_comp = 0;
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2) {
        for (i = step; i < size; i++) {
            tmp = mass[i];
            for (j = i; j >= step; j -= step) {
                (*count_comp)++;
                if (tmp < mass[j - step]) {
                    mass[j] = mass[j - step];
                    (*count_swap)++;
                }
                else {
                    break;
                }
            }
            mass[j] = tmp;
        }
    }
}