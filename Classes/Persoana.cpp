//
// Created by Vlad on 02.03.2022.
//

#include "Persoana.h"

Persoana::Persoana(std::string nume_, std::string prenume_, int varsta_, std::string CNP_):
nume(nume_),
prenume(prenume_),
varsta(varsta_),
CNP(CNP_){
    //std::cout<<"Persoana creata\n";
}

std::ostream &operator<<(std::ostream &os, const Persoana &p) {
    os<<p.nume<<' '<<p.prenume<<": "<<p.varsta<<" ani\n";
    os<<"CNP: "<<p.CNP<<'\n';
    return os;
}

Persoana::~Persoana() {
    //std::cout<<"Destructor Persoana apelat\n";
}

Persoana &Persoana::operator=(const Persoana &other) {
    this->nume = other.nume;
    this->prenume = other.prenume;
    this->varsta = other.varsta;
    this->CNP = other.CNP;
    return *this;
}

Persoana::Persoana(const Persoana &other):
    nume(other.nume),
    prenume(other.prenume),
    varsta(other.varsta),
    CNP(other.CNP){
    //std::cout<<"Constructor de copiere apelat\n";
}
