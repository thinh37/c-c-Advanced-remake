#include"voidpointer.h"

int main()
{
    int intArr[]={2,5,7,8};
    char charArr[]="hello world";
    
    double doubleArr[]={4.6,3.6,3.6,2.9,2.4};
    void (*funtionArr[])(int,int)={&calculateSum,&calculateSubtrac};
    void *arr[4]={intArr,charArr,doubleArr};
    for(int i=0;i<4;i++){
        printf("%d\t",((int *)arr[0])[i]);
    }
    printf("\n");
    for(int i=0;;i++){
        if((((char*)arr[1])[i])=='\0') break;
        printf("%c",((char*)arr[1])[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++){
    printf("%f\t",((double*)arr[2])[0]);
    }
    printf("\n");
    ((void (*)(int,int))(((void **)arr[3])[0]))(10,2);
    printf("\n");
    ((void (*)(int,int))(((void **)arr[3])[1]))(9,2);
    return 0;
    
}
