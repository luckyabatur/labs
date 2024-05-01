#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "vectors_table.h"
#include <string.h>


void Create(Vector* v, int sz)
{
    v->capacity = sz;
    v->size = 0;
    v->data = (string*)(malloc(sizeof(string) * v->capacity));
}

bool Empty(Vector *v)
{
    return v->size == 0;
}

int Size(Vector* v)
{
    return v->size;
}

char* Load(Vector* v, int i)
{
    if ((i >= 0) && (i < v->size))
        return v->data[i];
}

void Save(Vector *v, int i, string t)
{
    if ((i >= 0) && (i < v->size))
        strcpy(v->data[i], t);
}


void Resize(Vector* v, int sz)
{
    v->capacity = sz;
    v->data = realloc(v->data, sizeof(string) * sz);
}

void Push(Vector* v, string t)
{
    if (v->size >= v->capacity)
        Resize(v, v->capacity * 2);
    strcpy(v->data[v->size], t);
    v->size++;
}

void Print(Vector* v)
{
    for (int i = 0; i < v->size; i++)
    {   
        printf("%d", i);
        puts(v->data[i]);
    }       
}


void Destroy(Vector* v)
{
    v->size = 0;
    free(v->data);
}

void ZeroCreate(Vector* v, int sz)
{
    v->capacity = sz;
    v->size = 0;
    v->data = (string*)malloc(sizeof(string) * v->capacity);
    string t = {};
    for (int i = 0; i < sz; i++)
    {
        Push(v, t);
    }
}

