
#include"vector.h"
int main()
{   
    vector array;
    vectorInit(&array);
    /*pushes an element to the last position of the vector*/
    array.vector_push_back(array.node,1);
    array.vector_push_back(array.node,2);
    array.vector_push_back(array.node,2);
    array.vector_push_back(array.node,3);
    array.vector_push_back(array.node,7);
    /*print the elements of the vector to the screen*/
    array.vector_displayLinkedList(array.node);

    /*It assigns a new value to the vector elements by replacing the old values*/
    array.vector_assign(array.node,2,9);
    /*print the elements of the vector to the screen*/
    array.vector_displayLinkedList(array.node);
    
    /*delete the last element a vector.*/
    array.vector_pop_back(array.node);
    /*print the elements of the vector to the screen*/
    array.vector_displayLinkedList(array.node);

    /*delete elements at position 0*/
    array.vector_erase(array.node,0);
    /*print the elements of the vector to the screen*/
    array.vector_displayLinkedList(array.node);

    /*get the data of the 2nd vector element*/
    printf("\nGet data: %d\n",array.vector_getData(array.node,2));

    /*remove all elements of the vector container.*/
    array.vector_clear(array.node->Next);
    
    return 0;
}