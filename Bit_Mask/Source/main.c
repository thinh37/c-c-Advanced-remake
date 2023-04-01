#include"bitmask.h"
uint8_t  CART; 
int main()
{   
    addtoCart(&CART,(STORE)(TROUSERS|SHIRT|BAG|BALO));
    checkProduct(&CART,(STORE)(BRUSH|SHIRT));
    checkCart(&CART);
    putoutCart(&CART,(STORE)(SHIRT));
    checkCart(&CART);
    return 0;
}

