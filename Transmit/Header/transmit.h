/*
* File: linked.h
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This is a header file for transmit
*/
#ifndef __TRANSMIT_H
#define __TRANSMIT_H
#include <stdio.h>
#include <string.h>
#define START 0
/*
* Function: transmitData
* Description: The function concatenate 
* string uid with string data to transmit
* Input:
*   n - an integer value 
*   uid - an address of char uid(user ID)
*   data - an address of char data(Data user) 
* Output:
*   return string concatenated form string uid and string data
*/
char *transmit_data(char *uid,char *data);
#endif