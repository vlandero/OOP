//
// Created by Vlad on 04.05.2022.
//

#include "Client.h"

#include <utility>

void Client::afisare(std::ostream &os) const {
    os<<"Client\n";
    Persoana::afisare(os);
}

std::ostream &operator<<(std::ostream &os, const Client &p) {
    p.afisare(os);
    return os;
}

Client::Client(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
                 const std::vector<Bilet> &b,std::string tip_) : Persoana(nume, prenume, varsta, cnp,
                                                                                         b,std::move(tip_)){
//    std::cout<<"Constructor Client\n";
}

std::shared_ptr<Persoana> Client::clone() const {
    return std::make_shared <Client>(*this);
}

void Client::citire(std::istream &is, std::ostream &os) {
    Persoana::citire(is, os);
    tip = "Client";
}

void Client::calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) {
    double pret = 0;
    int pretBagajCala = 0,pretBagajMana = 0;
    for(auto &z : b.getZboruri()){
        pretBagajCala += z.getDistanta() * Bilet::getPretBagajCalaKm();
        pretBagajMana += z.getDistanta() * Bilet::getPretBagajManaKm();
        pret += z.getDistanta() * Bilet::getPretBiletKm();
    }
    out<<"Pretul zborului este de "<<pret<<"\n";
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

Client::~Client() = default;

