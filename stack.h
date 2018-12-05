#include <stdbool.h>
#include <stdlib.h>

// typedef struct stack_info *StackInfo;
typedef struct stack *Stack;

/*
 * Creates a linked list stack that contain an element of 0
 * [0]->NULL
 */
Stack stack_init();

/*
 * Creates a single node for item
 * [item]->NULL
 */
Stack stack_create(int item);

/*
 * Return the number of element in stack
 */
size_t stack_size(Stack s);

/*
 * Push item on the stack
 * [Stack]->[item]->NULL
 */
void stack_push(Stack s, int item);

/*
 * Returns last element in the stack
 * [Stack ...]->[item]->NULL
 * [item]->NULL
 */
Stack stack_pop(Stack s);

/*
 * Returns the first element in stack
 */
Stack stack_peek(Stack s);

/*
 * Prints the current stack
 */
void stack_print(Stack s);

/*
 * Free memory, prevent memory leak
 */
void stack_destroy(Stack s);
