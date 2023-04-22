#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
using namespace std;

class Account{
    private:
        string name;
        uint8_t number;
        uint64_t balance;
    public:
        Account(string name =" Nguyen A",uint8_t number= 000, uint64_t balance =50000);
        void withdrawing(uint64_t money);
        void depositing(uint64_t money);
        uint64_t getBalance();
};

Account::Account(string name ,uint8_t number, uint64_t ballance ){
    this->name=name;
    this->number=number;
    this->balance=ballance;
}
void Account::withdrawing(uint64_t money){
    if(this->balance - money >=0){
        this->balance -=  money;
        cout<<"Da rut "<<money<<" dong thanh cong"<<endl;
    }
    else{
        cout<<"SO DU KHONG DU!!"<<endl;
    }
}
void Account::depositing(uint64_t money){
    this->balance += money;
    cout<<"Da nap "<<money<<" dong thanh cong"<<endl;
}
uint64_t Account::getBalance(){
    return this->balance;
}


int main(int argc, char const *argv[])
{
    Account a;
    a.depositing(30000);
    cout<<"so du tai khoan: "<<a.getBalance()<<endl;
    a.withdrawing(70000);
    cout<<"so du tai khoan: "<<a.getBalance()<<endl;
    return 0;
}

