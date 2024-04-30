#include <stdio.h>
#include "list.h"

int main(void)
{
    List li;
    List* l = &li;
    int f, index, a;
    Iterator i, last, first;
    Iterator empty = { NULL };
    colors element;
    Create(l);
    printf("1 - печать списка\n2 - вставка нового элемента в список\n3 - Удаление элемента из списка\n4 - Подсчёт длины списка\n5 - переставить элементы списка в обратном порядке\n6 - завершить работу\n");

    scanf("%d", &f);

    while (f != 6)
    {   
        last = Last(l);
        switch (f)
        {
        case 1:
            PrintList(l);
            break;
        case 2:
            scanf("%d", &index);
            scanf("%d", &element);
            i = Index(l, index);
            if (Equal(&i, &empty))
            {
                printf("Некорректный индекс\n");
                break;
            } 
            i = Insert(l, &i, element);
            if (Equal(&i, &last))
            {
                printf("Не выделилась память\n");
                break;
            }
            printf("Элемент добавлен\n");
            first = First(l);
            break;
        case 3:
            scanf("%d", &index);
            i = Index(l, index);
            if (Equal(&i, &empty))
            {
                printf("Некорректный индекс\n");
                break;
            } 
            i = Delete(l, &i);
            if (Equal(&i, &empty))
            {
                printf("Попытка удалить барьерный элемент\n");
                break;
            }
            printf("Элемент удалён\n");
            break;
        case 4:
            printf("Длина списка: %d\n", Size(l));
            break;
        case 5:
            Reverse(l);
            printf("Список реверсирован\n");
            break;
        case 6:
            break;
        default:
            printf("Invalid input\n");
        }
        scanf("%d", &f);
    }
    return 0;
}
