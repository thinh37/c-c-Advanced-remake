/*
* File: linked.h
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This is a header file for Linked List
*/
#ifndef __LINKED_H
#define __LINKED_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define START 0
typedef struct node
{
    uint8_t Data;
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
Node *createNode(uint8_t inputData);
#define FIRST_NODE 0
#define NOT_FIRST_NODE 1
/*
* Function: push_back
* Description: This function create a Linked List
* Input:
*   inputData - an unsigned integer 8 bit value
*   node_address- an address of Node
* Output:
*   Create new Node and push back Linked List
*/
void push_back(Node *node_address,uint8_t inputData);
/*
* Function: displayLinkedList
* Description: This function Display Data of Linked List
* Input:
*   node_address- an address of Node
* Output:
*   Data of Linked List will print on screen
*/
void displayLinkedList(Node *node_address);
/*
* Function: assign
* Description: This function It assigns a new value to the Node elements 
* by replacing the old values.
* Input:
*   node_address  - an address of Node
*   index - an integer value 
*   input_data - an unsigned integer 8 bit value
* Output:
*   old value is replaced
*/
void assign(Node *node_address,int index,uint8_t input_data);
/*
* Function: pop_back
* Description: This function used to remove the last element
* Input:
*   node_address- an address of Node
* Output:
*   the last element is removed
*/
void pop_back(Node *node_address);
/*
* Function: erase
* Description: The function is used to remove elements 
* according to the container position
* Input:
*   node_address- an address of Node
*   index - an integer value
* Output:
*   the Node element is removed
*/
void erase(Node *node_address,int index);
/*
* Function: clear
* Description: The function is used to remove 
* all elements of the Linked list container.
* Input:
*   node_address- an address of Node
* Output:
*   Linked list container is removed
*/
void clear(Node *node_address);
#define NOT_FIND -1
/*
* Function: getData
* Description: The function is get Data of Node
* Input:
*   node_address- an address of Node
*   index - an integer value
* Output:
*   return Data of Node
*/
uint8_t getData(Node *node_address, int index);
#endif