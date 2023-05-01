#include <stdio.h>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include <stdint.h>
#include <iomanip>
using namespace std;


class Service{
    private:
        uint8_t id;
        string name;
        double price;
        int quantity;
        double total;
    public:
        Service(string name, double price);
        void setName(string name);
        void setPrice(double price);
        void setQuantity(int quantity);

        uint8_t getId();
        string getName();
        double getPrice();
        int getQuantity();
        double getTotal();
};
Service::Service(string name, double price){
    static uint8_t id_add=100;
    this->id=id_add;
    id_add++;
    this->name=name;
    this->price=price;
    this->quantity=quantity;
}
void Service::setName(string name){
    this->name=name;
}
void Service::setPrice(double price){
    this->price=price;
}
void Service::setQuantity(int quantity){
    this->quantity=quantity;
}
uint8_t Service::getId(){
    return this->id;
}
string Service::getName(){
    return this->name;
}
double Service::getPrice(){
    return this->price;
}
int Service::getQuantity(){
    return this->quantity;
}
double Service::getTotal(){
    return this->total=(this->price*this->quantity);
}
class Hour{
    private:
        int8_t hour;
        int8_t minute;
        int8_t second;
    public:
        void setTime();
        void setHour(int8_t hour);
        void setMinute(int8_t minute);
        void setSecond(int8_t second);
        void displayTime();
        int8_t getHour();
        int8_t getMinute();
        int8_t getSecond();
};
void Hour::displayTime(){
    cout<<"  "<<(int)this->hour<<":";
    cout<<(int)this->minute<<":";
    cout<<(int)this->second<<endl;
}
void Hour::setTime(){
    int time;
    while(1){
        cout<<"Press Hour (0h-23h): ";
        cin>>time;
        if(0 <= time && time < 24){
        this->hour=time;
        break;
        }
        cout<<"wrong again"<<endl;
    }
    while(1){
        cout<<"Press Minute (0m-59m): ";
        cin>>time;
        if(0 <= time && time <60) {
        this->minute=time;
        break;
        }
        cout<<"wrong again"<<endl;
    }
    while (1){
        cout<<"Press Second (0s-59s): ";
        cin>>time;
        if(0<=time && time <60) {
        this->second=time;
        break;
        }
        cout<<"wrong again"<<endl;
    }
    
}
void Hour::setHour(int8_t hour){
    this->hour=hour;
}
void Hour::setMinute(int8_t minute){
    this->minute=minute;
}
void Hour::setSecond(int8_t second){
    this->second=second;
}
int8_t Hour::getHour(){
    return this->hour;
}
int8_t Hour::getMinute(){
    return this->minute;
}
int8_t Hour::getSecond(){
    return this->second;
}
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
        }Smouth;
class Date{
    private:
        uint8_t day;
        uint8_t mouth;
        uint16_t year;
    public:
        void setDate();
        void setDay(uint8_t day);
        void setMouth(uint8_t mouth);
        void setYear(uint16_t year);
        uint8_t getDay();
        uint8_t getMouth();
        uint16_t getYear();
        void displayDate();
};
void Date::displayDate(){
    cout<<(int)this->day<<"/";
    cout<<(int)this->mouth<<"/";
    cout<<(int)this->year<<endl;
}
void Date::setDate(){
    int date;
    while (1)
    {
        cout<<"Press Year : ";
        cin>>date;
        if(0< date){
           this->year=date;
           break;
        }
        cout<<"wrong again"<<endl;
    }
    while (1)
    {
        cout<<"Press Mouth (1m-12m): ";
        cin>>date;
        if(0 < date && date <= 12){
            this->mouth=date;
            break;
        }
        cout<<"wrong again"<<endl;
    }
    Smouth check=(Smouth)this->mouth;
    int tempDay;
    switch (check)
    {
    case THANG_1:
    case THANG_3:
    case THANG_5:
    case THANG_7:
    case THANG_8:
    case THANG_10:
    case THANG_12:
        tempDay=31;
        break;
    case THANG_4:
    case THANG_6:
    case THANG_9:
    case THANG_11:
        tempDay=30;
        break;
    case THANG_2:
        tempDay=((year %400==0)||(year % 4==0 && year % 100))?29:28;
    default:
        break;
    }
    while (1)
    {
        cout<<"Press Day (1d-"<<tempDay<<"d): ";
        cin>>date;
        if(0 < date && date <= tempDay){
            this->day=date;
            break;
        }
        cout<<"wrong again"<<endl;
    }
}
void Date::setDay(uint8_t day){
    this->day=day;
}
void Date::setMouth(uint8_t mouth){
    this->mouth=mouth;
}
void Date::setYear(uint16_t year){
    this->year=year;
}
uint8_t Date::getDay(){
    return this->day;
}
uint8_t Date::getMouth(){
    return this->mouth;
}
uint16_t Date::getYear(){
    return this->year;
}
typedef enum{
    BOOKED,
    AVAILABLE
}status;
typedef enum{
    HOUR,
    DAY
}rentaltype;
class Room{
    private:
        status statusRoom;
        vector <Service> vecService;
        rentaltype rentaltypeRoom;
        Hour startHour;
        Date startDate;
    public:
        void setStatus(status statusRoom);
        void setService(vector <Service> vecService); 
        void setRentaltype(rentaltype rentaltypeRoom);
        void setStartHour(Hour startHour);
        void setStartDate (Date startDate);
        status getStatus();
        vector <Service> getService();
        rentaltype getRentaltype();
        Hour getStartHour();
        Date getStartDate();

};
void Room::setStatus(status statusRoom){
    this->statusRoom=statusRoom;
}
void Room::setService(vector <Service> vecService){
    this->vecService=vecService;
}
void Room::setRentaltype(rentaltype rentaltypeRoom){
    this->rentaltypeRoom=rentaltypeRoom;
}
void Room::setStartHour(Hour startHour){
    this->startHour=startHour;
}
void Room::setStartDate (Date startDate){
    this->startDate=startDate;
}
status Room::getStatus(){
    return this->statusRoom;
}
vector <Service> Room::getService(){
    return this->vecService;
}
rentaltype Room::getRentaltype(){
    return this->rentaltypeRoom;
}
Hour Room::getStartHour(){
    return this->startHour;
}
Date Room::getStartDate(){
    return this->startDate;
}


class Manager{
    private:
        vector <Room> vecRoom;
        vector <Service> vecService;
        double price[2];
    public:
        void addService();
        void updateService();
        void deleteService();
        void displayService();
        void setPrice();
        void setRoom();
        double getPrice(int index);
        void setVecRoom(vector <Room> vecRoom);
        void setVecService(vector <Service> vecService);
        vector <Room> getVecRoom();
        vector <Service> getVecService();

};
void Manager::addService(){
    string name;
    double price;
    fflush(stdin);
    cout<<"NAME DISH: ";
    getline(cin,name);
    cout<<"PRICE DISH: ";
    cin>>price;
    Service newService(name,price);
    this->vecService.push_back(newService);
}
void Manager::deleteService(){
    if(this->vecService.empty()) return;
    int ID;
    while (1)
    {
        cout<<"PRESS ID: ";
        cin >>ID;
        for (int i = 0; i < this->vecService.size(); i++)
        {
            if(ID ==(int)vecService[i].getId()){
                this->vecService.erase(this->vecService.begin()+i);
                cout<<"SUCCESSFUL DELETE"<<endl;
                return;
            }
        }
        cout<<"NOT HAVE ID!! PLEASE AGAIN!"<<endl;
    }
    
}
#define LABEL() cout<<"STT\tID\t"<<left<<setw(25)<<"Name"<<"Price"<<endl;
#define DISPLAY(i)                                                          \
cout<<i<<"\t";                                                              \
cout<<(int)this->vecService[i].getId()<<"\t";                                  \
cout<<left<<setw(25)<<this->vecService[i].getName();                           \
cout<<this->vecService[i].getPrice()<<endl;    
void Manager::displayService(){
    LABEL();
    for(int i=0;i<this->vecService.size();i++){
        DISPLAY(i);
    }
}
void Manager::updateService(){
    if(this->vecService.empty()) return;
    int index=-1;
    int ID;
    while (1)
    {
        cout<<"PRESS ID:";
        cin>>ID;
        for (int i = 0; i < this->vecService.size(); i++)
        {
            if(ID==(int)vecService[i].getId()){
                index=i;
            }
        }
        if(index == -1){
            cout<<"NOT HAVE ID!! PLEASE AGAIN!!"<<endl;
        }else{
            break;
        }
    }
    while (1)
    {
        system("cls");
        LABEL();
        DISPLAY(index);
        cout<<"--UPDATE SERVICE--\n";
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
            vecService[index].setName(name);
            break;
        case 2:
            cout<<"New Price: ";
            cin>>price;
            vecService[index].setPrice(price);
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
void Manager::setPrice(){
    while(1){
        system("cls");
        cout<<"Set Price"<<endl;
        cout<<"PRESS 1: RENT BY THE HOUR"<<endl;
        cout<<"PRESS 2: RENT BY DAY"<<endl;
        cout<<"PRESS 0: EXIT"<<endl;
        int button;
        cout<<"PRESS: ";
        cin>> button;
        double tempPrice;
        switch (button)
        {
        case 1:
            cout<<"PRESS PRICE RENT BY THE HOUR: "<<endl;
            cin>>tempPrice;
            this->price[HOUR]=tempPrice;
            break;
        case 2:
            cout<<"PRESS PRICE RENT BY DAY: "<<endl;
            cin>>tempPrice;
            this->price[DAY]=tempPrice;
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
double Manager::getPrice(int index){
    return this->price[index];
}
void Manager::setRoom(){
    vecRoom.clear();
    int number;
    cout<<"PRESS NUMBER OF ROOM: ";
    cin >>number;
    for(int i=0;i<number;i++){
        Room newRoom;
        newRoom.setStatus(AVAILABLE);
        vecRoom.push_back(newRoom);
    }
}
void Manager::setVecRoom(vector <Room> vecRoom){
    this->vecRoom=vecRoom;
}
void Manager::setVecService(vector <Service> vecService){
    this->vecService=vecService;
}
vector <Room> Manager::getVecRoom(){
    return this->vecRoom;
}
vector <Service> Manager::getVecService(){
    return this->vecService;
}

class Personnel{
    private:
        Manager manage;
        double calculationPricebyTime(Hour Start,Hour End);
        double calculationPricebyDate(Date Start,Date End);
        int calDay(int8_t day, int8_t mouth,int16_t year);
    public:
        void setManager(Manager manage);
        void rentRoom(int room);
        void displayRoom();
        void orderService(int room);
        void updateOrderService(int room);
        void deleteOrderService(int room);
        void displayOrderService(int room);
        void payMoney(int room);
        Manager getManager();
};
int Personnel::calDay(int8_t day, int8_t mouth,int16_t year) {
 if (mouth < 3)
  year--, mouth += 12;
 return 365 * year + year / 4 - year / 100 + year / 400 + (153 * mouth - 457) / 5 + day - 306;
}
void Personnel::setManager(Manager manage){
    this->manage=manage;
}
double Personnel::calculationPricebyDate(Date Start,Date End){
    int numberOfDays = this->calDay(End.getDay(),End.getMouth(),End.getYear())
    -this->calDay(Start.getDay(),Start.getMouth(),Start.getYear());
    cout<<"room rental time: ";
    cout<<numberOfDays<<endl;
    return this->manage.getPrice(DAY)*numberOfDays;
}
double Personnel::calculationPricebyTime(Hour Start,Hour End){
    Hour tempStart=Start;
    Hour tempEnd=End;
    Hour tempResult;
    double Price;
    if(tempStart.getSecond()>tempEnd.getSecond()){
        tempEnd.setSecond(tempEnd.getSecond()+60);
        tempEnd.setMinute(tempEnd.getMinute()-1);
    }
    tempResult.setSecond(tempEnd.getSecond()-tempStart.getSecond());
    if(tempStart.getMinute()>tempEnd.getMinute()){
        tempEnd.setMinute(tempEnd.getMinute()+60);
        tempEnd.setHour(tempEnd.getHour()-1);
    }
    tempResult.setMinute(tempEnd.getMinute()-tempStart.getMinute());
    if(tempStart.getHour()>tempEnd.getHour()){
        tempEnd.setHour(tempEnd.getHour()+24);
    }
    tempResult.setHour(tempEnd.getHour()-tempStart.getHour());
    cout<<"room rental time :";
    tempResult.displayTime();
    Price = this->manage.getPrice(HOUR)*tempResult.getHour() +
    this->manage.getPrice(HOUR)*((double)tempResult.getMinute()/60) +
    this->manage.getPrice(HOUR)*((double)tempResult.getSecond()/3600);
    return Price;
}
Manager Personnel::getManager(){
    return this->manage;
}
void Personnel::displayRoom(){
    cout<<"ROOM\t\tSTATUS"<<endl;
    for(int i=0;i<this->manage.getVecRoom().size();i++){
        cout<<i<<"\t\t";
        if(this->manage.getVecRoom()[i].getStatus()==AVAILABLE) cout<<"\n";
        else if(this->manage.getVecRoom()[i].getStatus()==BOOKED) cout<<"X\n";
    }
}
void Personnel::rentRoom(int room){
    while (1)
    {   system("cls");
        cout<<"----RENT ROOM----"<<endl;
        if(this->manage.getVecRoom()[room].getStatus()==BOOKED){
            cout<<"ROOM ARE RENTED"<<endl;
            cout<<"Please pay to continue"<<endl;
            return;
        }
        cout<<"PRESS 1: Rent by the hour"<<endl;
        cout<<"PRESS 2: rent by day"<<endl;
        cout<<"PRESS 0: Exit"<<endl;
        cout<<"PRESS: ";
        int button;
        cin >>button;
        int temp;
        vector <Room> tempRoom=this->manage.getVecRoom();
        switch (button)
        {
        case 1:
            system("cls");
            Hour newHour;
            cout<<"Rent by the hour"<<endl;
            newHour.setTime();
            tempRoom[room].setStartHour(newHour);
           tempRoom[room].setStatus(BOOKED);
           tempRoom[room].setRentaltype(HOUR);
           this->manage.setVecRoom(tempRoom);
            break;
        case 2:
            system("cls");
            Date newDate;
            cout<<"Rent by day"<<endl;
            newDate.setDate();
            tempRoom[room].setStartDate(newDate);
            tempRoom[room].setStatus(BOOKED);
            tempRoom[room].setRentaltype(DAY);
            this->manage.setVecRoom(tempRoom);
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
#define THINH 0
#define CHOOSE(FUNCTION)                               \
system("cls");                                         \
cout<<"----"<<FUNCTION<<" SERVICE----"<<endl;          \
cout<<"----MENU----"<<endl;                            \
this->manage.displayService();                         \
cout<<"----ORDER----"<<endl;                           \
this->displayOrderService(room);                       \
cout<<"PRESS 1: "<<FUNCTION<<" SERVICE "<<endl;        \
cout<<"PRESS 0: EXIT"<<endl;                           \
int button;                                            \
cout<<"PRESS: ";                                       \
cin>>button;
void Personnel::orderService(int room){
    while(1){

        CHOOSE("ORDER");
        switch (button)
        {
        case 1:
            while(1){
                int ID;
                cout<<"PRESS ID: ";
                cin>>ID;
                int check=0;
                for(int i=0;i<this->manage.getVecService().size();i++){
                    if(ID==this->manage.getVecService()[i].getId()){
                        cout<<"Your Choose: "<<this->manage.getVecService()[i].getName()<<endl;
                        int number;
                        cout<<"PRESS MUMBER: ";
                        cin>>number;
                        vector <Room> tempRoom=this->manage.getVecRoom();
                        vector <Service> tempService = tempRoom[room].getService();
                        tempService.push_back(this->manage.getVecService()[i]);
                        tempService[tempService.size()-1].setQuantity(number);
                        tempRoom[room].setService(tempService);
                        tempRoom[room].setStatus(BOOKED);
                        this->manage.setVecRoom(tempRoom);
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
void Personnel::updateOrderService(int room){
    if(this->manage.getVecRoom()[room].getService().empty()) return;
    while(1){
        CHOOSE("UPDATE");
        switch (button)
        {
        case 1:
            while (1)
            {
                int STT;
                cout<<"PRESS STT: ";
                cin>>STT;
                int Check=0;
                if(STT < this->manage.getVecRoom()[room].getService().size()){
                    Check=1;
                    while(1){
                        int ID;
                        cout<<"PRESS ID:";
                        cin >> ID;
                        int check=0;
                        for(int i=0;i<this->manage.getVecService().size();i++){
                            if(ID==this->manage.getVecService()[i].getId()){
                                cout<<"Your Choose: "<<this->manage.getVecService()[i].getName()<<endl;
                                int number;
                                cout<<"PRESS NUMBER: ";
                                cin>>number;
                                vector<Room> tempRoom=this->manage.getVecRoom();
                                vector<Service>tempService=tempRoom[room].getService();
                                tempService[STT]=this->manage.getVecService()[i];
                                tempService[STT].setQuantity(number);
                                tempRoom[room].setService(tempService);
                                tempRoom[room].setStatus(BOOKED);
                                this->manage.setVecRoom(tempRoom);
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
void Personnel::deleteOrderService(int room){
    if(this->manage.getVecRoom()[room].getService().empty()) return;
    while(1){
        CHOOSE("DELETE");
        switch (button)
        {
            case 1:
                while(1){
                	if(this->manage.getVecRoom()[room].getService().empty()) break;
                    int STT;
                    cout<<"PRESS STT: ";
                    cin>>STT;
                    int check =0;
                    if(STT < this->manage.getVecRoom()[room].getService().size()){
                        vector <Room> tempRoom=this->manage.getVecRoom();
                        vector <Service> tempService =tempRoom[room].getService();
                        tempService.erase(tempService.begin()+STT);
                        tempRoom[room].setService(tempService);
                        this->manage.setVecRoom(tempRoom);
                        check=1;
                        cout<<"SUCCESSFUL DELETE"<<endl;
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
void Personnel::displayOrderService(int room){
    cout<<"STT\tID\t"<<left<<setw(25)<<"NAME"<<left<<setw(10)<<"PRICE"<<left<<setw(8)<<"NUMBBER"<<"\tTOTAL\n";
    for(int i=0;i<this->manage.getVecRoom()[room].getService().size();i++){
        cout<<i<<"\t";
        cout<<(int)this->manage.getVecRoom()[room].getService()[i].getId()<<"\t";
        cout<<left<<setw(25)<<this->manage.getVecRoom()[room].getService()[i].getName();
        cout<<left<<setw(10)<<this->manage.getVecRoom()[room].getService()[i].getPrice();
        cout<<left<<setw(8)<<this->manage.getVecRoom()[room].getService()[i].getQuantity()<<"\t";
        cout<<this->manage.getVecRoom()[room].getService()[i].getTotal()<<"\n";
    }
}
void Personnel::payMoney(int room){
    cout<<"PAY MONEY"<<endl;
    if(this->manage.getVecRoom()[room].getStatus()==BOOKED){
        switch (this->manage.getVecRoom()[room].getRentaltype())
        {
        case HOUR:
            while(1){
            system("cls");
            cout<<"Rent by the hour"<<endl;
            cout<<"Price 1 hour: "<<this->manage.getPrice(HOUR)<<endl;
            cout<<"Start: ";
            this->manage.getVecRoom()[room].getStartHour().displayTime();
            cout<<"End: "<<endl;
            Hour endTime;
            endTime.setTime();
            endTime.displayTime();
            double priceRoom=this->calculationPricebyTime(this->manage.getVecRoom()[room].getStartHour(),endTime);
            cout<<"Price Room: "<<priceRoom<<endl;
            this->displayOrderService(room);
            double sum=0;
            for(int i=0;i<this->manage.getVecRoom()[room].getService().size();i++){
                sum+=this->manage.getVecRoom()[room].getService()[i].getTotal();
            }
            cout<<"Sum Price Service: "<<sum<<endl;
            sum+=priceRoom;
            cout<<"total amount to be paid: "<<sum<<endl;
            break;
            }
            break;
        case DAY:
            while(1){
            WRONGYEAR:
            system("cls");
            cout<<"Rent by day"<<endl;
            cout<<"Price 1 day: "<<this->manage.getPrice(DAY)<<endl;
            cout<<"Start: ";
            this->manage.getVecRoom()[room].getStartDate().displayDate();
            cout<<"End: "<<endl;
            Date endDate;
            endDate.setDate();
            double priceRoom=this->calculationPricebyDate(this->manage.getVecRoom()[room].getStartDate(),endDate);
            if(priceRoom <= 0) {
            	cout<<"EndDate is wrong Please Again!!"<<endl;
            	cout<<"ENTER TO COUTINUE"<<endl;
            	getch();
            	goto WRONGYEAR;
			}
			endDate.displayDate();
            cout<<"Price Room: "<<priceRoom<<endl;
            this->displayOrderService(room);
            double sum=0;
            for(int i=0;i<this->manage.getVecRoom()[room].getService().size();i++){
                sum+=this->manage.getVecRoom()[room].getService()[i].getTotal();
            }
            cout<<"Sum Price Service: "<<sum<<endl;
            sum+=priceRoom;
            cout<<"total amount to be paid: "<<sum<<endl;
            break;
            }
            break;
        default:
            break;
        }
        cout<<"PRESS 1:PAY MONEY"<<endl;
        cout<<"PRESS 0: EXIT "<<endl;
        while(1){
        cout<<"PRESS: ";
        int button;
        cin>>button;
        vector <Room> tempRoom =this->manage.getVecRoom();
        vector <Service> tempService = tempRoom[room].getService();
            switch (button)
            {
            case 1:
                tempService.clear();
                tempRoom[room].setService(tempService);
                tempRoom[room].setStatus(AVAILABLE);
                this->manage.setVecRoom(tempRoom);
                cout<<"PAYMENT SUCCESS!!"<<endl;
                break;
            case 0:
                break;
            default:
                break;
            }
            if(button ==0 || button == 1) break;
            cout<<"ENTER TO COUTINUE"<<endl;
            getch();
        }
    }
    else{
        cout<<"Please Rent the Room"<<endl;
    }
}
class Hotel{
    private:
        Manager Rmanage;
        Personnel Rpersonnel;
    public:
        void programManage();
        void programManageService();
        void programPersonnel();
        void programPersonnelService(int room);
};
void Hotel::programManageService(){
    while (1)
    {
        system("cls");
        cout<<"----MENU-----"<<endl;
        this->Rmanage.displayService();
        cout<<"----MANAGER SERVICE----"<<endl;
        cout<<"PRESS 1:ADD SERVICE"<<endl;
        cout<<"PRESS 2:UPDATE SERVICE"<<endl;
        cout<<"PRESS 3:DELETE SERVICE"<<endl;
        cout<<"PRESS 4:DISPLAY SERVICE"<<endl;
        cout<<"PRESS 0:EXIT"<<endl;
        int button;
        cout<<"PRESS: ";
        cin>>button;
        switch (button)
        {
        case 1:
            this->Rmanage.addService();
            break;
        case 2:
            this->Rmanage.updateService();
            break;
        case 3:
            this->Rmanage.deleteService();
            break;
        case 4:
            this->Rmanage.displayService();
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
void Hotel::programManage(){
    while (1)
    {
       system("cls");
       cout<<"-----MANAGE-----"<<endl;
       cout<<"PRESS 1: SET PRICE"<<endl;
       cout<<"PRESS 2: SET SERVICE"<<endl;
       cout<<"PRESS 3: SET ROOM"<<endl;
       cout<<"PRESS 0: EXIT"<<endl;
       int button;
       cout<<"PRESS: ";
       cin>>button;
       switch (button)
       {
        case 1:
        this->Rmanage.setPrice();
        break;
        case 2:
        this->programManageService();
        break;
        case 3:
        this->Rmanage.setRoom();
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
void Hotel::programPersonnelService(int room){
    while(1){
        system("cls");
        cout<<"-----ORDER SERVICE-----"<<endl;
        cout<<"PRESS 1:ADD DISH"<<endl;
        cout<<"PRESS 2:UPDATE DISH"<<endl;
        cout<<"PRESS 3:DELETE DISH"<<endl;
        cout<<"PRESS 4:DISPLAY DISH"<<endl;
        cout<<"PRESS 0:EXIT"<<endl;
        cout<<"PRESS :";
        int button;
        cin>>button;
        switch (button)
        {
        case 1:
            this->Rpersonnel.orderService(room);
            this->Rmanage=this->Rpersonnel.getManager();
            break;
        case 2:
            this->Rpersonnel.updateOrderService(room);
            this->Rmanage=this->Rpersonnel.getManager();
            break;
        case 3:
            this->Rpersonnel.deleteOrderService(room);
            this->Rmanage=this->Rpersonnel.getManager();
            break;
        case 4:
            this->Rpersonnel.displayOrderService(room);
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
void Hotel::programPersonnel(){
    this->Rpersonnel.setManager(this->Rmanage);
    this->Rpersonnel.displayRoom();
    if(this->Rmanage.getVecRoom().empty()){
        cout<<"Hotel close!!!"<<endl;
        return;
    }
    int room;
    while(1){
        cout<<"CHOSSE ROOM: ";
        cin>>room;
        if(room < this->Rmanage.getVecRoom().size()){
            break;
        }
        cout<<"NO HAVE ROOM !! PRESS AGAIN!! \n";
    }
    while(1){
        system("cls");
       cout<<"-----PERSONNEL-----"<<endl;
       cout<<"PRESS 1: RENT ROOM"<<endl;
       cout<<"PRESS 2: ORDER SERVICE"<<endl;
       cout<<"PRESS 3: PAY MONEY"<<endl;
       cout<<"PRESS 0: EXIT"<<endl;
       int button;
       cout<<"PRESS: ";
       cin>>button;
       switch (button)
       {
        case 1:
            this->Rpersonnel.rentRoom(room);
            this->Rmanage=this->Rpersonnel.getManager();
            break;
        case 2:
        	if(this->Rpersonnel.getManager().getVecRoom()[room].getStatus()==BOOKED){
            this->programPersonnelService(room);
            break;
            }
            cout<<"ORDER SERVICE"<<endl;
            cout<<"Please rent the room"<<endl;
            break;
        case 3:
            this->Rpersonnel.payMoney(room);
            this->Rmanage=this->Rpersonnel.getManager();
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
void programHotel(){
    Hotel program;
    while(1){
        system("cls");
        cout<<"- - HOTEL - -"<<endl;
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
int main(){

    programHotel();
}
