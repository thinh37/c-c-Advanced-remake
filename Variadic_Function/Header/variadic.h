/*
* File: linked.h
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This is a header file for Variadic
*/
#ifndef __VARIADIC_H
#define __VARIADIC_H
#include<stdio.h>
#include<stdarg.h>
/*
* Function: calculate_sum
* Description: The function calculate sum of n input parameter values
* Input:
*   n - an integer value 
* Output:
*   return sum of n input parameter values
*/
double calculate_sum(int n, ...);
#endif