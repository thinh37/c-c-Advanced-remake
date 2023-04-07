/*
* File: queue.c
* Author: Quach Minh Thinh
* Date: 08/04/2023
* Description: This file contains all the functions for the Queue.
*/
#include"queue.h"

/*
* Function: InitQueue
* Description: This function init the InitQueue
* Input:
*   queue - a data structure type Queue
*   size  - a size of Queue
* Output:
*   the Queue is inited
*/
void initQueue(Queue *queue,int size)
{
    queue->size=size;
    queue->front=queue->rear=-1;
    queue->data=(uint8_t *)malloc(queue->size*sizeof(uint8_t));
}
/*
* Function: isFull
* Description: This function checks whether the queue is full
* Input:
*   queue - a data structure type Queue
* Output:
*   return 1 if queue is full and 0 if queue is not full
*/
bool isFull(Queue queue){
    return (queue.rear==queue.size-1);
}
/*
* Function: enQueue
* Description: This function add the element to the queue.
* Input:
*   stack - a data structure type Queue
*   value - an unsigned integer 8 bit value
* Output:
*   the element is added to the queue if queue not full 
*   and print is full if queue full
*/
void enQueue(Queue *queue,uint8_t value){
    if(isFull(*queue))
        printf("Queue is Full\n");
    else{
        queue->data[++queue->rear]=value;
    }
}
/*
* Function: isEmpty
* Description: This function checks whether the queue is Empty
* Input:
*   queue - a data structure type Queue
* Output:
*   return 1 if queue is Empty and 0 if queue is not Empty
*/
bool isEmpty(Queue queue){
    return (queue.front)==(queue.rear);
}
/*
* Function: deQueue
* Description: This function removes the first element from the queue
* Input:
*   queue - a data structure type Queue
*   value - an unsigned integer 8 bit value
* Output:
*   Returns the retrieved value  
*/
uint8_t deQueue( Queue *queue)
{
    uint8_t x=0;
    if(isEmpty(*queue))
        printf("Queue is Empty\n");
    else{
        x=queue->data[0];
        for(int i=0;i<queue->rear;i++){
            queue->data[i]=queue->data[i+1];
        }
        queue->rear--;
    }
    return x;
}

/*
* Function: Display
* Description: This function display the elements from the queue
* Input:
*   queue - a data structure type Queue
* Output:
*   queue elements are printed to the screen 
*/
void Display(Queue queue)
{

	for(int i=(queue.front+1);i<=queue.rear;i++){
    printf("%d ",queue.data[i]);
	}
 printf("\n");
}
