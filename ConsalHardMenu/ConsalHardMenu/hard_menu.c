// библиотеки
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
// управл¤ющие консолью библиотеки
#include <windows.h>
#include <conio.h>
#include"functions.h"
#define START_MENU_SIZE 4
#define ALGORITHM_MENU_SIZE 3
#define SEARCH_MENU_SIZE 3
#define SORTINGS_MENU_SIZE 5
#define SETTINGS_MENU_SIZE 4
#define MENU_SIZE_FOR_EXP 3
#define MENU_SIZE_FOR_MASS 4
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
struct Sort {
    char name_of_sort[50];
    int time;
    int swaps;
    int comps;
};
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
    int choose_pos;
    int exit_flag;
    int size = 1;
    int back_flag;
    int back_flag1;
    int time_of_sort;
    int* mass;
    int* first_mass;
    int swaps = 0, comps = 0;
    mass = (int*)malloc(sizeof(int) * size);
    first_mass = (int*)malloc(sizeof(int) * size);
    mass = NULL;
    first_mass = NULL;
    char dir[100] = "C:\\GitHubProjects\\source\\";
    char filename[100] = "input.txt";
    char filepath[200];
    char filename1[100] = "output.txt";
    char filepath1[200];
    strcpy_s(filepath, sizeof filepath, dir);
    strncat_s(filepath, 100, filename, 100);
    strcpy_s(filepath1, sizeof filepath1, dir);
    strncat_s(filepath1, 100, filename1, 100);
    FILE* input_file = NULL;
    FILE* output_file = NULL;
    srand(time(0));
    //пункты меню
    char* menu_for_experimentmode[MENU_SIZE_FOR_EXP] = { "Сравнение сорторовок", "Эффективность", "Назад" };
    char* start_menu[START_MENU_SIZE] = { "Режим эксперимента", "Алгоритмы", "Настройки", "Выход" };
    char* algorithm_menu[ALGORITHM_MENU_SIZE] = { "Поиск", "Сортировки", "Назад" };
    char* menu_for_search[SEARCH_MENU_SIZE] = { "Наивный поиск", "Бинарный поиск","Назад" };
    char* menu_for_sorts[SORTINGS_MENU_SIZE] = { "Пузырьковая сортировка","Сортировка Шелла", "Сортировка вставками", "Сортировка подсчетом",  "Назад" };
    char* menu_for_settings[SETTINGS_MENU_SIZE] = { "Задать массив","Изменить путь до файла", "Посмотреть текущий массив", "Назад" };
    char* menu_for_mass[MENU_SIZE_FOR_MASS] = { "Задать вручную", "Автоматически","Считать с файла", "Назад" };
    // инициализаци¤ (заполнение значени¤ми) переменных
    exit_flag = 0;
    back_flag = 0;
    choose_pos = 0;
    back_flag1 = 0;
    while (!exit_flag) {
        back_flag = 0;
        constractMenu(hStdOut, start_menu, START_MENU_SIZE, &choose_pos);
        if (choose_pos == 0) {
            while (!back_flag) {
                constractMenu(hStdOut, menu_for_experimentmode, MENU_SIZE_FOR_EXP, &choose_pos);
                if (choose_pos == 0) {
                    float min_time = 0;
                    float min_swaps = 0;
                    float min_comps = 0;
                    struct Sort shell;
                    struct Sort bubble;
                    struct Sort inserts;
                    struct Sort counting;
                    //сравнение сортировок
                    reb_mass(mass, first_mass, size);
                    time_of_sort = clock();
                    bubble_sort(mass, size, &swaps, &comps);
                    time_of_sort = clock() - time_of_sort;
                    bubble.time = time_of_sort;
                    bubble.comps = comps;
                    bubble.swaps = swaps;
                    strcpy_s(bubble.name_of_sort, 23, "Пузырьковая сортировка");
                    reb_mass(mass, first_mass, size);
                    time_of_sort = clock();
                    shell_sort(mass, size, &swaps, &comps);
                    time_of_sort = clock() - time_of_sort;
                    shell.time = time_of_sort;
                    shell.comps = comps;
                    shell.swaps = swaps;
                    strcpy_s(shell.name_of_sort, 17, "Сортировка Шелла");
                    reb_mass(mass, first_mass, size);
                    time_of_sort = clock();
                    insertion_sort(mass, size, &swaps, &comps);
                    time_of_sort = clock() - time_of_sort;
                    inserts.time = time_of_sort;
                    inserts.comps = comps;
                    inserts.swaps = swaps;
                    strcpy_s(inserts.name_of_sort, 21, "Сортировка вставками");
                    reb_mass(mass, first_mass, size);
                    time_of_sort = clock();
                    counting_sort(mass, size, &swaps, &comps);
                    time_of_sort = clock() - time_of_sort;
                    counting.time = time_of_sort;
                    counting.comps = comps;
                    counting.swaps = swaps;
                    strcpy_s(counting.name_of_sort, 21, "Сортировка подсчетом");
                    min_time = compare_stats(bubble.time, shell.time, inserts.time, counting.time);
                    min_swaps = compare_stats(bubble.swaps, shell.swaps, inserts.swaps, counting.swaps);
                    min_comps = compare_stats(bubble.comps, shell.comps, inserts.comps, counting.comps);
                    system("cls");
                    printf("|Название               |Время     |Замедление |Количество перестановок |Увеличение числа перестановок |Количество сравнений |Увеличение числа сравнений |");
                    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
                    printf("\n|%-23s|%-10d|%-11.4lf|%-24d|%-30.4lf|%-21d|%-27.4lf|", bubble.name_of_sort, bubble.time, bubble.time/ min_time, bubble.swaps, bubble.swaps /min_swaps, bubble.comps, bubble.comps/ min_comps);
                    printf("\n|%-23s|%-10d|%-11.4lf|%-24d|%-30.4lf|%-21d|%-27.4lf|", shell.name_of_sort, shell.time, shell.time / min_time, shell.swaps, shell.swaps / min_swaps, shell.comps, shell.comps / min_comps);
                    printf("\n|%-23s|%-10d|%-11.4lf|%-24d|%-30.4lf|%-21d|%-27.4lf|", inserts.name_of_sort, inserts.time, inserts.time / min_time, inserts.swaps, inserts.swaps / min_swaps, inserts.comps, inserts.comps / min_comps);
                    printf("\n|%-23s|%-10d|%-11.4lf|%-24d|%-30.4lf|%-21d|%-27.4lf|", counting.name_of_sort, counting.time, counting.time / min_time, counting.swaps, counting.swaps / min_swaps, counting.comps, counting.comps / min_comps);
                    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
                    _getch();
                }
                else if (choose_pos == 1) {
                    //эффективность
                    int choose_of_sort;
                    int size1, size2, size3, time_of_sort1, time_of_sort2, time_of_sort3;
                    system("cls");
                    printf("1.Пузырьковая сортировка\n2.Сортировка Шелла\n3.Сортировка вставками\n4.Сортировка подсчетом\nВвод: ");
                    scanf_s("%d", &choose_of_sort);
                    system("cls");
                    void (*pfunc[4])(int*, int, int*, int*) = {bubble_sort, shell_sort, insertion_sort, counting_sort};
                    if (choose_of_sort < 1 || choose_of_sort>4) {
                        printf("Введено неправильное значение");
                        _getch();
                        system("cls");
                    }
                    else {
                        printf("Введите размер первого масива: ");
                        scanf_s("%d", &size1);
                        printf("Введите размер второго масива: ");
                        scanf_s("%d", &size2);
                        printf("Введите размер третьего масива: ");
                        scanf_s("%d", &size3);
                        system("cls");
                        int* mass1 = (int*)malloc(sizeof(int) * size1);
                        int* mass2 = (int*)malloc(sizeof(int) * size2);
                        int* mass3 = (int*)malloc(sizeof(int) * size3);
                        gener_mass_for_comp(mass1, size1);
                        gener_mass_for_comp(mass2, size2);
                        gener_mass_for_comp(mass3, size3);
                        time_of_sort1 = clock();
                        pfunc[choose_of_sort -1](mass1, size1, &swaps, &comps);
                        time_of_sort1 = clock() - time_of_sort1;
                        time_of_sort2 = clock();
                        pfunc[choose_of_sort -1](mass2, size2, &swaps, &comps);
                        time_of_sort2 = clock() - time_of_sort2;
                        time_of_sort3 = clock();
                        pfunc[choose_of_sort -1](mass3, size3, &swaps, &comps);
                        time_of_sort3 = clock() - time_of_sort3;
                        float min_time = compare_stats1(time_of_sort1, time_of_sort2, time_of_sort3);
                        printf("|Размер массива |Время работы |Замедление |\n ");
                        printf("------------------------------------------\n");
                        printf("|%-15d|%-13d|%-11f|\n", size1, time_of_sort1, time_of_sort1 / min_time);
                        printf("|%-15d|%-13d|%-11f|\n", size2, time_of_sort2, time_of_sort2 / min_time);
                        printf("|%-15d|%-13d|%-11f|\n", size3, time_of_sort3, time_of_sort3 / min_time);
                        printf("------------------------------------------\n");
                        _getch();
                    }
                }
                else if (choose_pos == 2) {
                    back_flag = 1;
                }
            }
        }
        else if (choose_pos == 1) {
            while (!back_flag) {
                constractMenu(hStdOut, algorithm_menu, ALGORITHM_MENU_SIZE, &choose_pos);
                back_flag1 = 0;
                if (choose_pos == 0) {
                    while (!back_flag1) {
                        constractMenu(hStdOut, menu_for_search, SEARCH_MENU_SIZE, &choose_pos);
                        if (choose_pos == 0) {
                            //наивный поиск
                            system("cls");
                            just_search(mass, size);
                            _getch();
                        }
                        else if (choose_pos == 1) {
                            //бинарный поиск
                            system("cls");
                            binar_search(mass, size);
                            _getch();
                        }
                        else if (choose_pos == 2) {
                            //назад
                            back_flag1 = 1;
                        }
                    }
                }
                else if (choose_pos == 1) {
                    while (!back_flag1) {
                        constractMenu(hStdOut, menu_for_sorts, SORTINGS_MENU_SIZE, &choose_pos);
                        back_flag1 = 0;
                        if (choose_pos == 0) {
                            //пузырьковая сортировка
                            reb_mass(mass, first_mass, size);
                            system("cls");
                            print_mass(mass, size, filepath1, filename1, dir,output_file);
                            time_of_sort = clock();
                            bubble_sort(mass, size, &swaps, &comps);
                            time_of_sort = clock() - time_of_sort;
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            printf("time: %d\ncomps: %d\nswaps: %d", time_of_sort, comps, swaps);
                            _getch();
                            system("cls");
                        }
                        else if (choose_pos == 1) {
                            //сортировка шелла
                            reb_mass(mass, first_mass, size);
                            system("cls");
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            time_of_sort = clock();
                            shell_sort(mass, size, &swaps, &comps);
                            time_of_sort = clock() - time_of_sort;
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            printf("time: %d\ncomps: %d\nswaps: %d", time_of_sort, comps, swaps);
                            _getch();
                            system("cls");
                        }
                        else if (choose_pos == 2) {
                            //сортировка вставками
                            reb_mass(mass, first_mass, size);
                            system("cls");
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            time_of_sort = clock();
                            insertion_sort(mass, size, &swaps, &comps);
                            time_of_sort = clock() - time_of_sort;
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            printf("time: %d\ncomps: %d\nswaps: %d", time_of_sort, comps, swaps);
                            _getch();
                            system("cls");
                        }
                        else if (choose_pos == 3) {
                            //сортировка подсчетом
                            reb_mass(mass, first_mass, size);
                            system("cls");
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            time_of_sort = clock();
                            counting_sort(mass, size, &swaps, &comps);
                            time_of_sort = clock() - time_of_sort;
                            print_mass(mass, size, filepath1, filename1, dir, output_file);
                            printf("time: %d\ncomps: %d\nswaps: %d", time_of_sort, comps, swaps);
                            _getch();
                            system("cls");
                        }
                        else if (choose_pos == 4) {
                            //назад
                            back_flag1 = 1;
                        }
                    }

                }
                else if (choose_pos == 2) {
                    back_flag = 1;
                }
            }
        }
        else if (choose_pos == 2) {
            while (!back_flag) {
                constractMenu(hStdOut, menu_for_settings, SETTINGS_MENU_SIZE, &choose_pos);
                if (choose_pos == 0) {
                    back_flag1 = 0;
                    while (!back_flag1) {
                        constractMenu(hStdOut, menu_for_mass, MENU_SIZE_FOR_MASS, &choose_pos);
                        if (choose_pos == 0) {
                            system("cls");
                            printf("Введите размер массива: ");
                            free(mass);
                            free(first_mass);
                            scanf_s("%d", &size);
                            mass = (int*)malloc(sizeof(int) * size);
                            first_mass = (int*)malloc(sizeof(int) * size);
                            generate_mass_by_hand(mass, first_mass, size);
                        }
                        else if (choose_pos == 1) {
                            system("cls");
                            free(mass);
                            free(first_mass);
                            printf("Введите размер массива: ");
                            scanf_s("%d", &size);
                            mass = (int*)malloc(sizeof(int) * size);
                            first_mass = (int*)malloc(sizeof(int) * size);
                            generate_mass_auto(mass, first_mass, size);
                        }
                        else if (choose_pos == 2) {
                            //считать массив из файла
                            int new_size = 0;
                            mass = input(filepath, mass, size, &new_size,input_file);
                            first_mass = input(filepath, first_mass, size, &new_size,input_file);
                            size = new_size;
                        }
                        else if (choose_pos == 3) {
                            back_flag1 = 1;
                        }
                    }

                }
                else if (choose_pos == 1) {
                    //изменить путь до файла
                    system("cls");
                    printf("Введите путь до файла:\n");
                    gets(dir);
                }
                else if (choose_pos == 2) {
                    //посмотреть текущий массив
                    system("cls");
                    print_mass(mass, size, filepath1, filename1, dir, output_file);
                    _getch();
                }
                else if (choose_pos == 3) {
                    back_flag = 1;
                }
            }
        }
        else if (choose_pos == 3) {
            //выход
            system("cls");
            exit_flag = 1;
        }
    }
    free(mass);
    free(first_mass);
    system("cls");
    printf("Goodbay!\n");
    // завершение программы
    system("pause");
    return 0;
}