#ifndef _LIST_H_ 
#define _LIST_H_

#include <stdbool.h>

typedef enum colors 
{
    BLACK,
    PINK,
    GREY,
    BROWN,
    BLUE,
    ORANGE,
    PURPLE,
    WHITE,
    YELLOW,
    GREEN,
    RED
} colors;

typedef struct Item
{
    struct Item* prev;
    struct Item* next;
    colors data;
} Item;

typedef struct Iterator
{
    Item* node;
} Iterator;

typedef struct List
{
    Item* head;
    int size;
} List;

bool Equal(const Iterator* lhs, const Iterator* rhs);
bool NotEqual(const Iterator* lhs, const Iterator* rhs);
Iterator* Next(Iterator* i);
Iterator* Prev(Iterator* i);
int Fetch(const Iterator* i);   
void Store(const Iterator* i, const int t);
void Create(List* l);
Iterator First(const List* l);
Iterator Last(const List* l);
bool Empty(const List* l);
int Size(const List* l);
Iterator Insert(List* l, Iterator* i, const colors t);
Iterator Delete(List* l, Iterator* i);
void Destroy(List* l);
Iterator Index(List* l, const int ind);
void fill(List* l);
void PrintList(List *l);
void Reverse(List* l);
void Exchange(List *l, Iterator *second);

#endif