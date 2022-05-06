#ifndef OOP_ZBOR_H
#define OOP_ZBOR_H
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include "Time.h"


class Zbor{
    unsigned long long id{};
    int distanta{}; //pret 0.32/km
    std::string plecare;
    std::string destinatie;
    tm detalii_plecare{};
    tm detalii_sosire{};
public:
    static unsigned long long id_max;
    [[nodiscard]] const std::string &getPlecare() const;

    int getDistanta() const;

    const tm &getDetaliiPlecare() const;

    const tm &getDetaliiSosire() const;

    [[nodiscard]] const std::string &getDestinatie() const;

    [[nodiscard]] const unsigned long long &getId() const;
    friend std::ostream& operator<<(std::ostream& os,const Zbor& z);
    Zbor(std::string plecare_,std::string destinatie_, int dist,std::tm plecare, std::tm sosire);
    explicit Zbor(std::istream &in);
    ~Zbor();
    Zbor() = default;
};


#endif //OOP_ZBOR_H
