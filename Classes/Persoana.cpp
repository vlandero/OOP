//
// Created by Vlad on 02.03.2022.
//

#include "Persoana.h"
#include "Angajat.h"
#include "Client.h"
#include "VIP.h"
#include <utility>
unsigned long long Persoana::id_max = 0;
Persoana::Persoana(std::string nume_, std::string prenume_, int varsta_, std::string CNP_,std::vector<Bilet>b,std::string tip_):
nume(std::move(nume_)),
prenume(std::move(prenume_)),
varsta(varsta_),
CNP(std::move(CNP_)),
bilete(std::move(b)),
tip(std::move(tip_)){
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
    this->tip = other.tip;
    return *this;
}

Persoana::Persoana(const Persoana &other):
    id(other.id),
    nume(other.nume),
    prenume(other.prenume),
    varsta(other.varsta),
    CNP(other.CNP),
    bilete(other.bilete),
    tip(other.tip)
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
    verifCNP(cnp);

    os<<"Introduceti varsta\n";
    is>>V;
    try{
        v = verifInt(V);
    }
    catch (eroare_consola& err){
        throw;
    }
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
    try{
        if(functie == "Angajat" || functie == "angajat")
            p = std::make_shared<Angajat>();
        else if(functie == "Client" || functie == "client")
            p = std::make_shared<Client>();
        else if(functie == "VIP" || functie == "vip")
            p = std::make_shared<VIP>();
        else
            throw eroare_consola{"Tip inexistent"};

        p->citire(is,std::cout);
    }
    catch (eroare_consola& err){
        throw;
    }

    return p;

}

void Persoana::addBilet(Bilet &b) {
    this->bilete.push_back(b);
}

int Persoana::verifInt(const std::string& s) {
    int num = 0;
    for(auto &n : s){
        if(!std::isdigit(n)){
            throw eroare_consola{"Introduceti numar"};
        }
        num = num * 10 + int(n - '0');
    }
    return num;
}

void Persoana::verifCNP(std::string cnp) {
    if(cnp.size() != 13)
        throw eroare_consola{"CNP invalid"};
    for(auto &n : cnp){
        if(!std::isdigit(n)){
            throw eroare_consola{"CNP invalid"};
        }
    }
    std::string p;
    int day,month,year;
    p.push_back(cnp[1]);
    p.push_back(cnp[2]);
    year = std::stoi(p);
    p.clear();
    p.push_back(cnp[3]);
    p.push_back(cnp[4]);
    month = std::stoi(p);
    p.clear();
    p.push_back(cnp[5]);
    p.push_back(cnp[6]);
    day = std::stoi(p);
    p.clear();

    if(!validDate(year,month,day))
        throw eroare_consola{"CNP invalid"};
}

bool Persoana::validDate(int year, int month, int day) {
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if ((year % 4 == 0) && (year % 100 != 0))
            return (day <= 29);
        else
            return (day <= 28);
    }
    if (month == 4 || month == 6 ||
        month == 9 || month == 11)
        return (day <= 30);
    return true;
}

unsigned long long int Persoana::getId() const {
    return id;
}

const std::string &Persoana::getTip() const {
    return tip;
}
