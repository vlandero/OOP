//
// Created by Vlad on 02.03.2022.
//

#include "Persoana.h"
#include "Angajat.h"
#include "Client.h"
#include "VIP.h"
#include <utility>
unsigned long long Persoana::id_max = 0;
Persoana::Persoana(std::string nume_, std::string prenume_, int varsta_, std::string CNP_,std::vector<Bilet>b):
nume(std::move(nume_)),
prenume(std::move(prenume_)),
varsta(varsta_),
CNP(std::move(CNP_)),
bilete(std::move(b)){
    id = id_max;
    id_max++;
}

std::ostream &operator<<(std::ostream &os, const Persoana &p) {
    p.afisare(os);
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

void Persoana::afisare(std::ostream &os) const {
    os<<"ID: "<<this->id<<'\n';
    os<<this->nume<<' '<<this->prenume<<": "<<this->varsta<<" ani\n";
    os<<"CNP: "<<this->CNP<<"\n";
    os<<"Bilete:\n";
    for(unsigned long long i = 0; i < this->bilete.size(); ++i){
        std::cout<<i+1<<": "<<this->bilete[i]<<'\n';
    }
}

void Persoana::citire(std::istream &is,std::ostream &os) {
    std::string Nume,Prenume,cnp,V;
    int v;
    os<<"Introduceti numele persoanei\n";
    is>>Nume;
    os<<"Introduceti prenumele persoanei\n";
    is>>Prenume;
    os<<"Introduceti CNP\n";
    is>>cnp;
    Utility::verifCNP(cnp);

    os<<"Introduceti varsta\n";
    is>>V;
    v = Utility::verifInt(V);
    nume = Nume;
    prenume = Prenume;
    CNP = cnp;
    varsta = v;
    id = id_max;
    id_max++;
}

std::shared_ptr<Persoana> Persoana::create(std::istream &is) {
    std::shared_ptr<Persoana> p;
    std::string functie;
    std::cout<<"Introduceti functia persoanei (Angajat, Client, VIP)\n";
    is>>functie;
    if(functie == "Angajat" || functie == "angajat")
        p = std::make_shared<Angajat>();
    else if(functie == "Client" || functie == "client")
        p = std::make_shared<Client>();
    else if(functie == "VIP" || functie == "vip")
        p = std::make_shared<VIP>();
    else
        throw eroare_consola{"Tip inexistent"};

    p->citire(is,std::cout);

    return p;

}

void Persoana::addBilet(Bilet &b) {
    this->bilete.push_back(b);
}


unsigned long long int Persoana::getId() const {
    return id;
}

const std::string &Persoana::getNume() const {
    return nume;
}

const std::string &Persoana::getPrenume() const {
    return prenume;
}

void Persoana::provCalculeazaPret(Bilet &b,int discount_zboruri,int bagajeCala_incluse,int bagajeMana_incluse, std::istream &in, std::ostream &out) {
    double pret = 0;
    double pretBagajCala = 0,pretBagajMana = 0;
    for(auto &z : b.getZboruri()){
        pretBagajCala += z.getDistanta() * Bilet::getPretBagajCalaKm();
        pretBagajMana += z.getDistanta() * Bilet::getPretBagajManaKm();
        pret += z.getDistanta() * Bilet::getPretBiletKm();
    }
    out<<"Pretul zborului este de "<<pret<<", la care se aplica o reducere de "<<discount_zboruri<<"%\n";
    pret *= (double(100 - discount_zboruri) / 100);
    int bb = 0;
    out<<"Introduceti numarul de bagaje de cala dorit ("<<pretBagajCala<<" per bagaj, momentan aveti "<<bagajeCala_incluse<<" incluse)\n";
    in>>bb;
    b.setBagajeCala(bb + bagajeCala_incluse);
    pret += bb * pretBagajCala;
    out<<"Introduceti numarul de bagaje de mana dorit ("<<pretBagajMana<<" per bagaj, momentan aveti "<<bagajeCala_incluse<<" incluse)\n";
    in>>bb;
    b.setBagajeMana(bb + bagajeMana_incluse);
    pret += bb * pretBagajMana;
    out<<"Totalul de plata: "<<pret<<"\n";
    b.setPret(pret);
}

