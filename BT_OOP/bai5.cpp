#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
using namespace std;
class Date{
    private:
    int16_t day;
    int16_t mouth;
    uint16_t year;
    public:
    void setDate(int16_t day,int16_t mouth,uint16_t year);
    int16_t getDay();
    int16_t getMouth();
    uint16_t getYear();
};
void Date::setDate(int16_t day,int16_t mouth,uint16_t year){
    this->day=day;
    this->mouth=mouth;
    this->year=year;
}
int16_t Date::getDay(){
    return this->day;
}
int16_t Date::getMouth(){
    return this->mouth;
}
uint16_t Date::getYear(){
    return this->year;
}

class Person{
    private:
        string name;
        string address;
        Date date;
        int16_t age;
    public:
        void setPerson(string name,string address,int16_t day, int16_t mouth,uint16_t year);
        void displayPerson();
        void setAge();
};

void Person::setPerson(string name,string address,int16_t day, int16_t mouth,uint16_t year){
        this->name=name;
        this->address=address;
        this->date.setDate(day,mouth,year);
}

void Person::displayPerson(){
    cout<<"Name: "<<this->name<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"date of birth: "<<(int )this->date.getDay() <<"/"<<(int )this->date.getMouth();
    cout<<"/"<<(int )this->date.getYear() <<endl;
    cout<<(int )this->age<<" tuoi";

}
void Person::setAge(){
    this->age=2023-this->date.getYear();
}
int main(int argc, char const *argv[])
{
    Person a;
    a.setPerson("thinh","hcm",30,7,2002);
    a.setAge();
    a.displayPerson();
    return 0;
}
