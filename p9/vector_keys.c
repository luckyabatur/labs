#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "vectors_table.h"


void CreateK(VectorK* v, int sz)
{
    v->capacity = sz;
    v->size = 0;
    v->data = (key*)malloc(sizeof(key) * v->capacity);
}


bool EmptyK(VectorK *v)
{
    return v->size == 0;
}


int SizeK(VectorK* v)
{
    return v->size;
}


key LoadK(VectorK* v, int i)
{
    if ((i >= 0) && (i < v->size))
        return v->data[i];
}

void SaveK(VectorK *v, int i, key t)
{
    if ((i >= 0) && (i < v->size))
        v->data[i] = t;
}

void ResizeK(VectorK* v, int sz)
{
    v->capacity = sz;
    v->data = realloc(v->data, sizeof(key) * v->capacity);
}


void PushK(VectorK* v, key t)
{
    if (v->size >= v->capacity)
        ResizeK(v, v->capacity * 2);
    v->data[v->size] = t;
    v->size++;
}


void DestroyK(VectorK* v)
{
    v->size = 0;
    free(v->data);
}


void Increase(VectorK *v, int size)
{
    key t;
    t.key2 = 'A';
    for (int i = 0; i < size; i++)
    {
        t.key1 = i;
        PushK(v, t);
    }
}


bool FindK(VectorK *v, key t)
{
    for (int i = 0; i < v->size; i++)
        if (Compare(v->data[i], t) == 3)
            return true;
    return false;
}

void RandomKeys(VectorK *v, int size)
{
    for (int i = 0; i < size; i++)
    {   
        int flag = 0;
        key t;
        while (FindK(v, t) || flag == 0)
        {
            int key_i = rand() % size; 
            int key_c= rand() % 52 + 65;
            if (key_c > 90)
                key_c += 6;
            t.key1 = key_i;
            t.key2 = key_c;
            flag = 1;
        }
        PushK(v, t); 
    }    
}


void Reverse(VectorK* v)
{
    int start = 0, end = v->size - 1;
    key temp;
    while (start < end)
    {
        temp = v->data[start];
        v->data[start] = v->data[end];
        v->data[end] = temp;
        start++;
        end--;
    } 
}

void ZeroCreateK(VectorK* v, int sz)
{
    v->capacity = sz;
    v->size = 0;
    v->data = (key*)malloc(sizeof(key) * v->capacity);
    key t = { 0, 'A' };
    for (int i = 0; i < sz; i++)
    {
        PushK(v, t);
    }
}

void PrintK(VectorK* v)
{
    for (int i = 0; i < v->size; i++)
    {   
        printf("%lld %c", v->data[i].key1, v->data[i].key2);
    }      
}

