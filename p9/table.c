#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "vectors_table.h"


int Compare(key k1, key k2)
{
    if (k1.key1 <  k2.key1)
        return 1;
    else if (k1.key1 > k2.key1)
        return 2;
    else if (k1.key2 < k2.key2)
        return 1;
    else if (k1.key2 > k2.key2)
        return 2;
    else
        return 3;
}


void VectorSort(VectorK* keys, Vector* values, int start, int end)
{
    int left, right, avg;
    VectorK mas;
    Vector buf;
    ZeroCreateK(&mas, end - start + 1);
    ZeroCreate(&buf, end - start + 1);
    avg = (start + end) / 2;
    left = start;
    right= avg + 1;

    for(int j = start; j <= end; j++)
    {
        if ((left <= avg) && ((right > end) || (Compare(LoadK(keys, left), LoadK(keys, right)) == 1)))
        {
            SaveK(&mas, j - start, LoadK(keys, left));
            Save(&buf, j - start, Load(values, left));
            left++;
        }
        else
        {
            
            SaveK(&mas, j - start, LoadK(keys, right));
            Save(&buf, j - start, Load(values, right));
            right++;
        }
    }
    for(int j=start; j <=end; j++)
    {
        SaveK(keys, j, LoadK(&mas, j - start));
        Save(values, j, Load(&buf, j - start));
    }
    DestroyK(&mas);
    Destroy(&buf);
}

void Merge(VectorK* keys, Vector* values, int start, int end)
{
    if (start < end)
    {
    Merge(keys, values, start, (start + end) / 2);
    Merge(keys, values, (start + end)/2 + 1, end);
    VectorSort(keys, values, start, end);
    }
}

char* BinaryFind(Vector* values, VectorK* keys, key t)
{
    int L = 0, R = values->size - 1;


    while (L <= R)
    {
        int m = (L + R) / 2;
        if (Compare(LoadK(keys, m), t) == 3)
            return Load(values, m);
        else if (Compare(LoadK(keys, m), t) == 1)
            L = m+1;
        else 
            R = m-1;
    }

    return NULL;
}

void PrintTable(Vector* values, VectorK* keys)
{
    printf("Key   Value\n");
    for (int i = 0; i < values->size; i++)
    {   
        printf("%-5lld %c ", keys->data[i].key1, keys->data[i].key2);
        puts(values->data[i]);
    } 
}


void FileToVector(char* name, Vector* v)
{
    FILE* f = fopen(name, "r");
    char buf[SIZE];
    int state = 0, count = 0;
    char s = 0;
    while (s != EOF)
    {
        s = fgetc(f);
        switch (state)
        {
        case 0:
            if (s != ' ' && s != '\n' && s != '.' && s != ',')
            {
                buf[count] = s;
                count++;
            }
            else if (count != 0)
            {
                buf[count] = '\0';
                count = 0;
                Push(v, buf);
                state = 1;
            }
            break;
        case 1:
            if (s != ' ' && s != '\n' && s != '.' && s != ',' && s != EOF)
            {
                buf[count] = s;
                count++;
                state = 0;
            }
            break;  
        default:
            break;
        }
    }
    if (state == 0)
    {
        buf[count-1] = '\0';
        Push(v, buf);
    }
    fclose(f);
}