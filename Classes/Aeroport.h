//
// Created by Vlad on 09.04.2022.
//

#ifndef OOP_AEROPORT_H
#define OOP_AEROPORT_H

#include <string>
#include <vector>
#include "Zbor.h"

class Aeroport {
    std::string nume;
    std::string abreviere; //este unica, se poate folosi pe post de id
    std::string locatie;
    std::vector<Zbor> plecari;
    std::vector<Zbor> sosiri;
public:
    void afisare(std::ostream &out) const;
    void addPlecare(Zbor& z);
    void addSosire(Zbor& z);
    [[nodiscard]] const std::string &getAbreviere() const;
    friend std::ostream& operator<<(std::ostream& os,const Aeroport& a);
    explicit Aeroport(std::istream &in);
    Aeroport() = default;
};


#endif //OOP_AEROPORT_H
