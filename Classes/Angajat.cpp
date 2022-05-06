//
// Created by Vlad on 08.04.2022.
//

#include "Angajat.h"

#include <utility>
int Angajat::reducere = 5;
void Angajat::afisare(std::ostream &os) const {
    os<<"Angajat\n";
    os<<"Post: "<<this->post<<'\n';
    os<<"Aeroport: "<<this->aeroport<<'\n';
    Persoana::afisare(os);
    os<<"Salariu: "<<this->salariu<<'\n';
}

std::ostream &operator<<(std::ostream &os, const Angajat &p) {
    p.afisare(os);
    return os;
}

Angajat::Angajat(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
                 const std::vector<Bilet> &b, int salariu, std::string post_,std::string aeroport,std::string tip_) : Persoana(nume, prenume, varsta, cnp,
                                                                                             b,std::move(tip_)), salariu(salariu),post(std::move(post_)),aeroport(std::move(aeroport)){
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
    salary = verifInt(S);
    std::string a;
    os<<"Introduceti aeroportul la care lucreaza\n";
    is>>a;
    aeroport = a;
    os<<"Introduceti postul ocupat\n";
    is>>Post;
    post = Post;
    salariu = salary;
    tip = "Angajat";
}

void Angajat::calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) {
    double pret = 0;
    double pretBagajCala = 0,pretBagajMana = 0;
    for(auto &z : b.getZboruri()){
        pretBagajCala += z.getDistanta() * Bilet::getPretBagajCalaKm();
        pretBagajMana += z.getDistanta() * Bilet::getPretBagajManaKm();
        pret += z.getDistanta() * Bilet::getPretBiletKm();
    }
    out<<"Pretul zborului este de "<<pret<<", la care se aplica o reducere de "<<reducere<<"%\n";
    pret *= (double(100 - reducere) / 100);
    int bb;
    out<<"Introduceti numarul de bagaje de cala dorit ("<<pretBagajCala<<" per bagaj)\n";
    in>>bb;
    b.setBagajeCala(bb);
    pret += bb * pretBagajCala;
    out<<"Introduceti numarul de bagaje de mana dorit ("<<pretBagajMana<<" per bagaj)\n";
    in>>bb;
    b.setBagajeMana(bb);
    pret += bb * pretBagajMana;
    out<<"Totalul de plata: "<<pret<<"\n";
    b.setPret(pret);
}

Angajat::~Angajat() = default;
