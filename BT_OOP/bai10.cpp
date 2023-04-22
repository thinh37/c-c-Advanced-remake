#include <iostream>
#include <cmath>
#include <stdint.h>
#include <string>
using namespace std;

class Book
{
    private:
        string name;
        string author;
        uint16_t year;
        uint16_t quantity;
    public:
    Book(string name,string author ,uint16_t year);
    void setQuantily(uint16_t quantity);
    void borrowBook();
    void returnBook();
    void printBook();
};


Book::Book(string name,string author ,uint16_t year){
    this->name=name;
    this->author=author;
    this->year=year;
}

void Book::setQuantily(uint16_t quantity){
    this->quantity=quantity;
}
void Book::borrowBook(){
    if (this->quantity > 0) {
        this->quantity--;
        cout << "Muon sach thanh cong." << endl;
     } else {
        cout << "Khong co sach" << endl;
    }
}
void Book::returnBook(){
    this->quantity++;
    cout << "tra sach thanh cong" << endl;
}

void Book::printBook(){
    cout << "Ten: " << this->name << endl;
    cout << "Tac gia: " << this->author << endl;
    cout << "Nam san xuat: " << this->year << endl;
    cout << "so luong: " << this->quantity << endl;
}

int main(int argc, char const *argv[])
{
    Book b("toi thay hoa vang tren co xanh","Nguyen Nhat Anh",2010);
    b.setQuantily(20);
    b.borrowBook();
    b.printBook();
    b.returnBook();
    return 0;
}


