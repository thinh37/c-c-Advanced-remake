/*
* File: transport.c
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This file contains all the functions for the transport
*/
#include "transport.h"
/*
* Function: sumLenght
* Description: This function use to calculate sum of characters of string
* Input:
*   a - a char value
* Output:
*   return sum of characters of string
*/
int sumLenght(char a[100]){
    int i=0;
    int sum=0;
    while (a[i]!='\0')
    {
        sum=sum+a[i];
        i++;
    }
    return sum;
}

TRANSPORT(ROAD(choseAirline),MUMBER_TRANSPORT(2),
                NAME_TRANSPORT("COMMERCIAL AIRCRAFT")
                NAME_TRANSPORT("HELICOPTER")
                );

TRANSPORT(ROAD(choseRoad),MUMBER_TRANSPORT(3),
                NAME_TRANSPORT("TAXI")
                NAME_TRANSPORT("BICYCLE")
                NAME_TRANSPORT("MOTORBIKE")
                );
TRANSPORT(ROAD(choseWaterWay),MUMBER_TRANSPORT(2),
                NAME_TRANSPORT("SHIP")
                NAME_TRANSPORT("CANO")
                );

/*
* Function: programchoseTransport
* Description: This function use to chose Transport
* Input:
*   TRtransport - an type struct TransportRoad
* Output:
*   Display the Transport of your choice
*/
void programchoseTransport(TransportRoad *TRtransport){
	
    printf("What do you want to travel with?\n");
    printf("Push 1: Airline\n");
    printf("Push 2: Road\n");
    printf("Push 3: Water Way\n");
    printf("Push 0: Exit\n");
    int button = 0;
    scanf("%d", &button);

    switch (button)
    {
    case 1:
        choseAirline(TRtransport);
        break;
    case 2:
        choseRoad(TRtransport);
        break;
    case 3:
        choseWaterWay(TRtransport);
        break;
    case 0:
        exit(0);
    default:
        break;
    }
}
/*
* Function: showPrice
* Description: This function use to show price
* Input:
*   TRtransport - an type struct TransportRoad
* Output:
*   Display the price of the Transport of your choice
*/
void showPrice(TransportRoad TRtransport){
    
   switch (TRtransport.transport)
   {
   case COMMERCIAL_AIRCRAFT:
        FARE(1.000.000 VND);
    break;
   case HELICOPTER:
        FARE(1.200.000 VND);
    break;
    case TAXI:
        FARE(120.000 VND);
    break;
    case MOTORBIKE:
        FARE(80.000 VND);
    break;
    case BICYCLE:
        FARE(20.000 VND);
    break;
    case SHIP:
        FARE(200.000 VND);
    break;
    case CANO:
        FARE(300.000 VND);
    break;
   default:
    break;
}
}