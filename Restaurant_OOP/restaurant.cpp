#include <stdio.h>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include <stdint.h>
#include <iomanip>
using namespace std;

class Dish
{
private:
    uint8_t id;
    string name;
    double price;
    int quantity;
    double total;
public:
    Dish(string name, double price, int quantity);
    void setName(string name);
    void setPrice(double price);
    void setQuantity(int quantity);

    uint8_t getId();
    string getName();
    double getPrice();
    int getQuantity();
    double getTotal();
     
};
Dish::Dish(string name, double price, int quantity){
    static uint8_t id_add=100;
    this->id=id_add;
    id_add++;
    this->name=name;
    this->price=price;
    this->quantity=quantity;
}
void Dish::setName(string name){
    this->name=name;
}
void Dish::setPrice(double price){
    this->price=price;
}
void Dish::setQuantity(int quantity){
    this->quantity=quantity;
}

uint8_t Dish::getId(){
    return this->id;
}
string Dish::getName(){
    return this->name;
}
double Dish::getPrice(){
    return this->price;
}
int Dish::getQuantity(){
    return this->quantity;
}
double Dish::getTotal(){
    return this->total=(this->price*this->quantity);
}
typedef enum{
    BOOKED,
    AVAILABLE
}status;
class Table
{
    private:
        status st;
        vector <Dish> vecDish;
    public:
        void setStatus(status st);
        status getStatus();
        vector <Dish> getDish();
        void setDish(vector <Dish> vecDish);
};
void Table::setStatus(status st){
    this->st=st;
}
status Table::getStatus(){
    return this->st;
}
vector <Dish> Table::getDish(){
    return this->vecDish;
}
void Table::setDish(vector <Dish> vecDish){
    this->vecDish=vecDish;
}
 
class Manage
{
private:
    vector<Table> vecTable;
    vector<Dish> vecDish;
public:
    
    void addDish();
    void updateDish();
    void setTable();
    void deleteDish();
    void DisplayMenu();
    void setVecTable(vector<Table> vecTable);
    void setVecDish(vector<Dish> vecDish);
    vector<Table> getVecTable();
    vector<Dish>  getVecDish();

};
void Manage::setVecTable(vector<Table> vecTable){
    this->vecTable=vecTable;
}
void Manage::setVecDish(vector<Dish> vecDish){
    this->vecDish=vecDish;
}
vector<Table> Manage::getVecTable(){
	return this->vecTable;
}
vector<Dish>  Manage::getVecDish(){
	return this->vecDish;
}
void Manage::setTable(){
    vecTable.clear();
    int number;
    cout<<"PRESS NUMBER OF TABLE: ";
    cin >>number;
    for(int i=0;i<number;i++){
        Table newTable;
        newTable.setStatus(AVAILABLE);
        vecTable.push_back(newTable);
    }
}

void Manage::addDish(){
    string name;
     double price;
     fflush(stdin);
    cout <<"NAME DISH: ";
   	getline(cin,name);
    fflush(stdin);
    cout <<"PRICE DISH: ";
    cin >>price;
    Dish newdish(name,price,0);
    this->vecDish.push_back(newdish);
}

void Manage::deleteDish(){
    int ID;
    while(1){
    cout<<"PRESS ID: ";
    cin >>ID;
    for(int i=0;i<this->vecDish.size();i++){
        if(ID == (int)vecDish[i].getId()){
            this->vecDish.erase(this->vecDish.begin()+i);
            cout<<" SUCCESSFUL DELETE"<<endl;
            return;
        }
    }
    cout<<"NOT HAVE ID!! PLEASE AGAIN!"<<endl;
    }
}
#define THINH() 0
#define LABEL() cout<<"STT\tID\t"<<left<<setw(25)<<"Name"<<"Price"<<endl;
#define DISPLAY(i)                                                          \
cout<<i<<"\t";                                                              \
cout<<(int)this->vecDish[i].getId()<<"\t";                                \
cout<<left<<setw(25)<<this->vecDish[i].getName();                           \
cout<<this->vecDish[i].getPrice()<<endl;    
void Manage::DisplayMenu(){
    LABEL();
    for(int i=0;i<this->vecDish.size();i++){
        DISPLAY(i);
    }
}

void Manage::updateDish(){
    int index=-1;
    int ID;
    while(1){
    	cout<<"PRESS ID:";
    	cin>>ID;
        for(int i=0;i<this->vecDish.size();i++){
            if(ID==(int)vecDish[i].getId()){
                index=i;
            }
        }
        if(index == -1){
            cout<<"NOT HAVE ID!! PLEASE AGAIN!"<<endl;
        }else{
            break;
        }
    }
    while (1)
    {
        system("cls");
        LABEL();
        DISPLAY(index);
        cout<<"-UPDATE DISH-"<<endl;
        cout<<"PRESS 1:UPDATE NAME "<<endl;
        cout<<"PRESS 2:UPDATE PRICE "<<endl;
        cout<<"PRESS 0:EXIT"<<endl;
        int button;
        cout<<"PRESS: ";
        cin >> button;
        string name;
        double price;
        switch (button)
        {
        case 1:
        	fflush(stdin);
            cout<<"New Name:";
            getline(cin,name);
            vecDish[index].setName(name);
            break;
        case 2:
            cout<<"New Price:";
            cin>>price;
            vecDish[index].setPrice(price);
            break;
        case 0:
            cout<<"EXIT"<<endl;
            break;
        default:
            break;
        }
        if(button ==0) break;
        cout<<"ENTER TO COUTINUE";
        getch();
    }
    
}

class Personnel{
    private:
        Manage manage;
    public:
        void setManage(Manage manage);
        void displayTable();
        void addDish(int table);
        void updateDish(int table);
        void deleteDish(int table);
        void DisplayMenu(int table);
        void payMoney(int table);
        Manage getManage();
};

void Personnel::setManage(Manage manage){
    this->manage=manage;
}
Manage Personnel::getManage(){
    return this->manage;
}
void Personnel::displayTable(){
    cout<<"TABLE\t\tSTATUS"<<endl;
    for(int i=0;i<this->manage.getVecTable().size();i++){
        cout<<i<<"\t\t";
        if(this->manage.getVecTable()[i].getStatus()==AVAILABLE) cout<<"\n";
        if(this->manage.getVecTable()[i].getStatus()==BOOKED) cout<<"X\n";
    }
}


void Personnel::addDish(int table){
    while(1){
        system("cls");
        cout<<"--ADD DISH--"<<endl;
        cout<<"---MENU---"<<endl;
        this->manage.DisplayMenu();
        cout<<"---ORDER----"<<endl;
        this->DisplayMenu(table);
        cout<<"PRESS 1: ADD DISH"<<endl;
        cout<<"PRESS 0: EXIT"<<endl;
        int button;
        cout<<"PRESS:";
        cin>>button;
        
        switch (button)
        {
            case 1:
            	while(1){                                                                                                                                                           
                        int ID;                                                                                                                                   
                        cout<<"PRESS ID:";                                                                                                                                     
                        cin >> ID;                                                                                                                                  
                        int check=0;                                                                                                                      
                        for(int i=0;i<this->manage.getVecDish().size();i++){                                                
                             if(ID== this->manage.getVecDish()[i].getId()){                                                 
                                cout<<"Your Chose: "<<this->manage.getVecDish()[i].getName()<<endl;     
                                 int number;                                                            
                                cout<<"PRESS NUMBER: ";                                                
                                cin>>number;                                                            
                                vector <Table> tempTable =this->manage.getVecTable();                  
                                vector <Dish> tempDish=tempTable[table].getDish();                     
                                tempDish.push_back(this->manage.getVecDish()[i]);                      
                                tempDish[tempDish.size()-1].setQuantity(number);                      
                                tempTable[table].setDish(tempDish);                                    
                                tempTable[table].setStatus(BOOKED);                                    
                                this->manage.setVecTable(tempTable);                                   
                                check=1;                                                               
                            }                                                                           
                        }                                                                              
                        if(check==1) break;                                                            
                        cout<<"NO HAVE ID !! PLEASE AGAIN!!"<<endl;                                    
                }
                break;
            case 0:
                break;
            default:
                break;
        }
        
        if(button ==0) break;
        cout<<"ENTER TO COUTINUE";
        getch();
    }
}
void Personnel::updateDish(int table){
    while(1){
        system("cls");
        cout<<"-UPDATE DISH--"<<endl;
        cout<<"---MENU---"<<endl;
        this->manage.DisplayMenu();
        cout<<"---ORDER----"<<endl;
        this->DisplayMenu(table);
        cout<<"PRESS 1: UPDATE DISH"<<endl;
        cout<<"PRESS 0: EXIT"<<endl;
        int button;
        cout<<"PRESS:";
        cin>>button;
        
        switch (button)
        {
            case 1:
            	while(1){
                    int STT;
                    cout<<"PRESS STT:";
                    cin >> STT;
                    int Check=0;
                
                        if(STT < this->manage.getVecTable()[table].getDish().size()){
                        		Check=1;
                            while(1){
                    int ID;
                    cout<<"PRESS ID:";
                    cin >> ID;
                    int check=0;
                    for(int i=0;i<this->manage.getVecDish().size();i++){
                        if(ID== this->manage.getVecDish()[i].getId()){
                            cout<<"Your Chose: "<<this->manage.getVecDish()[i].getName()<<endl;
                            int number;
                            cout<<"PRESS NUMBER: ";
                            cin>>number;
                            vector <Table> tempTable =this->manage.getVecTable();
                            vector <Dish> tempDish=tempTable[table].getDish();
                            tempDish[STT]=this->manage.getVecDish()[i];
                            tempDish[STT].setQuantity(number);
                            tempTable[table].setDish(tempDish);
                            tempTable[table].setStatus(BOOKED);
                            this->manage.setVecTable(tempTable);
                            check=1;
                        }
                    }
                    if(check==1) break;
                    cout<<"NO HAVE ID !! PLEASE AGAIN!!"<<endl;
            	}
                        }
                    
                    if(Check==1) break;
                    cout<<"NO HAVE STT !! PLEASE AGAIN!!"<<endl;
            	}
                break;
            case 0:
                break;
            default:
                break;
        }
        
        if(button ==0) break;
        cout<<"ENTER TO COUTINUE";
        getch();
    }
    
    
}
void Personnel::deleteDish(int table){
    while (1)
    {   
        system("cls");
        cout<<"--DELETE DISH--"<<endl;
        cout<<"---MENU---"<<endl;
        this->manage.DisplayMenu();
        cout<<"---ORDER----"<<endl;
        this->DisplayMenu(table);
        cout<<"PRESS 1: DELETE DISH"<<endl;
        cout<<"PRESS 0: EXIT"<<endl;
        int button;
        cout<<"PRESS:";
        cin>>button;


        switch (button)
        {
            case 1:
            	while(1){
                    int STT;
                    cout<<"PRESS STT:";
                    cin >> STT;
                    int check=0;
                    if(STT < this->manage.getVecTable()[table].getDish().size()){
                        vector <Table> tempTable =this->manage.getVecTable();
                        vector <Dish> tempDish=tempTable[table].getDish();
                        tempDish.erase(tempDish.begin()+STT);
                        tempTable[table].setDish(tempDish);
                        this->manage.setVecTable(tempTable);
                        check=1;
                    }
                    if(check==1) break;
                    cout<<"NO HAVE STT !! PLEASE AGAIN!!"<<endl;
            	}
                break;
            case 0:
                break;
            default:
                break;
        }
        
        if(button ==0) break;
        cout<<"ENTER TO COUTINUE";
        getch();
    }
}
void Personnel::DisplayMenu(int table){
    cout<<"STT\tID\t"<<left<<setw(25)<<"NAME"<<left<<setw(10)<<"PRICE"<<left<<setw(8)<<"NUMBBER"<<"\tTOTAL\n";
    for(int i=0;i<this->manage.getVecTable()[table].getDish().size();i++){
        cout<<i<<"\t";
        cout<<(int)this->manage.getVecTable()[table].getDish()[i].getId()<<"\t";
        cout<<left<<setw(25)<<this->manage.getVecTable()[table].getDish()[i].getName();
        cout<<left<<setw(10)<<this->manage.getVecTable()[table].getDish()[i].getPrice();
        cout<<left<<setw(8)<<this->manage.getVecTable()[table].getDish()[i].getQuantity()<<"\t";
        cout<<this->manage.getVecTable()[table].getDish()[i].getTotal()<<"\n";
    }
}
void Personnel::payMoney(int table){
    system("cls");
    this->DisplayMenu(table);
    double sum=0;
    for(int i=0;i<this->manage.getVecTable()[table].getDish().size();i++){
        sum+=this->manage.getVecTable()[table].getDish()[i].getTotal();
    }
    vector <Table> tempTable =this->manage.getVecTable();
    vector <Dish> tempDish=tempTable[table].getDish();
    tempDish.clear();
    tempTable[table].setDish(tempDish);
    tempTable[table].setStatus(AVAILABLE);
    this->manage.setVecTable(tempTable);
    cout<<"\t\t\tSUM: "<<sum<<endl;
    cout<<"PAYMENT SUCCESS!!"<<endl;
    cout<<"ENTER TO COUTINUE"<<endl;
    getch();
}
class Restaurant{
    private:
        Manage Rmanage;
        Personnel Rpersonnel;
    public:
        void programManage();
        void programPersonnel();
};
void Restaurant::programManage(){
    while(1){
        
        system("cls");
        cout<<"--MENU--"<<endl;
        this->Rmanage.DisplayMenu();
        cout<<"-- MANAGE --"<<endl;
        cout<<"PRESS 1:ADD DISH"<<endl;
        cout<<"PRESS 2:UPDATE DISH"<<endl;
        cout<<"PRESS 3:DELETE DISH"<<endl;
        cout<<"PRESS 4:DISPLAY MENU"<<endl;
        cout<<"PRESS 5:SET TABLE"<<endl;
        cout<<"PRESS 0:EXIT"<<endl;
        int button;
        cout<<"PRESS: ";
        cin>>button;
        switch (button)
        {
        case 1:
            this->Rmanage.addDish();
            break;
        case 2:
            this->Rmanage.updateDish();
            break;
        case 3:
            this->Rmanage.deleteDish();
            break;
        case 4:
            this->Rmanage.DisplayMenu();
            break;
        case 5:
            this->Rmanage.setTable();
            break;
        case 0:
            break;
        default:
            break;
        }
        if(button==0) break;
        cout<<"ENTER TO COUTINUE";
        getch();
    }
}
void Restaurant::programPersonnel(){
    this->Rpersonnel.setManage(this->Rmanage);
    this->Rpersonnel.displayTable();
    if(this->Rmanage.getVecTable().empty()) {
        cout<<"Restaurant close!!!"<<endl;
        return;
    }
    int table;
    while(1){
    cout<<"CHOSE TABLE:";
    cin>>table;
    if(table < this->Rmanage.getVecTable().size()){
        break;
    }
    cout<<"NO TABLE !! PRESS AGAIN!!\n";
    }
    while(1){
        int button;
        system("cls");
        cout<<"---PERSONNEL"<<endl;
        cout<<"PRESS 1:ADD DISH"<<endl;
        cout<<"PRESS 2:UPDATE DISH"<<endl;
        cout<<"PRESS 3:DELETE DISH"<<endl;
        cout<<"PRESS 4:DISPLAY DISH"<<endl;
        cout<<"PRESS 5:PAY MONEY"<<endl;
        cout<<"PRESS 0:EXIT"<<endl;
        cout<<"PRESS : ";
        cin>>button;
        switch (button)
        {
        case 1:
            this->Rpersonnel.addDish(table);
            this->Rmanage=this->Rpersonnel.getManage();
            break;
        case 2:
            this->Rpersonnel.updateDish(table);
            this->Rmanage=this->Rpersonnel.getManage();
            break;
        case 3:
            this->Rpersonnel.deleteDish(table);
            this->Rmanage=this->Rpersonnel.getManage();
            break;
        case 4:
            this->Rpersonnel.DisplayMenu(table);
            break;
        case 5:
            this->Rpersonnel.payMoney(table);
            this->Rmanage=this->Rpersonnel.getManage();
            break;
        case 0:
            break;
        default:
            break;
        }
        if(button==0) break;
        cout<<"ENTER TO COUTINUE";
        getch();
    }
}

void programRestaurant(){
Restaurant program;
while(1){
	system("cls");
    cout<<"- - RESTAURANT - -"<<endl;
    cout<<"PRESS 1:MANAGER"<<endl;
    cout<<"PRESS 2:PERSONNEL"<<endl;
    cout<<"PRESS 0:EXIT"<<endl;
    cout<<"PRESS: ";
    int button;
    cin >>button;
    switch (button)
    {
    case 1:
        program.programManage();
        break;
    case 2:
        program.programPersonnel();
        break;
    case 0:
        break;
    default:
        break;
    }
    if(button==0) break;
    cout<<"ENTER TO COUTINUE";
    getch();
}
}

int main(int argc, char const *argv[])
{
	programRestaurant();
}




