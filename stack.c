#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// struct stack_info {
//     Stack head;
//     Stack tail;
//     size_t size;
// };

struct stack {
    int item;
    Stack next;
    Stack prev;
};

Stack stack_init() {
    Stack s = malloc(sizeof(struct stack));
    s->item = 0;
    s->next  = NULL;
    s->prev  = NULL;

    return s;
}

Stack stack_create(int item) {
    Stack s = malloc(sizeof(struct stack));
    s->item = item;
    s->next  = NULL;
    s->prev  = NULL;

    return s;
}

size_t stack_size(Stack s) {
    size_t size = 0;
    Stack curr;
    for(curr = s; curr != NULL; curr = curr->next)
        size++;

    return size;
}

void stack_push(Stack s, int item) {
    Stack item_s = stack_create(item);
    if(s == NULL) s = item_s;
    Stack curr;
    for(curr = s; curr->next != NULL; curr = curr->next);
    curr->next = item_s;
    item_s->prev = curr;
}

Stack stack_pop(Stack s) {
    if(s == NULL) return NULL;      // size 0
    if(s->next == NULL) {           // size 1
        printf("Cannot Pop Last Item in Stack\n");
        return NULL;
    }

    Stack curr;
    for(curr = s; curr->next != NULL; curr = curr->next);
    Stack pop = stack_create(curr->item);
    curr->prev->next = NULL;
    free(curr);

    return pop;
}

Stack stack_peek(Stack s) {
    if(s == NULL) return NULL;

    return s;
}

void stack_print(Stack s) {
    if(s == NULL) printf("No Stack");

    Stack curr;
    for(curr = s; curr != NULL; curr = curr->next)
        printf("%d, ", curr->item);
    printf("\n");
}

void stack_destroy(Stack s) {
    if(s == NULL) return;

    Stack tmp;
    while(s != NULL) {
        tmp = s;
        s = s->next;
        free(tmp);
    }
}
