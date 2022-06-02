//
// Created by Vlad on 09.04.2022.
//

#include "Aeroport.h"

Aeroport::Aeroport(std::istream &in) {
    //nume \n abreviere \n locatie
    std::string name,abv,loc;
    std::getline(in,name);
    std::getline(in,abv);
    std::getline(in,loc);
    this->nume = name;
    this->abreviere = abv;
    this->locatie = loc;

}


const std::string &Aeroport::getAbreviere() const {
    return abreviere;
}

void Aeroport::addSosire(const Zbor& z) {
    this->sosiri.push_back(z);
}

void Aeroport::addPlecare(const Zbor& z) {
    this->plecari.push_back(z);
}

std::ostream &operator<<(std::ostream &os, const Aeroport &a) {
    os<<a.nume<<" ("<<a.abreviere<<"), "<<a.locatie<<'\n';
    os<<"Plecari:\n";
    printVec<Zbor>(a.plecari);
    os<<"Sosiri:\n";
    printVec<Zbor>(a.sosiri);
    os<<'\n';
    return os;
}

const std::vector<Zbor> &Aeroport::getPlecari() const {
    return plecari;
}
