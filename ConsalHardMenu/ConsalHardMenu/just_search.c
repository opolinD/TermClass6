void just_search(int* mass, int size) {
    int desired;
    printf("¬ведите искомое: ");
    scanf_s("%d", &desired);
    for (int i = 0; i < size; i++) {
        if (mass[i] == desired) {
            printf("»скомое число на %d месте в массиве\n", i + 1);
        }
    }
}