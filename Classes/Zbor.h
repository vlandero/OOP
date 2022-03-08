#ifndef OOP_ZBOR_H
#define OOP_ZBOR_H
#include <string>
#include <utility>
#include <iostream>

struct Ora{
    int h;
    int min;
};

class Zbor{
    int id;
    std::string plecare;
    std::string destinatie;
    Ora oraPlecare{};
    Ora oraSosire{};
public:
    friend std::ostream& operator<<(std::ostream& os,const Zbor& z);
    Zbor(std::string plecare_,std::string destinatie_,int plecare_h,int plecare_min,int sosire_h,int sosire_min);
    ~Zbor();
};


#endif //OOP_ZBOR_H
