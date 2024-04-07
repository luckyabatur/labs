#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
#include "list.c"

void fill(List* l)
{
    int i;
    Iterator last = Last(l);
    while (scanf("%d", &i) != EOF)
        Insert(l, &last, i);
}

void traversal(List* l)
{
    Iterator last = Last(l);
    for (Iterator i = First(l); NotEqual(&i, &last); i = *Next(&i))
    {
        printf("%d ", i.node->data);
    }
}

bool help(List *l)
{
    
    Iterator find = { First(l).node->next }, last = Last(l), ins, first;
    while (find.node->data >= find.node->prev->data)
    {
        find = *Next(&find);
        if (Equal(&find, &last))
            return false;
    }
    ins = find;
    first = First(l);
    while (ins.node->prev->data >= find.node->data  && NotEqual(&ins, &first))
        ins = *Prev(&ins);
    Insert(l, &ins, find.node->data);
    Delete(l, &find);
    return true;
}

void sort(List *l)
{
    while (help(l));
}

int main (void)
{
    List* l;
    Create(l);
    fill(l);
    sort(l);
    traversal(l);
    return 0;
}



