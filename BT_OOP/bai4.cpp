#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
using namespace std;

class animal
{
private:
    string name;
    int16_t age;
    int16_t weight;
    int16_t height;
public:
    void setName(string name);
    void setAge(int16_t age);
    void setWeight(uint16_t weight);
    void setHeight(uint16_t height);
    string getName();
    int16_t getAge();
    uint16_t getWeight();
    uint16_t getHeight();
    double calculateBMI();
};

void animal::setName(string name){
    this->name=name;
}
void animal::setAge(int16_t age){
    this->age=age;
}
void animal::setWeight(uint16_t weight){
    this->weight=weight;
}
void animal::setHeight(uint16_t height){
    this->height=height;
}
string animal::getName(){
    return this->name;
}
int16_t animal::getAge(){
    return this->age;
}   
uint16_t animal::getWeight(){
    return this->weight;
}
uint16_t animal::getHeight(){
    return this->height;
}
double animal::calculateBMI(){
    return this->weight/pow(this->height,2);
}
class Compare{
    private:
        animal first;
        animal second;
    public:
    Compare(animal first,animal second);
    void compareAge();
    void compareWeight();
};

Compare::Compare(animal first,animal second){
    this->first=first;
    this->second=second;
}

void Compare::compareAge(){
    if(first.getAge() > second.getAge()){
        cout<<first.getName()<<" lon tuoi hon "<<second.getName()<<endl;
    }
    else if(first.getAge() < second.getAge()){
        cout<<first.getName()<<" nho tuoi hon "<<second.getName()<<endl;
    }
    else{
        printf("%s bang tuoi %s\n",first.getName(),second.getName());
        cout<<first.getName()<<" bang tuoi "<<second.getName()<<endl;
    }
}
void Compare::compareWeight(){
    if(first.getWeight() > second.getWeight()){
         cout<<first.getName()<<" nang hon "<<second.getName()<<endl;
    }
    else if(first.getWeight() < second.getWeight()){
        cout<<first.getName()<<" nhe hon "<<second.getName()<<endl;
    }
    else{
        cout<<first.getName()<<" va "<<second.getName()<<" bang trong luong "<<endl;
    }
}   

int main(int argc, char const *argv[])
{
    animal cat;
    animal dog;
    cat.setName(string("cat"));
    cat.setAge(12);
    cat.setHeight(12);
    cat.setWeight(14);
    cout<<cat.getName()<<" BMI: "<<cat.calculateBMI()<<endl;
    dog.setName(string("dog"));
    dog.setAge(10);
    dog.setHeight(20);
    dog.setWeight(15);
    cout<<dog.getName()<<" BMI: "<<dog.calculateBMI()<<endl;
    Compare sosanh(cat,dog);
    sosanh.compareAge();
    sosanh.compareWeight();
    return 0;
}
 



