/*
* File: queue.h
* Author: Quach Minh Thinh
* Date: 08/04/2023
* Description: This is a header file for Queue
*/
#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <stdint.h>
typedef struct 
{
 int size;
 int8_t front;
 int8_t rear;
 uint8_t *data;
}Queue;
/*
* Function: InitQueue
* Description: This function init the InitQueue
* Input:
*   queue - a data structure type Queue
*   size  - a size of Queue
* Output:
*   the Queue is inited
*/
void initQueue(Queue *queue,int size);

/*
* Function: isFull
* Description: This function checks whether the queue is full
* Input:
*   queue - a data structure type Queue
* Output:
*   return 1 if queue is full and 0 if queue is not full
*/
bool isFull(Queue queue);

/*
* Function: enQueue
* Description: This function add the element to the queue.
* Input:
*   queue - a data structure type Queue
*   value - an unsigned integer 8 bit value
* Output:
*   the element is added to the queue if queue not full 
*   and print is full if queue full
*/
void enQueue(Queue *queue,uint8_t value);

/*
* Function: isEmpty
* Description: This function checks whether the queue is Empty
* Input:
*   queue - a data structure type Queue
* Output:
*   return 1 if queue is Empty and 0 if queue is not Empty
*/
bool isEmpty(Queue queue);

/*
* Function: deQueue
* Description: This function removes the first element from the queue
* Input:
*   queue - a data structure type Queue
* Output:
*   Returns the retrieved value  
*/
uint8_t deQueue(Queue *queue);

/*
* Function: deQueue
* Description: This function display the elements from the queue
* Input:
*   queue - a data structure type Queue
* Output:
*   queue elements are printed to the screen 
*/
void Display(Queue queue);
#endif
