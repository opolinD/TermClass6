void generate_mass_auto(int* mass, int* first_mass, int size) {
    int min, max;
    printf("������� ����������� �������� �������: ");
    scanf_s("%d", &min);
    printf("������� ������������ �������� �������: ");
    scanf_s("%d", &max);
    for (int i = 0; i < size; i++) {
        mass[i] = min + rand() % (max - min + 1);
        first_mass[i] = mass[i];
    }
}