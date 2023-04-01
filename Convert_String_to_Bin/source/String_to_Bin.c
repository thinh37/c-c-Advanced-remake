/*
* File: String_to_Bin.c
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This file contains all the functions for the String to Binary.
*/
#include "String_to_Bin.h"
void convertStringtoBin(char *a){
int i,j;
for( i=0;a[i]!='\0';i++){
  char Binary[BYTE];
  int t=a[i];
  for(j=BYTE-1;j>=0;j--){
    if(t%2==0){
      Binary[j]=Bit_0;
    }else{
      Binary[j]=Bit_1;
    }
    t=t/2;
  }
  printf("%c: %s\n",a[i],Binary);
}
}
