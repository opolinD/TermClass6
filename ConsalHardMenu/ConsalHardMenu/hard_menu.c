// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include<malloc.h>

// управл¤ющие консолью библиотеки
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3
#define MENU_SIZE1 3
#define MENU_SIZE2 3
#define MENU_SIZE3 2
#define MENU_SIZE4 3


// основные ключи, которые могут пригодитьс¤

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

//функции
void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
    // объявление переменных
    int iKey; // переменная для фиксации нажатой клавиши
    COORD cursorPos; // управление положением курсора, чтобы менять выводимый текст
    // инициализация (заполнение значениями) переменных
    *choose_pos = 0;
    /* 1. вывод меню с переключением */
    // сброс консоли в стартовое положение
    system("cls");
    iKey = 67;
    cursorPos = (COORD){ 0, 0 };
    SetConsoleCursorPosition(hStdOut, cursorPos);
    // контроль нажатия клавиш
    while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
        switch (iKey) {
        case KEY_ARROW_UP:
            (*choose_pos)--;
            break;
        case KEY_ARROW_DOWN:
            (*choose_pos)++;
            break;
        }
        system("cls");
        // зацикливание перелистывания меню
        if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
        if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
        for (int i = 0; i < menu_size; i++) {
            cursorPos = (COORD){ 3, i };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("%s \n", menu_names[i]);
        }
        // обозначение выбранной позиции
        cursorPos = (COORD){ 0, *choose_pos };
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf("<<", iKey);
        cursorPos = (COORD){ strlen(menu_names[*choose_pos]) + 3 + 1, *choose_pos };
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf(">>");
        // ожидание нового нажатия клавиши
        iKey = _getch();
    }
}
void generate_mass(int * mass, int size) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &mass[i]);
    }
}
void print_mass(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", mass[i]);
    }
}
void just_search(int*mass, int size) {
    int desired;
    printf("Введите искомое: ");
    scanf_s("%d", &desired);
    for (int i = 0; i < size; i++) {
        if (mass[i] == desired) {
            printf("Искомое число на %d месте в массиве\n", i + 1);
        }
    }
}
void binar_search(int* mass, int size) {
    int left, right, middle, val;
    printf("Введите искомый элемент: ");
    scanf_s("%d", &val);
    left = 0;
    right =size - 1;
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
            printf("Искомый элемент на %d месте\n",middle);
        }
    }
    printf("Искомый элмент не найден(.");
}
void bubble_sort(int* mass, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (mass[i] < mass[j]) {
                int cas = mass[i];
                mass[i] = mass[j];
                mass[j] = cas;
            }
       }
    }
}




// объ¤вление главной функции
int main() {
    // настройки

    // задаЄм название консольного окна
    system("title Application");

    // устанавливаем взаимодействие с русскими буквами
    SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

    // получаем дескриптор окна дл¤ обращени¤ к консоли
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // задаЄм серый фон дл¤ окна консоли
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // очищаем экран, чтобы настройка цвета применилась
    system("cls");

    // объ¤вление переменных
    int choose_pos;                    // переменна¤ дл¤ хранени¤ выбранного пункта меню                          // переменна¤ дл¤ фиксации нажатой клавиши
    int exit_flag;                     // флаг на завершение программs
    int size = 0;
    int back_flag;
    int* mass;
    mass = (int*)malloc(sizeof(int) * size);

    char* menu[MENU_SIZE] = { "Алгоритмы", "Настройки", "Выход" };
    char* menu1[MENU_SIZE1] = { "Поиск", "Сортировки", "Назад"};
    char* menu_for_search[MENU_SIZE2] = {"Наивный поиск", "Бинарный поиск","Назад"};
    char* menu_for_sorts[MENU_SIZE3] = {"Пузырьковая сортировка", "Назад"};
    char* menu_for_settings[MENU_SIZE4] = { "Задать массив", "Посмотреть текущий массив", "Назад" };
    // инициализаци¤ (заполнение значени¤ми) переменных
    exit_flag = 0;
    back_flag = 0;
    choose_pos = 0;


    while (!exit_flag) {
        back_flag = 0;
        constractMenu(hStdOut, menu, MENU_SIZE, &choose_pos);
        if (choose_pos == 0) {
            while (!back_flag) {
                constractMenu(hStdOut, menu1, MENU_SIZE1, &choose_pos);
                if (choose_pos == 0) {
                    while (!back_flag) {
                        constractMenu(hStdOut, menu_for_search, MENU_SIZE2, &choose_pos);
                        if (choose_pos == 0) {
                            system("cls");
                            just_search(mass, size);
                            Sleep(1000);
                        }
                        else if (choose_pos == 1) {
                            system("cls");
                            binar_search(mass, size);
                            Sleep(1000);
                        }
                        else if (choose_pos == 2) {
                            back_flag = 1;
                        }
                    }
                }
                else if (choose_pos == 1) {
                    while (!back_flag) {
                        constractMenu(hStdOut, menu_for_sorts, MENU_SIZE3, &choose_pos);
                        if (choose_pos == 0) {
                       
                            bubble_sort(mass,size);
                            system("cls");
                        }
                        else if (choose_pos == 1) {
                            back_flag = 1;
                        }
                    }
                }
                else if (choose_pos == 2) {
                    back_flag =1 ;
                }
            }
        }
        else if (choose_pos == 1) {
            while (!back_flag) {
                constractMenu(hStdOut, menu_for_settings, MENU_SIZE4, &choose_pos);
                if (choose_pos == 0) {
                    system("cls");
                    printf("Введите размер массива: ");
                    scanf_s("%d", &size);
                    generate_mass(mass, size);
                }
                else if( choose_pos == 1){
                    system("cls");
                    print_mass(mass,size);
                    Sleep(1000);
                }
                else if (choose_pos == 2) {
                    back_flag = 1;
                }
            }
        }else if (choose_pos == 2) {
            system("cls");
            exit_flag = 1;
        }
        
    }

    // вывод результата
    system("cls");
    printf("Goodbay!\n");

    // завершение программы
    system("pause");
    return 0;
}