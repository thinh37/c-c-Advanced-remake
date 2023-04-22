#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;

class rectangle{
private:
    int16_t length ;
    int16_t width;
public:
    rectangle(int16_t length = 0, int16_t width = 0);
    void setLength(int16_t length);
    void setWidth(int16_t width);
    int16_t getLength();
    int16_t getWidth();
};

rectangle::rectangle(int16_t length , int16_t width ){
    this->length=length;
    this->width=width;
}

void rectangle::setLength(int16_t length){
    this->length=length;
}

void rectangle::setWidth(int16_t width){
    this->width=width;
}

int16_t rectangle::getWidth(){
    return this->width;
}
int16_t rectangle::getLength(){
    return this->length;
}

class Calculate{
    private:
    rectangle hcn;
    public:
    Calculate(rectangle hcn);
    void setCalculate(rectangle hcn);
    uint16_t area();
    uint16_t perimeter();
    double diagonal();
    bool checksquare();
};
Calculate::Calculate(rectangle hcn){
    this->hcn=hcn;
}

void Calculate::setCalculate(rectangle hcn){
    this->hcn=hcn;
}

uint16_t Calculate::area(){
    return (hcn.getLength() * hcn.getWidth());
}

uint16_t Calculate::perimeter(){
    return (hcn.getLength() + hcn.getWidth())*2;
}

double Calculate::diagonal(){
    return sqrt(pow(hcn.getLength(),2)+pow(hcn.getWidth(),2));
}

bool Calculate::checksquare(){
    return hcn.getLength() == hcn.getWidth();
}

int main(int argc, char const *argv[])
{
    rectangle a(3,4);
    Calculate tinh(a);
    
    printf("chu vi hinh chu nhat: %d \n",tinh.perimeter());
    printf("dien tich hinh chu nhat: %d \n",tinh.area());
    printf("duong cheo hinh chu nhat : %f \n",tinh.diagonal());
    if(tinh.checksquare()){
        printf("Day la hinh vuong\n");
    }else{
        printf("Day khong la hinh vuong\n");
    }
    a.setLength(5);
    a.setWidth(5);
    tinh.setCalculate(a);
    printf("chu vi hinh chu nhat: %d \n",tinh.perimeter());
    printf("dien tich hinh chu nhat: %d \n",tinh.area());
    printf("duong cheo hinh chu nhat : %f \n",tinh.diagonal());
    if(tinh.checksquare()){
        printf("Day la hinh vuong\n");
    }else{
        printf("Day khong la hinh vuong\n");
    }

    return 0;
}





