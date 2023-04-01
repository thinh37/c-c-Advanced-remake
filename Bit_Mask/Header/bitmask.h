/*
* File: bitmask.h
* Author: Quach Minh Thinh
* Date: 31/03/2023
* Description: This is a header file for Bitmask
*/
#ifndef __BITMASK_H
#define __BITMASK_H
#include<stdio.h>
#include<stdint.h>
typedef enum{
    SHIRT       =    1<<0,
    TROUSERS    =    1<<1,
    DRESS       =    1<<2,
    BRUSH       =    1<<3,
    RING        =    1<<4,
    BAG         =    1<<5,
    SHOES       =    1<<6,
    BALO        =    1<<7
}STORE;
/*
* Function: addtoCart
* Description: This function Add product to cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
*   Sproduct - a STORE value
* Output:
*   The product added to cart
*/
void addtoCart(uint8_t *cart,STORE Sproduct);

/*
* Function: putoutCart
* Description: This function Take the product out of the cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
*   Sproduct - a STORE value
* Output:
*   The product has been removed from the cart
*/
void putoutCart(uint8_t *cart,STORE Sproduct);

#define CHECK_PRODUCT(PRODUCT) \
if(((*cart&PRODUCT)==PRODUCT)&((temp&PRODUCT)==PRODUCT)) {\
    printf("%s ALREADY IN THE CART \n",#PRODUCT);}\
else if((temp&PRODUCT)==PRODUCT) printf("%s DOESN'T EXIST IN CART\n",#PRODUCT);

/*
* Function: checkProduct
* Description: This function check the product inside the cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
*   Sproduct - a STORE value
* Output:
*   Print out which products are in the cart 
*   and which are not in the cart
*/
void checkProduct(uint8_t *cart,STORE Sproduct);

#define CHECK_CART(PRODUCT) if((*cart&PRODUCT)==PRODUCT) {i++; printf("%d   %s \n",i,#PRODUCT);}

/*
* Function: checkCart
* Description: This function check what products are in the cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
* Output:
*  Print the products in the cart
*/
void checkCart(uint8_t *cart);
#endif

