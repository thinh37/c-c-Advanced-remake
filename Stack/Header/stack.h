/*
* File: stack.h
* Author: Quach Minh Thinh
* Date: 03/04/2023
* Description: This is a header file for stack
*/
#ifndef __STACK_H
#define __STACK_H

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include <stdlib.h>
typedef struct{
        int size;
        uint8_t *data;
        int8_t top;
}Stack;

/*
* Function: initStack
* Description: This function init the stack
* Input:
*   stack - a data structure type Stack
* Output:
*   the stack is inited
*/
void initStack(Stack *st);

/*
* Function: isFull
* Description: This function checks whether the stack is full
* Input:
*   stack - a data structure type Stack
* Output:
*   return 1 if stack is full and 0 if stack is not full
*/
bool isFull(Stack *stack);

/*
* Function: isEmpty
* Description: This function checks whether the stack is Empty
* Input:
*   stack - a data structure type Stack
* Output:
*   return 1 if stack is Empty and 0 if stack is not Empty
*/
bool isEmpty(Stack *stack);

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

void push(Stack *stack,uint8_t value);

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
uint8_t pop(Stack *stack);

#endif