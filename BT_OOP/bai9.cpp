#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
using namespace std;

class Car{
    private:
    string color;
    string engineModel;
    int mileage;
    public:
    Car(string color = "red", string engineModel = "F1", int mileag = 0);

    void setColor(string c); 
    void setEngineModel(string e); 
    void setMileage(int m);

    string getColor(); 
    string getEngineModel();
    int getMileage();

    void printCarInfo();
    double costMaintenance();

};

Car::Car(string color , string engineModel , int mileage ) {
    this->color=color;
    this->engineModel=engineModel;
    this->mileage=mileage;
}

string Car::getColor() { 
    return this->color; 
}
string Car::getEngineModel() { 
    return this->engineModel; 
}
int Car::getMileage() { 
    return this->mileage; 
}

void Car::setColor(string color) { 
    this->color = color; 
}
void Car::setEngineModel(string  engineModel) { 
    this->engineModel =  engineModel; 
}
void Car::setMileage(int mileage) { 
    this->mileage = mileage; 
}
void Car::printCarInfo() {
        cout << "Color: " << this->color << endl;
        cout << "Engine Model: " << this->engineModel << endl;
        cout << "Mileage: " << this->mileage << endl;
        cout <<"Cost Maintenance :"<<this->costMaintenance()<<endl;
}
double Car::costMaintenance(){
    double cost = 0;
        if (this->mileage < 1000) {
            cost = this->mileage*100;
        } else if (this->mileage < 5000) {
            cost = this->mileage*500;
        } else {
            cost = this->mileage*1000;
        }
        return cost;
}
int main(int argc, char const *argv[])
{
    Car a;
    a.setMileage(1280);
    a.printCarInfo();
    return 0;
}

