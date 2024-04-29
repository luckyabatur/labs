#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

bool Equal(const Iterator* lhs, const Iterator* rhs)
{
    return lhs->node == rhs->node;
}

bool NotEqual(const Iterator* lhs, const Iterator* rhs)
{
    return !Equal(lhs, rhs);
}

Iterator* Next(Iterator* i)
{
    if (i->node->next != NULL)
        i->node = i->node->next;
    return i;
}

Iterator* Prev(Iterator* i)
{
    if (i->node->prev != NULL)
        i->node = i->node->prev;
    return i;
}

int Fetch(const Iterator* i)   
{
    return i->node->data;
}

void Store(const Iterator* i, const int t)
{
    i->node->data = t;
}

void Create(List* l)
{
    l->head = malloc(sizeof(Item));
    l->head->prev = l->head->next = NULL;
    l->size = 0;
}

Iterator First(const List* l)
{
    Iterator res = { l->head };
    while (res.node->prev != NULL)
        Prev(&res);
    return res;
}

Iterator Last(const List* l)
{
    Iterator res = { l->head };
    return res;
}

bool Empty(const List* l)
{
    Iterator fst = First(l);
    Iterator lst = Last(l);
    return Equal(&fst, &lst);
}

int Size(const List* l)
{
    return l->size;
}

Iterator Insert(List* l, Iterator* i, const colors t)
{
    Iterator res = { malloc(sizeof(Item)) };
    if (!res.node)
        return Last(l);
    res.node->data = t;
    res.node->next = i->node;
    res.node->prev = i->node->prev;
    if (res.node->prev != NULL)
        res.node->prev->next = res.node;
    i->node->prev = res.node;
    l->size++;
    return res;
}

Iterator Index(List* l, const int ind)
{
    Iterator empty = { NULL };
    Iterator res = First(l);

    if (ind < 0 || ind > l->size)
        return empty;

    for (int k = 0; k < ind; k++)
    {
        Next(&res);
    }

    return res;  
}

Iterator Delete(List* l, Iterator* i)
{
    Iterator empty = { NULL };
    Iterator res = Last(l);
    if (Equal(i, &res))
        return empty;
    res.node = i->node->next;
    res.node->prev = i->node->prev;
    if (i->node->prev != NULL)
        i->node->prev->next = res.node; 
    l->size--;
    free(i->node);
    i->node = 0;
    return res;
}

void Destroy(List* l)
{
    Iterator last = Last(l);
    Iterator res = First(l);
    while (Next(&res)->node != last.node)
    {
        Item* pi = res.node;
        Next(&res);
        free(pi);
    }
    free(l->head);
    l->head = NULL;
    l->size = 0;
}

void fill(List* l)
{
    int i;
    Iterator last = Last(l);
    while (scanf("%d", &i) != EOF)
        Insert(l, &last, i);
}

void PrintList(List *l)
{
    if (Empty(l))
        printf("...   пустота  ....");
    Iterator last = Last(l);
    for (Iterator i = First(l); NotEqual(&i, &last); Next(&i))
    {
        printf("%d ", i.node->data);
    }
    printf("\n");
}

void Exchange(List *l, Iterator* second)
{
    Iterator first = First(l);
    first.node->prev = second->node;
    second->node->prev->next = second->node->next;
    second->node->next->prev = second->node->prev;
    first.node->prev->prev = NULL;
    first.node->prev->next = first.node;
}

void Reverse(List* l)
{
    Iterator i = First(l);
    Next(&i);
    Iterator empty = { NULL };
    if (Size(l) < 2)
        return;
    for (int k = 0; k < Size(l) - 1; k++)
    {
        Exchange(l, &i);
        i = First(l);
        for (int j = 0; j < k + 2; j++)
            Next(&i);
    }
}