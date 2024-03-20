#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value;
    struct node* l;
    struct node* r;
} node;

node* add(node* cur, int value)
{
    if (cur == NULL)
    {
        cur = malloc(sizeof(node));
        cur->value = value;
        cur->l = NULL;
        cur->r = NULL;
        return cur;
    }
    else if (value < cur->value)
        cur->l = add(cur->l, value);
    else
        cur->r = add(cur->r, value);    
    return cur;
}


node* max(node* cur)
{
    if (cur->r == NULL)
        return cur;
    return max(cur->r);
}


node* rm(node* cur, int value, int flag)
{
    if (cur == NULL)
    {
        printf("Элемента %d нет в нашем дереве\n", value);
        return NULL;
    }
    
    if (cur->value == value)
    {
        if (flag == 0)
            printf("Элемент %d удалён из нашего дерева\n", value);
        if (cur->l == NULL && cur->r == NULL)
        {
            free(cur);
            return NULL;
        }

        else if (cur->l == NULL)
        {
            node *new_cur = cur->r;
            free(cur);
            return new_cur;
        }

        else if (cur->r == NULL)
        {
            node *new_cur = cur->l;
            free(cur);
            return new_cur;
        }

        else
        {
            node *rez = max(cur->l);
            cur->value = rez->value;
            cur->l = rm(cur->l, rez->value, 1);
            return cur;
        }
        
    }
    else if (value < cur->value)
        cur->l = rm(cur->l, value, flag);
    else
        cur->r =  rm(cur->r, value, flag);
    return cur;
}


void showtree(node* cur, int n)
{   
    for (int i = 0; i < n; i++) printf("   ");
    printf("%d\n", cur->value);
    if (cur->l !=  NULL)
        showtree(cur->l, n+1);
    if (cur->r !=  NULL)    
        showtree(cur->r, n+1);
}


int degree(node *cur)
{
    if (cur == NULL)
        return 0;
    int sons = 0;
    if (cur->l != NULL)
        sons++;
    if (cur->r != NULL)
        sons++;
    if (cur->value == sons)
        return 1 + degree(cur->l) + degree(cur->r);
    return degree(cur->l) + degree(cur->r);
}


int main(void)
{
    node* root = NULL;
    int f, value;

    printf("0 x - добавить\n1 x - удалить\n2 - вывести дерево\n3 - посчитать функцию\n4 - завершить работу\n");

    scanf("%d", &f);

    while (f != 4)
    {
        switch (f)
        {
        case 0:
            scanf("%d", &value);
            if (root == NULL)
                root = add(root, value);
            else
                add(root, value);
            printf("Элемент %d добавлен в наше дерево\n", value);
            break;
        case 1:
            scanf("%d", &value);
            root = rm(root, value, 0);
            break;
        case 2:
        
            if (root != NULL)
            {
                printf("Наше дерево:\n");
                showtree(root, 0);
            }
            else
                printf("Дерева нет :(\n");         
            break;
        case 3:
            printf("Количество вершин, степень которых совпадает со значением: %d\n", degree(root));
            break;
        case 4:
            break;
        default:
            printf("Invalid input\n");
        }
        scanf("%d", &f);
    }
    return 0;
}
