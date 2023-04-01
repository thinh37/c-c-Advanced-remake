/*
* File: transport.h
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This is a header file for transport
*/
#ifndef __TRANSPORT_H
#define __TRANSPORT_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
typedef enum{
    COMMERCIAL_AIRCRAFT=1352,
    HELICOPTER=751,
    TAXI=310,
    BICYCLE=507,
    MOTORBIKE=684,
    SHIP=308,
    CANO=289
}Transport;
typedef union{
    Transport helicopter;
    Transport commercial_aircraft;
}Airline;
typedef union{
    Transport taxi;
    Transport motorbike;
    Transport bicycle;
}Road;
typedef union{
    Transport ship;
    Transport cano;
}WaterWay;
typedef union{
    Airline airline;
    Road road;
    WaterWay waterway;
    Transport transport;
}TransportRoad;
/*
* Function: sumLenght
* Description: This function use to calculate sum of characters of string
* Input:
*   a - a char value
* Output:
*   return sum of characters of string
*/
int sumLenght(char a[100]);
/*a macro function of transport*/
#define TRANSPORT(member, quantity, ...)                                 \
    member                                                               \
    char key_value[quantity][20];                                        \
    static int index = 0;                                                \
    int button = 0;                                                      \
    __VA_ARGS__                                                          \
    printf("Please choose a transport:\n");                              \
    for (int i = 0; i < index; i++)                                      \
    {                                                                    \
        printf("PUSH %d: %s\n",i+1, key_value[i]);                       \
    }                                                                    \
    printf("PUSH 0: Exit\n");                                           \
    printf("PLEASE PRESS THE BUTTON: ...");                              \
    scanf("%d", &button);                                                \
    for (int i = 0; i < index; i++)                                      \
    {                                                                    \
        if((button-1) == i){                                             \
            printf("YOUR CHOICE: %s\n", key_value[i]);                   \
            printf("YOUR CHOICE: %s\n",key_value[i]);                    \
            TRtransport->transport=(Transport)(sumLenght(key_value[i])); \
        }                                                                \
    }                                                                    \
    }
/*a macro function of road*/
#define ROAD(name)                                                      \
void name(TransportRoad *TRtransport){

/*a macro name of transport*/
#define NAME_TRANSPORT(value)                                                          \
    strcpy(key_value[index], (char*)value);                                         \
    index++; 
/*a macro munber of transport*/
#define MUMBER_TRANSPORT(number) number

/*
* Function: programchoseTransport
* Description: This function use to chose Transport
* Input:
*   TRtransport - an type struct TransportRoad
* Output:
*   Display the Transport of your choice
*/
void programchoseTransport(TransportRoad *TRtransport);

#define FARE(money) \
printf("FARE:"); \
printf(#money);
/*
* Function: showPrice
* Description: This function use to show price
* Input:
*   TRtransport - an type struct TransportRoad
* Output:
*   Display the price of the Transport of your choice
*/
void showPrice(TransportRoad TRtransport);
#endif