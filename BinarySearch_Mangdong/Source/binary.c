/*
* File: binary.c
* Author: Quach Minh Thinh
* Date: 10/04/2023
* Description: This file contains all the functions for the Birary Search.
*/
#include "binary.h"

/*
* Function: createNode
* Description: This function create a new Node
* Input:
*   inputData - an unsigned integer 16 bit value
* Output:
*   returns the Node with Node->Data=inputData and Node->Next=NULL
*/
Node *createNode(uint16_t input_data){
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->Next=NULL;
    newNode->Data=input_data;
    return newNode;
}
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
void addData(Node **node_address,uint16_t data){
    Node *p=*node_address;
    Node *newNode=createNode(data);
    if(*node_address==NULL){
       *node_address =newNode;
       //return;
    }
    else{
        if(newNode->Data<=p->Data) {
            newNode->Next=(*node_address);
            (*node_address)=newNode;
        }
        else{
            
            while (p->Next!=NULL && p->Next->Data<=newNode->Data)
            {
                p=p->Next;
            }
            newNode->Next=p->Next;
            p->Next=newNode;
        }
    } 
}

/*
* Function: display
* Description: This function print the linked list on screen
* Input:
*   node_address - an address of Node
* Output:
* the linked list printed on screen
*   
*/
void display(Node *node_address){
    while (node_address!=NULL)
    {
        printf("%d\t",node_address->Data);
        node_address=node_address->Next;
    }
    
}

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
int centerPoint(Node *arrPoint[],Node *node_address,int distance ){
    int index=1;
    int count=0;
    arrPoint[0]=node_address;
    while (node_address->Next!=NULL)
    {
        if(count==distance){
            arrPoint[index++]=node_address;
            count=0;
        }
        else{
            node_address=node_address->Next;
            count++;
        }
    }
    arrPoint[index]=node_address;
    return index;
}

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
List binarySearch(Node *arrPoint[],int size,uint16_t x){
    int left=0;
    int right=size;
    int center;
    List l;
    while (left <=right)
    {   center=(left+right)/2;
        if(arrPoint[center]->Data > x) right=center-1;
        else left=center+1;
    }
    
    l.first=arrPoint[right];
    l.Last=arrPoint[left];
    return l;

}

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
Node* search(List list,uint16_t x){
    Node *p=list.first;
    while (p->Next!=list.Last)
    {
        if((p->Data)==x) {
            return p;
            }
        p=p->Next;
    }
    return NULL;
}
