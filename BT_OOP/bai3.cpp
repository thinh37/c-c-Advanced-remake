#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

class circle{
    private:
        int16_t radius;
    public:
        circle(int16_t radius=0);
        void setRadius(int16_t r);
        int16_t getRadius();
};

circle::circle(int16_t radius){
    this->radius=radius;
}

void circle::setRadius(int16_t r){
    this->radius=r;
}

int16_t circle::getRadius(){
    return this->radius;
}

class Calculate{
    private:
        circle hinhtron;
    public:
        Calculate(circle hinhtron);
        void setCalculate(circle hinhtron);
        double area();
        double perimeter();
};

Calculate::Calculate(circle hinhtron){
    this->hinhtron=hinhtron;
}
void Calculate::setCalculate(circle hinhtron){
    this->hinhtron=hinhtron;
}
double  Calculate::area(){
    return pow(hinhtron.getRadius(),2)*M_PI;
}
double Calculate::perimeter(){
    return 2*hinhtron.getRadius()*M_PI;
}

int main(int argc, char const *argv[])
{
    circle a(5);
    Calculate tinh(a);
    printf("Chu Vi hinh tron:%f \n",tinh.perimeter());
    printf("Dien tich hinh tron: %f \n",tinh.area());

    a.setRadius(6);
    tinh.setCalculate(a);
    printf("Chu Vi hinh tron:%f \n",tinh.perimeter());
    printf("Dien tich hinh tron: %f \n",tinh.area());
    return 0;
}
