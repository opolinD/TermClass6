void just_search(int* mass, int size) {
    int desired;
    printf("������� �������: ");
    scanf_s("%d", &desired);
    for (int i = 0; i < size; i++) {
        if (mass[i] == desired) {
            printf("������� ����� �� %d ����� � �������\n", i + 1);
        }
    }
}