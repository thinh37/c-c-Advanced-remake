/*
* File: voidpointer.c
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This file contains all the functions for the voidpointer.
*/
#include"voidpointer.h"
/*
* Function: calculate_sum
* Description: This function calculates the sum of two integers
* Input:
*   firstValue - an integer value
*   secondValue - an integer value
* Output:
*   returns the sum of firstValue and secondValue
*/
void calculateSum(int firstValue,int secondValue){
    printf("%d + %d = %d",firstValue,secondValue,firstValue+secondValue);
}
/*
* Function: calculate_sum
* Description: This function calculates the subtrac of two integers
* Input:
*   firstValue - an integer value
*   secondValue - an integer value
* Output:
*   returns the subtrac of firstValue and secondValue
*/
void calculateSubtrac(int firstValue,int secondValue){
    printf("%d - %d = %d",firstValue,secondValue,firstValue-secondValue);
}