// gcc -Wall -Werror -std=gnu99 -O -lm -o stack stack_interface.c stack.c
//

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void) {
    Stack s = stack_init();
    int input;
    while(1) {
        puts("0: Quit()");
        puts("1: Push()");
        puts("2: Pop()");
        puts("3: Print()");
        puts("4: Peek()");
        puts("5: Size()");
        scanf("%d", &input);

        puts(" ");
        if(input == 0) {
            break;
        } else if(input == 1) {
            int item;
            printf("Enter item: ");
            scanf("%d", &item);
            stack_push(s, item);
        } else if(input == 2) {
            Stack pop = stack_pop(s);
            if (pop != NULL) free(pop);
        } else if(input == 3) {
            stack_print(s);
        } else if(input == 4) {
            // Stack peek = stack_peek(s);
        } else if(input == 5) {
            printf("Size: %zu\n", stack_size(s));
        }
        puts(" ");
    }
    stack_destroy(s);

    return EXIT_SUCCESS;
}
