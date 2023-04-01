#include "transport.h"

int main(){
    TransportRoad TRtransport;

    
    programchoseTransport(&TRtransport);
    
    showPrice(TRtransport);
    return 0;
}