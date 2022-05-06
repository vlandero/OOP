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

void Aeroport::afisare(std::ostream &out) const {
    out<<this->nume<<" ("<<this->abreviere<<"), "<<this->locatie<<'\n';
    out<<"Plecari:\n";
    for(auto &plecare : plecari){
        out<<plecare;
    }
    out<<"Sosiri:\n";
    for(auto &sosire : sosiri){
        out<<sosire;
    }
    out<<'\n';
}

const std::string &Aeroport::getAbreviere() const {
    return abreviere;
}

void Aeroport::addSosire(Zbor& z) {
    this->sosiri.push_back(z);
}

void Aeroport::addPlecare(Zbor& z) {
    this->plecari.push_back(z);
}

std::ostream &operator<<(std::ostream &os, const Aeroport &a) {
    a.afisare(os);
    return os;
}

const std::vector<Zbor> &Aeroport::getPlecari() const {
    return plecari;
}
