#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;

class Diem {
private:
    int8_t x;
    int8_t y;
public:
    Diem(int8_t x = 0, int8_t y = 0);
    int8_t getX();
    int8_t getY();
};

Diem::Diem(int8_t x, int8_t y){
    this->x=x;
    this->y=y;
}

int8_t Diem::getX()  { 
    return this->x; 
}
int8_t Diem::getY()  { 
    return this->y; 
}

class Khoangcach{
    protected:
        Diem A;
        Diem B;
    public:
        void setKhoangcach(Diem A, Diem B);
        double tinhKhoangcach();
};
void Khoangcach::setKhoangcach(Diem A, Diem B){
    this->A=A;
    this->B=B;
}
double Khoangcach::tinhKhoangcach(){
    return sqrt(pow(  A.getX()-B.getX(),2) +  pow(A.getY()-B.getY(),2));
}

class Dientich : private Khoangcach{
    private:
        Diem C;
    public:
        void setDientich(Diem A, Diem B,Diem C);
        double tinhDientich();
};

 void Dientich::setDientich(Diem A, Diem B,Diem C){
    this->A=A;
    this->B=B;
    this->C=C;
 }
 
double Dientich::tinhDientich(){
    Khoangcach kc;
    kc.setKhoangcach(B,C);
    double a= kc.tinhKhoangcach();

    kc.setKhoangcach(A,C);
    double c=kc.tinhKhoangcach();

    kc.setKhoangcach(A,B);
    double b=kc.tinhKhoangcach();

    double s=(a+b+c)/2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(int argc, char const *argv[])
{
    
    
    Diem A(0,0);
    Diem B(3,0);
    Diem C(0,4);
    Khoangcach kc;
    kc.setKhoangcach(A,C);
    cout<<kc.tinhKhoangcach()<<endl;

    Dientich dt;
    dt.setDientich(A,B,C);
    cout<<dt.tinhDientich();
    return 0;
}


