#include "transmit.h"
int main()
{
  char *data;
  data=transmit_data((char*)"1010",(char*)"12345");
  printf("data %s transmit",data);
}