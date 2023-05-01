#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;

typedef enum{
    MALE,
    FEMALE
}Sex;

typedef enum{
    EXCELLENT,
    GOOD,
    NORMAL,
    BAD
}Rank;
class Student
{
private:
    uint16_t id;
    string name;
    Sex sex;
    uint16_t age;
    float math;
    float physical;
    float chemistry;
    float average;
    Rank rank;
public:
    Student(string name="Van a",Sex sex=MALE,uint16_t age=18,float math=0,float physical=0,float chemistry=0);
    void setName(string name);
    void setSex(Sex sex);
    void setAge(uint8_t age);
    void setMath(float math);
    void setPhysical(float physical);
    void setChemistry(float chemistry);
    uint16_t getId();
    string getName();
    uint16_t getAge();
    Sex getSex();
    float getMath();
    float getPhysical();
    float getChemistry();
    float getAverage();
    Rank getRank();
};

Student::Student(string name,Sex sex,uint16_t age,float math,float physical,float chemistry)
{
    static uint16_t id_add=100;
    this->id=id_add;
    id_add++;
    this->name=name;
    this->sex=sex;
    this->age=age;
    this->math=math;
    this->physical=physical;
    this->chemistry=chemistry;
}

void Student::setName(string name){
    this->name=name;
}
void Student::setSex(Sex sex){
    this->sex=sex;
}

void Student::setAge(uint8_t age){
    this->age=age;
}
void Student::setMath(float math){
    this->math=math;
}
void Student::setPhysical(float physical){
    this->physical=physical;
}
void Student::setChemistry(float chemistry){
    this->chemistry=chemistry;
}
uint16_t Student::getId(){
    return this->id;
}
string Student::getName(){
    return this->name;
}
uint16_t Student::getAge(){
    return this->age;
}
Sex Student::getSex(){
    return this->sex;
}
float Student::getMath(){
    return this->math;
}
float Student::getPhysical(){
    return this->physical;
}
float Student::getChemistry(){
    return this->chemistry;
}
float Student::getAverage(){
    return this->average=(this->math +this->physical +this->chemistry)/3;
}
Rank Student::getRank(){
    if(this->average >=8) return this->rank=EXCELLENT;
    else if(this->average > 6.5) return this->rank=GOOD;
    else if(this->average > 5) return this->rank=NORMAL;
	else return this->rank=BAD;	
}

class Manage{
    private:
        vector <Student> sv;
    public:
        void addStudent();
        void updateInformStudent();
        void deleteStudent();
        void searchbyName();
        void sortbyName();
        void sortbyGPA();
        void display();
};
#define POINTS(SUBJECT) \
SUBJECT:                \
cout<<#SUBJECT<<" : ";   \
cin >> SUBJECT;         \
if(SUBJECT <0 || SUBJECT >10) { \
    cout <<"Error!! again please!! "<<"(0< "<<#SUBJECT<<" < 10)"<<endl; \
    goto SUBJECT;\
} 

void Manage::addStudent(){
    string name;
    Sex sex;
    uint16_t age;
    float math,physical,chemistry;
    fflush(stdin);
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Age: ";
    cin >>age;
    int button;
    SEX:
    cout<<"Sex (0-MALE 1-FEMALE) :";
    cin >>button;
    if (button== MALE) sex=MALE;
    else if(button ==FEMALE) sex=FEMALE;
    else {
        cout <<"Error!! again please!!"<<endl;
        goto SEX;
    }
    cout <<"LEARNING POINTS \n";
    POINTS(math);
    POINTS(physical);
    POINTS(chemistry);
    Student student(name,sex,age,math,physical,chemistry);
    this->sv.push_back(student);
}

void Manage::deleteStudent(){
    if(this->sv.empty()) return;
    uint16_t ID;
    ID_AGAIN_DE:
    cout<<"PRESS ID: ";
    cin >>ID;
        for(int i=0;i<sv.size();i++){
            if(ID == sv[i].getId() ){
                this->sv.erase(this->sv.begin()+i);
				cout<<" SUCCESSFUL DELETE"<<endl;
                return;
            }
        }
        cout<<"NOT HAVE ID!! PLEASE AGAIN!"<<endl;
        goto ID_AGAIN_DE;
}

void Manage::updateInformStudent(){
    if(this->sv.empty()) return;
    cout<<"UPDATE INFORM"<<endl;
    uint16_t ID;
    string update;
    int intUpdate;
    ID_AGAIN_UP:
    cout<<"PRESS ID: ";
    cin >>ID;

        int index=-1;
        for(int i=0;i<sv.size();i++){
            if(ID == sv[i].getId() ){
                index=i;
            }
        }
        if(index==-1){
        cout<<"NOT HAVE ID!! PLEASE AGAIN!"<<endl;
        goto ID_AGAIN_UP;
    	}
        while(1){
        system("cls");
         this->display();
        cout<<"UPDATE INFORM"<<endl;
        cout<<"PRESS 1: UPDATE NAME"<<endl;
        cout<<"PRESS 2: UPDATE AGE "<<endl;
        cout<<"PRESS 3: UPDATE SEX "<<endl;
        cout<<"PRESS 4: UPDATE MATH "<<endl;
        cout<<"PRESS 5: UPDATE PHYSICAL  "<<endl;
        cout<<"PRESS 6: UPDATE CHEMISTRY   "<<endl;
        cout<<"PRESS 0: EXIT:" <<endl;
        int button;
        cout<<"PRESS: ";
        cin >> button;
        
        switch (button)
        {
        case 1:

            cout<<"NEW NAME: ";
            fflush(stdin);
            getline(cin,update);
            fflush(stdin);
            this->sv.at(index).setName(update);
            break;
        case 2:
            cout<<"NEW AGE: ";
            cin>>intUpdate;
            this->sv.at(index).setAge(intUpdate);
            break;
        case 3:
            SEX_UP:
            cout<<"NEW SEX (0-MALE 1-FEMALE): ";
            cin>>intUpdate;
            if(intUpdate==MALE) this->sv.at(index).setSex(MALE);
            else if( intUpdate == FEMALE) this->sv.at(index).setSex(FEMALE);
            else {
                cout <<"Error!! again please!!"<<endl;
                goto SEX_UP;
            }
            break;
            
        case 4:
            float NEWMATH;
            POINTS(NEWMATH);
            this->sv.at(index).setMath(NEWMATH);
            break;
        case 5:
            float NEWPHYSICAL;
            POINTS(NEWPHYSICAL);
            this->sv.at(index).setPhysical(NEWPHYSICAL);
            break;
        case 6:
            float NEWCHEMISTRY;
            POINTS(NEWCHEMISTRY);
            this->sv.at(index).setChemistry(NEWCHEMISTRY);
            break;
        case 0:
            break;
        default:
            break;
        }
        if(button == 0) break;
        }
}

#define LAYBEL() cout<<"ID\t"<<left<<setw(30)<<"NAME"<<"AGE\tSEX\tMATH\tCHEMISTRY\tPHYSICAL\tAVERAGE\t\tRANK\n";
#define DISPLAY()     \
        cout<<sv.at(i).getId()<<"\t";                               \
        cout<<left<<setw(30)<<sv.at(i).getName()<<"\t";                             \
        cout<<sv.at(i).getAge()<<"\t";                              \
        if(sv[i].getSex() == MALE)  cout<<"MALE"<<"\t";             \
        else cout<<"FEMALE"<<"\t";                                  \
        cout<<sv.at(i).getMath()<<"\t";                             \
        cout<<sv.at(i).getChemistry()<<"\t\t";                      \
        cout<<sv.at(i).getPhysical()<<"\t\t";                       \
        cout<<sv.at(i).getAverage()<<"\t\t";                        \
        if(sv[i].getRank() == EXCELLENT) cout<<"EXCELLENT"<<"\n";   \
        else if(sv[i].getRank() == GOOD) cout<<"GOOD"<<"\n";             \
        else if(sv[i].getRank() == NORMAL) cout<<"NORMAL"<<"\n";         \
        else cout<<"BAD"<<"\n";  
void Manage::display(){
    LAYBEL();
    for(int i=0;i<sv.size();i++){
        DISPLAY();
    }
}

void Manage::searchbyName(){
    if(this->sv.empty()) return;
    string tempName;
    cout<<"SEARCH STUDENT BY NAME \n";
    while(1){
    cout<<"PRESS NAME: ";
    fflush(stdin);
    getline(cin,tempName);
    
    for(int i=0;i<sv.size();i++){
        if(tempName == sv.at(i).getName()){
            LAYBEL();
            DISPLAY();
            return;
        }
    }
    cout<<"NO NAME!! PLEASE AGAIN"<<endl;
    }
}

void Manage::sortbyName(){
    Student temp;
    for(int i=0;i<sv.size();i++){
        for(int j=i+1;j<sv.size();j++){
            if(sv.at(i).getName() > sv.at(j).getName()){
                temp=sv[i];
                sv[i]=sv[j];
                sv[j]=temp;
            }
        }
    }
    cout<<"SUCCESSFUL SORT"<<endl;
}
void Manage::sortbyGPA(){
	Student temp;
    for(int i=0;i<sv.size();i++){
        for(int j=i+1;j<sv.size();j++){
            if(sv.at(i).getAverage() > sv.at(j).getAverage()){
                temp=sv[i];
                sv[i]=sv[j];
                sv[j]=temp;
            }
        }
    }
    cout<<"SUCCESSFUL SORT"<<endl;
}
void ManageStudent(){
    Manage student;
while(1){
    int button;
    system("cls");
    student.display();
    cout<<"---MANAGE STUDENT---"<<endl;
    cout<<"PRESS 1: ADD STUDENT"<<endl;
    cout<<"PRESS 2: DELETE STUDENT"<<endl;
    cout<<"PRESS 3: SEARCH STUDENT BY NAME"<<endl;
    cout<<"PRESS 4: SORT STUDENT BY GPA"<<endl;
    cout<<"PRESS 5: SORT STUDENT BY NAME"<<endl;
    cout<<"PRESS 6: UPDATE INFORM STUDENT"<<endl;
    cout<<"PRESS 7: DISPLAY LIST STUDENT "<<endl;
    cout<<"PRESS 0: EXIT "<<endl;
    cout<<"PRESS : ";
    cin>>button;
    switch (button)
    {
    case 1:
        student.addStudent();
        break;
    case 2:
        student.deleteStudent();
        break;
    case 3:
        student.searchbyName();
        break;
    case 4:
        student.sortbyGPA();
        break;
    case 5:
        student.sortbyName();
        break;
    case 6:
        student.updateInformStudent();
        break;
    case 7:
        student.display();
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
    ManageStudent();
}

