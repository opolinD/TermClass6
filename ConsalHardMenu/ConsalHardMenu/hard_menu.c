// ����������
#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include<malloc.h>

// ���������� �������� ����������
#include <windows.h>
#include <conio.h>

#define MENU_SIZE 3
#define MENU_SIZE1 3
#define MENU_SIZE2 3
#define MENU_SIZE3 2
#define MENU_SIZE4 3


// �������� �����, ������� ����� ����������

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

//�������
void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
    // ���������� ����������
    int iKey; // ���������� ��� �������� ������� �������
    COORD cursorPos; // ���������� ���������� �������, ����� ������ ��������� �����
    // ������������� (���������� ����������) ����������
    *choose_pos = 0;
    /* 1. ����� ���� � ������������� */
    // ����� ������� � ��������� ���������
    system("cls");
    iKey = 67;
    cursorPos = (COORD){ 0, 0 };
    SetConsoleCursorPosition(hStdOut, cursorPos);
    // �������� ������� ������
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
        // ������������ �������������� ����
        if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
        if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
        for (int i = 0; i < menu_size; i++) {
            cursorPos = (COORD){ 3, i };
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("%s \n", menu_names[i]);
        }
        // ����������� ��������� �������
        cursorPos = (COORD){ 0, *choose_pos };
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf("<<", iKey);
        cursorPos = (COORD){ strlen(menu_names[*choose_pos]) + 3 + 1, *choose_pos };
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf(">>");
        // �������� ������ ������� �������
        iKey = _getch();
    }
}
void generate_mass(int * mass, int size) {
    printf("������� �������� �������:\n");
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
    printf("������� �������: ");
    scanf_s("%d", &desired);
    for (int i = 0; i < size; i++) {
        if (mass[i] == desired) {
            printf("������� ����� �� %d ����� � �������\n", i + 1);
        }
    }
}
void binar_search(int* mass, int size) {
    int left, right, middle, val;
    printf("������� ������� �������: ");
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
            printf("������� ������� �� %d �����\n",middle);
        }
    }
    printf("������� ������ �� ������(.");
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




// ���������� ������� �������
int main() {
    // ���������

    // ����� �������� ����������� ����
    system("title Application");

    // ������������� �������������� � �������� �������
    SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

    // �������� ���������� ���� �� �������� � �������
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ���������� ������ ������� � ������� (� ����� ���� ������ ������)
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

    // ����� ����� ��� �� ���� �������
    SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    // ������� �����, ����� ��������� ����� �����������
    system("cls");

    // ���������� ����������
    int choose_pos;                    // ��������� �� ������� ���������� ������ ����                          // ��������� �� �������� ������� �������
    int exit_flag;                     // ���� �� ���������� ��������s
    int size = 0;
    int back_flag;
    int* mass;
    mass = (int*)malloc(sizeof(int) * size);

    char* menu[MENU_SIZE] = { "���������", "���������", "�����" };
    char* menu1[MENU_SIZE1] = { "�����", "����������", "�����"};
    char* menu_for_search[MENU_SIZE2] = {"������� �����", "�������� �����","�����"};
    char* menu_for_sorts[MENU_SIZE3] = {"����������� ����������", "�����"};
    char* menu_for_settings[MENU_SIZE4] = { "������ ������", "���������� ������� ������", "�����" };
    // ������������ (���������� ���������) ����������
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
                    printf("������� ������ �������: ");
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

    // ����� ����������
    system("cls");
    printf("Goodbay!\n");

    // ���������� ���������
    system("pause");
    return 0;
}