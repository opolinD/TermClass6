
// ���������� �������� ����������
#include <windows.h>
#include <conio.h>
#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
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