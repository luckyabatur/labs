#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "vectors_table.h"


int main()
{
    srand(time(NULL));
    Vector values;
    VectorK keys;
    Create(&values, 10);
    CreateK(&keys, 10);
    FileToVector("song.txt", &values);
    int f;
    bool sorted = false;
    printf("Определите способ создания ключей:\n1 - По возрастанию\n2 - По убыванию\n3 - Рандомно\n");
    scanf("%d", &f);
    switch (f)
    {
    case 1:
        Increase(&keys, values.size);
        sorted = true;
        break;
    case 2:
        Increase(&keys, values.size);
        Reverse(&keys);
        break;
    case 3:
        RandomKeys(&keys, values.size);
        break;
    default:
        printf("Invalid input\n");
    }


    printf("\n1 - Вывести таблицу\n2 - Отсортировать таблицу\n3 - Найти элемент по ключу\n4 - Завершить программу\n");
    scanf("%d", &f);
    while (f != 4)
    {   
        switch (f)
        {
        case 1:
            PrintTable(&values, &keys);
            break;
        case 2:
            if (sorted == true)
            {
                printf("Таблица уже отсортирована\n");
                break;
            }
            Merge(&keys, &values, 0, values.size - 1);
            printf("Таблица отсортирована\n");
            sorted = true;
            break;
        case 3:
            key t;
            scanf("%lld %c", &t.key1, &t.key2);
            if (sorted == false)
            {
                printf("Сначала отсортируйте таблицу\n");
                break;
            }
            else
            {
                char* a = BinaryFind(&values, &keys, t);
                if (a == NULL)
                    printf("Ключ отсутствует в таблице\n");
                else
                {
                    printf("Искомый элемент: ");
                    puts(a);
                }
                break;
            }
        default:
            printf("Invalid input\n");
        }
        printf("\n1 - Вывести таблицу\n2 - Отсортировать таблицу\n3 - Найти элемент по ключу\n4 - Завершить программу\n");
        scanf("%d", &f);
    }
    return 0;
}