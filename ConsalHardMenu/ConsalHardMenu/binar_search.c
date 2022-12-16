void binar_search(int* mass, int size) {
    int left, right, middle, val, pos_of_elem = -1, sort_flag = 1;
    for (int i = 1; i < size; i++) {
        if (mass[i - 1] > mass[i]) {
            sort_flag = 0;
        }
    }
    if (sort_flag == 1) {
        printf("Введите искомый элемент: ");
        scanf_s("%d", &val);
        left = 0;
        right = size - 1;
        while (left < right)
        {
            middle = (left + right) / 2;
            if (val < mass[middle]) {
                right = middle - 1;
            }
            else if (val > mass[middle]) {
                left = middle + 1;
            }
            else {
                pos_of_elem = middle + 1;
                printf("Искомый элемент на %d месте", pos_of_elem);
                break;
            }
        }
        if (pos_of_elem == -1) {
            printf("Искомый элемент не найден");
        }
    }
    else {
        //исключение
    }
}