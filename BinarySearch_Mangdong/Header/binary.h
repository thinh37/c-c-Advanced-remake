/*
* File: binary.h
* Author: Quach Minh Thinh
* Date: 10/04/2023
* Description: This is a header file for Birary Search
*/
#ifndef __BINARY_SEARCH_H
#define __BINARY_SEARCH_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct node
{
    uint16_t Data;
    struct node *Next;
}Node;
/*
* Function: createNode
* Description: This function create a new Node
* Input:
*   inputData - an unsigned integer 8 bit value
* Output:
*   returns the Node with Node->Data=inputData and Node->Next=NULL
*/
Node *createNode(uint16_t input_data);

/*
* Function: addData
* Description: This function adds 1 node to the linked list 
* in the correct position in order
* Input:
*   inputData - an unsigned integer 16 bit value
*   node_address - pointer to pointer
* Output:
* Nodes are added and placed in the correct place in order
*   
*/
void addData(Node **node_address,uint16_t data);

/*
* Function: display
* Description: This function print the linked list on screen
* Input:
*   node_address - an address of Node
* Output:
* the linked list printed on screen
*   
*/
void display(Node *node_address);

/*
* Function: centerPoint
* Description: This function find center nodes
* Input:
*   node_address - an address of Node
*   arrPoint- an address of Node array
*   distance  - distance between points
* Output:
* the addresses of the center nodes are stored in an array
* and return size of array
*   
*/
int centerPoint(Node *arrPoint[],Node *node_address,int distance );

typedef struct LIST
{
	Node *first;
    Node * Last;
}List;

/*
* Function: binarySearch
* Description: This function Find the list in 
* which the number you want to find is inside
* Input:
*   x - an unsigned integer 16 bit value
*   size - an integer value -size of arr
*   arr- an address of Node array
* Output:
* The list in 
* which the number you want to find is inside
*   
*/
List binarySearch(Node *arrPoint[],int size,uint16_t x);

/*
* Function: search
* Description: This function find a X Node address 
* Input:
*   x - an unsigned integer 16 bit value
*   list- contains the start and end addresses of the linked list
* Output:
* return the address of X
*   
*/
Node* search(List list,uint16_t x);
#endif