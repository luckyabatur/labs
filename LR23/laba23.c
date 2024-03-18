#include <stdio.h>

struct node
    {
        int value;
        struct node *left_child;
        struct node *righht_child;
    };

typedef struct node node;
    
struct Binary_tree
{
    node *header;
}
    

struct node *header;

node* add(struct node *cur, int val)
    {
    if (cur == NULL)
    {
        struct node el;
        el.value  = val;
        el.left_child = NULL;
        el.right_child = NULL;
        struct node *ptr = &el;
        return ptr;
    }
    return;
    }

    