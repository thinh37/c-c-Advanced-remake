#include "stack.h"

int main()
{
    Stack stack;
    initStack(&stack);
    for(int i=0;i<5;i++){
        push(&stack,i*2);
    }
    for(int i=0;i<5;i++){
        printf("pop: %d\n",pop(&stack));
    }
    
    return 0;
}
