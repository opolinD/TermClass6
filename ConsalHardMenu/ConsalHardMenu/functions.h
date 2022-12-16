#pragma once
void bubble_sort(int* mass, int size, int* count_swap, int* count_comp);
void generate_mass_by_hand(int* mass, int* first_mass, int size);
void generate_mass_auto(int* mass, int* first_mass, int size);
void just_search(int* mass, int size);
void binar_search(int* mass, int size);
void shell_sort(int* mass, int size, int* count_swap, int* count_comp);
void insertion_sort(int* mass, int size, int* count_swap, int* count_comp);
void counting_sort(int* mass, int size, int* count_swap, int* count_comp);
void reb_mass(int* mass, int* first_mass, int size);
float compare_stats(int a, int b, int c, int d);
float compare_stats1(int a, int b, int c);
void gener_mass_for_comp(int* mass, int size);
int* input(char* filepath, int* mass, int size, int* new_size, FILE* input_file);
void print_mass(int* mass, int size, char* filepath, char* filename, char* dir, FILE* output_file);
void constractMenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);