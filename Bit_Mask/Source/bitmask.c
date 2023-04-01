/*
* File: bitmask.c
* Author: Quach Minh Thinh
* Date: 31/03/2023
* Description: This file contains all the functions for the Bitmask.
*/
#include "bitmask.h"
/*
* Function: addtoCart
* Description: This function Add product to cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
*   Sproduct - a STORE value
* Output:
*   The product added to cart
*/
void addtoCart(uint8_t *cart,STORE Sproduct){
    *cart|=Sproduct;
}
/*
* Function: putoutCart
* Description: This function Take the product out of the cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
*   Sproduct - a STORE value
* Output:
*   The product has been removed from the cart
*/
void putoutCart(uint8_t *cart,STORE Sproduct){
    *cart&=~Sproduct;
}
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
void checkProduct(uint8_t *cart,STORE Sproduct){
    
    STORE temp=Sproduct;
    CHECK_PRODUCT(RING);
    CHECK_PRODUCT(SHOES);
    CHECK_PRODUCT(DRESS);
    CHECK_PRODUCT(BRUSH);
    CHECK_PRODUCT(TROUSERS);
    CHECK_PRODUCT(SHIRT);
    CHECK_PRODUCT(BALO);
    CHECK_PRODUCT(BAG);
}
/*
* Function: checkCart
* Description: This function check what products are in the cart
* Input:
*   cart - an unsigned integer 8 bit value pointer
* Output:
*  Print the products in the cart
*/
void checkCart(uint8_t *cart){
    int i=0;
    printf("STT TEN\n");
    CHECK_CART(RING);
    CHECK_CART(SHOES);
    CHECK_CART(DRESS);
    CHECK_CART(BRUSH);
    CHECK_CART(TROUSERS);
    CHECK_CART(SHIRT);
    CHECK_CART(BAG);
    CHECK_CART(BALO);
}

