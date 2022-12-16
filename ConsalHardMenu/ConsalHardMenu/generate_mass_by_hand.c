void generate_mass_by_hand(int* mass, int* first_mass, int size) {
    printf("¬ведите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &mass[i]);
    }
    for (int i = 0; i < size; i++) {
        first_mass[i] = mass[i];
    }
}