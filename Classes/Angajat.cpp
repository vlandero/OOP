//
// Created by Vlad on 08.04.2022.
//

#include "Angajat.h"

#include <utility>

void Angajat::afisare(std::ostream &os) const {
    os<<"Angajat\n";
    os<<"Post: "<<this->post<<'\n';
    Persoana::afisare(os);
    os<<"Salariu: "<<this->salariu<<'\n';
}

std::ostream &operator<<(std::ostream &os, const Angajat &p) {
    p.afisare(os);
    return os;
}

Angajat::Angajat(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
                 const std::vector<Bilet> &b, int salariu, std::string post_) : Persoana(nume, prenume, varsta, cnp,
                                                                                             b), salariu(salariu),post(std::move(post_)){
//    std::cout<<"Constructor angajat\n";
}

std::shared_ptr<Persoana> Angajat::clone() const {
    return std::make_shared <Angajat>(*this);
}

void Angajat::citire(std::istream &is, std::ostream &os) {
    int salary = 0;
    std::string Post,S;
    Persoana::citire(is, os);
    os<<"Introduceti salariul\n";
    is>>S;
    try{
        salary = verifInt(S);
    }
    catch(eroare_consola& err){
        throw err;
    }
    os<<"Introduceti postul ocupat\n";
    is>>Post;
    post = Post;
    salariu = salary;
}

Angajat::~Angajat() = default;
