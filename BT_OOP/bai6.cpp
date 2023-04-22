#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
using namespace std;

class Fraction{
    private:
    int16_t numerator;
    int16_t  denominator;
    public:
    Fraction(int n = 0, int d = 1);
    int16_t getNumerator();
    int16_t  getDenominator();
    void display();
};
Fraction::Fraction(int n,int d){
    this->numerator=n;
    this->denominator=d;
}
int16_t Fraction::getNumerator(){
    return this->numerator;
}
int16_t  Fraction::getDenominator(){
    return this->denominator;
}
void Fraction::display(){
    cout<<this->numerator<<"/"<<this->denominator;
}
class Calculate{
    private:
    Fraction first;
    Fraction second;
    public:
    Calculate(Fraction first,Fraction second);
    Fraction addition();
    Fraction subtraction();
    Fraction multiplication();
    Fraction division();
    void display(Fraction result);
};

Calculate::Calculate(Fraction first,Fraction second){
        this->first=first;
        this->second=second;
}
Fraction Calculate::addition(){
    this->first.display();
    cout<<" + ";
    this->second.display();
    return Fraction(this->first.getNumerator() * this->second.getDenominator() 
    + this->second.getNumerator() * this->first.getDenominator()
    ,this->first.getDenominator() * this->second.getDenominator());
}
Fraction Calculate::subtraction(){
    this->first.display();
    cout<<" - ";
    this->second.display();
    return Fraction(this->first.getNumerator() * this->second.getDenominator() 
    - this->second.getNumerator() * this->first.getDenominator()
    ,this->first.getDenominator() * this->second.getDenominator());
}

Fraction Calculate::multiplication(){
    this->first.display();
    cout<<" * ";
    this->second.display();
    return Fraction(this->first.getNumerator() * this->second.getNumerator(),
    this->first.getDenominator() * this->second.getDenominator());
}

Fraction Calculate::division(){
    this->first.display();
    cout<<" / ";
    this->second.display();
    return Fraction(this->first.getNumerator() * this->second.getDenominator(),
    this->first.getDenominator() * this->second.getNumerator());
}

void Calculate::display(Fraction result){
    cout<<" = ";
    result.display();
    cout<<"\n";
}
int main(int argc, char const *argv[])
{
    Fraction a(1,2),b(1,4);
    Calculate tinh(a,b);
    tinh.display(tinh.addition());
    tinh.display(tinh.subtraction());
    tinh.display(tinh.multiplication());
    tinh.display(tinh.division());

    return 0;
}



