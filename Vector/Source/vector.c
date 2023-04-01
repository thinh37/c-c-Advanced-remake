/*
* File: vector.c
* Author: Quach Minh Thinh
* Date: 31/03/2023
* Description: This file contains all the functions for the Vector.
*/
#include"vector.h"
/*
* Function: createNode
* Description: This function create a new Node
* Input:
*   input_data - an unsigned integer 8 bit value
* Output:
*   returns the Node with Node->Data=input_data and Node->Next=NULL
*/
Node *createNode(uint8_t input_data){
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->Next=NULL;
    newNode->Data=input_data;
    return newNode;
}
/*
* Function: push_back
* Description: This function create a Linked List
* Input:
*   input_data - an unsigned integer 8 bit value
*   node_address- an address of Node
* Output:
*   Create new Node and push back Linked List
*/
void push_back(Node *node_address,uint8_t input_data){
    static uint8_t check =FIRST_NODE;
    if(check ==FIRST_NODE){
        node_address->Data=input_data;
        node_address->Next=NULL;
        check =NOT_FIRST_NODE;
    }else{
        while (node_address->Next !=NULL)
        {
            node_address=node_address->Next;
        }
        node_address->Next=createNode(input_data);
    }
}
/*
* Function: displayLinkedList
* Description: This function Display Data of Linked List
* Input:
*   node_address- an address of Node
* Output:
*   Data of Linked List will print on screen
*/
void displayLinkedList(Node *node_address){
    printf("\n");
    while (node_address!=NULL)
    {
        printf("%d\t",node_address->Data);
        node_address=node_address->Next;
    }
}
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
void assign(Node *node_address,int index,uint8_t input_data){
    int iCount = START;
    while (node_address->Next != NULL && iCount != index)
    {
        iCount++;
        node_address= node_address->Next;
    }
    node_address->Data=input_data;
}
/*
* Function: pop_back
* Description: This function used to remove the last element
* Input:
*   node_address- an address of Node
* Output:
*   the last element is removed
*/
void pop_back(Node *node_address){
        while (node_address->Next->Next != NULL)
        {
            node_address=node_address->Next;
        }
       node_address->Next=NULL;
}
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
void erase(Node *node_address,int index){
    int iCount=START;
    if(index==FIRST_NODE){
        node_address->Data=node_address->Next->Data;
        index=NOT_FIRST_NODE;
    }
    while (node_address->Next!=NULL&& iCount != (index-1))
    {
        iCount++;
        node_address=node_address->Next;
    }
    node_address->Next=node_address->Next->Next;
}
/*
* Function: clear
* Description: The function is used to remove 
* all elements of the Linked list container.
* Input:
*   node_address- an address of Node
* Output:
*   Linked list container is removed
*/
void clear(Node *node_address){
    Node *temp=node_address;
    while(node_address->Next!=NULL){
        temp=temp->Next;
        free(node_address);
        node_address=temp;
    }
    free(node_address);
    printf("CLEAR-END");
}
/*
* Function: getData
* Description: The function is get Data of Node
* Input:
*   node_address- an address of Node
*   index - an integer value
* Output:
*   return Data of Node
*/
uint8_t getData(Node *node_address, int index){
    int iCount=START;
    while (node_address->Next!=NULL)
    {
        if(iCount==index) return (node_address->Data); 
        node_address=node_address->Next;
        iCount++;
    }
    if(index>iCount) return NOT_FIND;
    return node_address->Data;
}
/*
* Function: vectorInit
* Description: The function to Init function of vector
* Input:
*   Value- an address of vector
* Output:
*   function of vector init
*/
void vectorInit(vector *Value){
    Value->node=(Node*)malloc(sizeof(Node));
    Value->vector_push_back=&push_back;
    Value->vector_displayLinkedList=&displayLinkedList;
    Value->vector_clear=&clear;
    Value->vector_assign=&assign;
    Value->vector_getData=&getData;
    Value->vector_pop_back=&pop_back;
    Value->vector_erase=&erase;
}
