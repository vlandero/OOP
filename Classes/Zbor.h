#ifndef OOP_ZBOR_H
#define OOP_ZBOR_H
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <ctime>


class Zbor{
    std::string id;
    int max_pasageri{};
    std::string plecare;
    std::string destinatie;
    tm detalii_plecare{};
    tm detalii_sosire{};
public:
    [[nodiscard]] const std::string &getPlecare() const;

    [[nodiscard]] const std::string &getDestinatie() const;

    [[nodiscard]] const std::string &getId() const;
    friend std::ostream& operator<<(std::ostream& os,const Zbor& z);
    Zbor(std::string plecare_,std::string destinatie_, int max_pas,std::tm plecare, std::tm sosire,std::string ID);
    explicit Zbor(std::istream &in);
    ~Zbor();
    Zbor() = default;
};


#endif //OOP_ZBOR_H
