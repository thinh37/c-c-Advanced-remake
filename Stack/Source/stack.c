
/*
* File: stack.h
* Author: Quach Minh Thinh
* Date: 03/04/2023
* Description: This file contains all the functions for the Stack.
*/
#include "stack.h"
/*
* Function: initStack
* Description: This function init the stack
* Input:
*   stack - a data structure type Stack
* Output:
*   the stack is inited
*/
void initStack(Stack *st)
{
 printf("Enter Size please!!! :");
 scanf("%d",&st->size);
 st->top=-1;
 st->data=(uint8_t *)malloc(st->size*sizeof(uint8_t));
}
/*
* Function: isFull
* Description: This function checks whether the stack is full
* Input:
*   stack - a data structure type Stack
* Output:
*   return 1 if stack is full and 0 if stack is not full
*/
bool isFull(Stack *stack){
     return (stack->top == stack->size-1);
}
/*
* Function: isEmpty
* Description: This function checks whether the stack is Empty
* Input:
*   stack - a data structure type Stack
* Output:
*   return 1 if stack is Empty and 0 if stack is not Empty
*/
bool isEmpty(Stack *stack){
     return (stack->top == -1) ;
}
/*
* Function: push
* Description: This function Adds an element to the top of the stack.
* Input:
*   stack - a data structure type Stack
*   value - an unsigned integer 8 bit value
* Output:
*   the element is added to the stack if stack not full 
*   and print is full if stack full
*/

void push(Stack *stack,uint8_t value){
     if(isFull(stack)){
        printf("is full\n");          
     }else{
         stack->data[++stack->top] = value;
    }
}
/*
* Function: pop
* Description: This function removes the topmost element from the stack
* Input:
*   stack - a data structure type Stack
*   value - an unsigned integer 8 bit value
* Output:
*   Returns the retrieved value  
*/
#define ISEMPTY 0
uint8_t pop(Stack *stack){
     if(isEmpty(stack)){
        printf("is Empty\n");
        return ISEMPTY;          
     }else{
        return stack->data[stack->top--];
     }   
}