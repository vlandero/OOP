//
// Created by Vlad on 04.05.2022.
//

#include "Client.h"


void Client::afisare(std::ostream &os) const {
    os << "Client\n";
    Persoana::afisare(os);
}

std::ostream &operator<<(std::ostream &os, const Client &p) {
    p.afisare(os);
    return os;
}

Client::Client(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
               const std::vector<Bilet> &b) : Persoana(nume, prenume, varsta, cnp,
                                                       b) {
//    std::cout<<"Constructor Client\n";
}

std::shared_ptr<Persoana> Client::clone() const {
    return std::make_shared<Client>(*this);
}

void Client::citire(std::istream &is, std::ostream &os) {
    Persoana::citire(is, os);
}

void Client::calculeazaPret(Bilet &b, std::istream &in, std::ostream &out) {
    out << "Nu aveti nimic inclus\n";
    aplicareReducere(b, out);
    Persoana::calculeazaPret(b, in, out);
}

void Client::aplicareReducere(Bilet &b, std::ostream &out) {
    Persoana::aplicareReducere(b, out);
}

Client::~Client() = default;

