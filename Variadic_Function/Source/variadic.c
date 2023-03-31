/*
* File: linked.h
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This file contains all the functions for the Variadic.
*/
#include "variadic.h"
/*
* Function: calculate_sum
* Description: The function calculate sum of n input parameter values
* Input:
*   n - an integer value 
* Output:
*   return sum of n input parameter values
*/
double calculate_sum(int n, ...){
    double sum = 0.0;
    va_list ptr;
    va_start(ptr, n);
    
    int i;
    for (i = 0; i < n; i++){
       int temp=va_arg(ptr,double);
       	if(temp!=0){
       	    sum =sum + temp;
	    }
	    else{
		    ptr=ptr-sizeof(ptr);
		    sum =sum + va_arg(ptr,int);
	    }
    }
    return sum;
}