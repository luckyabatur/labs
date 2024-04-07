#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "symbol.h"
#include "stack.h"

STACK *stack_create() {
    STACK *stack = (STACK*)malloc(sizeof(STACK));
    stack->body = 0;
    stack->size = 0;
    return stack;
}
// void stack_delete(STACK *stack) {
//     free(stack->body);
//     free(stack);
// }
bool stack_empty(STACK *stack) {
    return stack->size == 0;
}

void stack_push(STACK *stack, symbol t) {
    Item* i = malloc(sizeof(Item));
    i->data = t;
    i->prev = stack->body;
    stack->body = i;
    stack->size++;
}

symbol stack_pop(STACK *stack) {
    Item* i = stack->body;
    symbol res = i->data;
    stack->body = stack->body->prev;
    stack->size--;
    free(i);
    return res;
}

symbol stack_peek(STACK *stack) {
    return stack->body->data;
}
