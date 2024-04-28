#include <stdio.h>
#include "student.h"


int read_file(student* s, FILE* f)
{
    fread(s->name, sizeof(char), SIZE_N, f);
	fread(s->initials, sizeof(char), SIZE_I, f);
	fread(&s->gender, sizeof(char), 1, f);
	fread(&s->group, sizeof(int), 1, f);
	fread(&s->la, sizeof(int), 1, f);
	fread(&s->inf, sizeof(int), 1, f);
	fread(&s->py, sizeof(int), 1, f);
	fread(&s->dm, sizeof(int), 1, f);
	fread(&s->ma, sizeof(int), 1, f);

    return !feof(f);
}
void print_table(FILE* f)
{   
    printf("%-10s %-8s %-6s %-5s %c %c %c %c %c\n",\
    "Name", "Initials", "Gender", "Group", 'L', 'I', 'P', 'D', 'M');
    student st;
    int k = 0;
    while (read_file(&st, f))
    {
        printf("%-10s %-8s %-6c %-5d %d %d %d %d %d\n",
	    st.name, st.initials, st.gender, st.group, st.la, st.inf, st.py, st.dm, st.ma);
    } 
}