#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
#include<ctime>
using namespace std;
typedef enum{
            THANG_1=(uint8_t)1,
            THANG_2,
            THANG_3,
            THANG_4,
            THANG_5,
            THANG_6,
            THANG_7,
            THANG_8,
            THANG_9,
            THANG_10,
            THANG_11,
            THANG_12
        }thang;
class Date{
    private:
        uint8_t day;
        uint8_t mouth;
        uint16_t year;
        thang check;
    public:
        Date(uint8_t day=0,uint8_t mouth=0,uint16_t year=0);
        void holiday();
        int Age();
};
Date::Date(uint8_t day,uint8_t mouth,uint16_t year){
    if(mouth > 12 ) exit(0);
    int temp=0;
    this->check=(thang)mouth;
    switch (check)
    {
    case THANG_1:
    case THANG_3:
    case THANG_5:
    case THANG_7:
    case THANG_8:
    case THANG_10:
    case THANG_12:
        temp=31;
        break;
    case THANG_4:
    case THANG_6:
    case THANG_9:
    case THANG_11:
        temp=30;
        break;
    case THANG_2:
        temp=((year %400==0)||(year % 4==0 && year % 100))?29:28;
    default:
        break;
    }
    if(day > temp ) exit(0);
    this->day=day;
    this->mouth=mouth;
    this->year=year;
}
int Date::Age(){
    time_t t=time(NULL);
    tm* now= localtime(&t);
    int nowYear= now->tm_year +1900;
    int nowMouth= now->tm_mon +1;
    int nowDay= now->tm_mday;

    int age = nowYear - this->year -1;
    if(nowMouth > this->mouth){
        age++;
    }
    else if(nowMouth == this->mouth && nowDay >=day){
        age++;
    }
    return age;
}
void Date::holiday(){
    if(this->day == 8 && this->mouth==3){
        cout<<"Ngay quoc te phu nu";
    }
    else if(this->day == 1 && this->mouth==5){
        cout<<"Ngay quoc te lao dong";
    }
    else if(this->day == 1 && this->mouth==6){
        cout<<"Ngay quoc te thieu nhi";
    }
    else if(this->day == 30 && this->mouth==4){
        cout<<"Ngay thong nhat dat nuoc";
    }
}
int main(int argc, char const *argv[])
{
    
    Date d(30,4,1990);
    cout<<d.Age()<<" tuoi"<<endl;
    d.holiday();
    return 0;
}
