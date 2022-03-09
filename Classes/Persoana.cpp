//
// Created by Vlad on 02.03.2022.
//

#include "Persoana.h"

#include <utility>

Persoana::Persoana(std::string nume_, std::string prenume_, int varsta_, std::string CNP_,std::vector<Bilet>b,std::string _id):
id(std::move(_id)),
nume(std::move(nume_)),
prenume(std::move(prenume_)),
varsta(varsta_),
CNP(std::move(CNP_)),
bilete(b){
    this->id = 1;
    //std::cout<<"Persoana creata\n";
}

std::ostream &operator<<(std::ostream &os, const Persoana &p) {
    os<<p.nume<<' '<<p.prenume<<": "<<p.varsta<<" ani\n";
    os<<"CNP: "<<p.CNP<<"\n\n";
    os<<"Bilete:\n\n";
    for(unsigned long long i = 0; i < p.bilete.size(); ++i){
        std::cout<<i+1<<":\n"<<p.bilete[i]<<'\n';
    }
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
    this->bilete = other.bilete;
    this->id = other.id;
    return *this;
}

Persoana::Persoana(const Persoana &other):
    id(other.id),
    nume(other.nume),
    prenume(other.prenume),
    varsta(other.varsta),
    CNP(other.CNP),
    bilete(other.bilete)
    {
    //std::cout<<"Constructor de copiere apelat\n";
}
