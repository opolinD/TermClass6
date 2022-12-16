void insertion_sort(int* mass, int size, int* count_swap, int* count_comp) {
    *count_swap = 0;
    *count_comp = 0;
    int new_el, pos_of_elem;
    for (int i = 1; i < size; i++) {
        pos_of_elem = i - 1;
        new_el = mass[i];
        (*count_comp)++;
        while (mass[pos_of_elem] > new_el && pos_of_elem >= 0) {
            mass[pos_of_elem + 1] = mass[pos_of_elem];
            pos_of_elem--;
            (*count_swap)++;
        }
        mass[pos_of_elem + 1] = new_el;
    }
}