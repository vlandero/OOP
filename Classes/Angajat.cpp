//
// Created by Vlad on 08.04.2022.
//

#include "Angajat.h"

#include <utility>

double Angajat::reducere = 5;

void Angajat::afisare(std::ostream &os) const {
    os << "Angajat\n";
    os << "Post: " << this->post << '\n';
    os << "Aeroport: " << this->aeroport << '\n';
    Persoana::afisare(os);
    os << "Salariu: " << this->salariu << '\n';
}

std::ostream &operator<<(std::ostream &os, const Angajat &p) {
    p.afisare(os);
    return os;
}

Angajat::Angajat(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
                 const std::vector<Bilet> &b, int salariu, std::string post_, std::string aeroport) : Persoana(nume,
                                                                                                               prenume,
                                                                                                               varsta,
                                                                                                               cnp,
                                                                                                               b),
                                                                                                      salariu(salariu),
                                                                                                      post(std::move(
                                                                                                              post_)),
                                                                                                      aeroport(
                                                                                                              std::move(
                                                                                                                      aeroport)) {
//    std::cout<<"Constructor angajat\n";
}

std::shared_ptr<Persoana> Angajat::clone() const {
    return std::make_shared<Angajat>(*this);
}

void Angajat::citire(std::istream &is, std::ostream &os) {
    int salary = 0;
    std::string Post, S;
    Persoana::citire(is, os);
    os << "Introduceti salariul\n";
    is >> S;
    salary = Utility::verifInt(S);
    std::string a;
    os << "Introduceti aeroportul la care lucreaza\n";
    is >> a;
    aeroport = a;
    os << "Introduceti postul ocupat\n";
    is >> Post;
    post = Post;
    salariu = salary;
}

void Angajat::calculeazaPret(Bilet &b, std::istream &in, std::ostream &out) {
    aplicareReducere(b, out);
    out << "Aveti " << reducere << "% reducere la zbor\n";
    Persoana::calculeazaPret(b, in, out);
}

void Angajat::aplicareReducere(Bilet &b, std::ostream &out) {
    Persoana::aplicareReducere(b, out);
    double pret = b.getPret();
    pret = pret * (reducere / 100);
    b.setPret(pret);
}

int Angajat::reducereRestaurant() {
    return 5;
}

int Angajat::bugetMancare() {
    return 30;
}

Angajat::~Angajat() = default;
