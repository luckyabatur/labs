#include <stdio.h>
#define SIZE_N 10
#define SIZE_I 3


typedef struct student
{
    char name[SIZE_N];
    char initials[SIZE_I];
    char gender;
    int group;
    int la, ma, dm, inf, py;
} student;

int read_file(student* s, FILE* f);
void print_table(FILE* f);