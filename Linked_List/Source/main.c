
#include"linked.h"
int main()
{   
    Node arr;
    /*PUSH Node*/
    push_back(&arr,6);
    push_back(&arr,7);
    push_back(&arr,8);
    push_back(&arr,9);
    push_back(&arr,10);
    /*Print Linked List on screen*/
    displayLinkedList(&arr);
    /*assign Data in index 2 by Data 9*/
    assign(&arr,2,9);
    /*Print Linked List on screen*/
    displayLinkedList(&arr);
    /*remove last Linked List*/
    pop_back(&arr);
    /*delete element at position 0*/
    erase(&arr,0);
    /*Print Linked List on screen*/
    displayLinkedList(&arr);
    printf("\nGet data: %d\n",getData(&arr,2));
    /*delete all elements of the Linked List container*/
    clear(arr.Next);
    
    return 0;
}