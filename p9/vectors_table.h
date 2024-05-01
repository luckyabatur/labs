#ifndef _PT_
#define _PT_

#include <stdbool.h>

#define SIZE 30

typedef char string[SIZE];

typedef struct key
{
    long long key1;
    char key2;
} key;

typedef struct Vector
{
    string* data;
    int capacity;
    int size;
} Vector;

typedef struct VectorK
{
    key* data;
    int capacity;
    int size;
} VectorK;


void Create(Vector* v, int sz);
bool Empty(Vector *v);
int Size(Vector* v);
char* Load(Vector* v, int i);
void Save(Vector *v, int i, string t);
void Resize(Vector* v, int sz);
void Push(Vector* v, string t);
void Print(Vector* v);
void Destroy(Vector* v);
void ZeroCreate(Vector* v, int sz);


void CreateK(VectorK* v, int sz);
bool EmptyK(VectorK *v);
int SizeK(VectorK* v);
key LoadK(VectorK* v, int i);
void SaveK(VectorK *v, int i, key t);
void ResizeK(VectorK* v, int sz);
void PushK(VectorK* v, key t);
void DestroyK(VectorK* v);
void Increase(VectorK *v, int size);
bool FindK(VectorK *v, key t);
void RandomKeys(VectorK *v, int size);
void Reverse(VectorK* v);
void ZeroCreateK(VectorK* v, int sz);
void PrintK(VectorK* v);


int Compare(key k1, key k2);
void VectorSort(VectorK* keys, Vector* values, int start, int end);
void Merge(VectorK* keys, Vector* values, int start, int end);
char* BinaryFind(Vector* values, VectorK* keys, key t);
void PrintTable(Vector* values, VectorK* keys);
void FileToVector(char* name, Vector* v);

#endif