//
// Created by Vlad on 01.06.2022.
//

#ifndef OOP_REZERVARE_H
#define OOP_REZERVARE_H

#include <string>
#include <iostream>
#include <utility>


class Rezervare {
    unsigned long long id{};
    static unsigned long long id_max;
    std::string nume_pers;
    std::string restaurant;
    std::string aeroport;
    int nr_persoane{};
    int reducere = 0;
    int buget = 0;
    friend class builder_rezervare;
public:
    [[nodiscard]] unsigned long long int getId() const;

    friend std::ostream &operator<<(std::ostream &os, const Rezervare &rezervare);

    Rezervare() = default;
};

class builder_rezervare{
    Rezervare r;
public:
    builder_rezervare() = default;
    builder_rezervare& restaurant(std::string& rs) {
        r.restaurant = std::move(rs);
        return *this;
    }
    builder_rezervare& aeroport(std::string& a) {
        r.aeroport = std::move(a);
        return *this;
    }
    builder_rezervare& nr_persoane(int n) {
        r.nr_persoane = n;
        return *this;
    }
    builder_rezervare& reducere(int n) {
        r.reducere = n;
        return *this;
    }
    builder_rezervare& buget(int n) {
        r.buget = n;
        return *this;
    }
    builder_rezervare& pers(std::string n) {
        r.nume_pers = std::move(n);
        return *this;
    }
    Rezervare build(){
        r.id = Rezervare::id_max++;
        return r;
    }
};




#endif //OOP_REZERVARE_H
