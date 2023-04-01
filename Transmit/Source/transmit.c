/*
* File: transmit.c
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This file contains all the functions for the Transmit.
*/
#include "transmit.h"
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
char *transmit_data(char *uid,char *data){
    int iCount,jCount=START;
    int lengthUid=strlen(uid);
    int lengthData=strlen(data);
    static char resuilt[sizeof(char)];
    for(iCount=0;iCount<lengthUid;iCount++){
        resuilt[iCount]=uid[iCount];
    }
    for(iCount=lengthUid;iCount<lengthUid+lengthData;iCount++){
        resuilt[iCount]=data[jCount];
        jCount++;
    }
    resuilt[iCount]='\0';
    char *k=resuilt;
    return k;
}
