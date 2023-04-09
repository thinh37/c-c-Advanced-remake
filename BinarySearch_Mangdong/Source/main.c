#include "binary.h"

int main()
{
    Node *p=NULL;
    int n=10000;
    int random_number;
    /*PREPARATION DATA */
    /*Create a List data*/
    for(int i=0;i<=n;i++){
        random_number = rand() % 10000 + 1;
        addData(&p,random_number);
    }
    /*find the center points and Find the list in 
    which the number you want to find is inside*/
    Node *temp[100];
    n=n/100+1;
    n=centerPoint(temp,p,n);
    /*FIND DATA*/
    List l=binarySearch(temp,n,567);
    printf("SO CAN TIM NAM TRONG KHOANG (%d- %d)\n",l.first->Data,l.Last->Data);
    /*find a X Node address */
    printf("%d",search(l,567)->Data);
    
    return 0;
}