#include "Bilet.h"


Bilet::Bilet(double pret_, int bagaje_, bool masa_inclusa_,Persoana& p,std::vector<std::string>escale_):
    posesor(p),
    pret(pret_),
    nr_bagaje_incluse(bagaje_),
    masa_inclusa(masa_inclusa_),
    escale(escale_)
{
    this->id = 2;
    std::cout<<"Bilet creat cu succes\n";
}
std::ostream &operator<<(std::ostream &os, const Bilet& b) {
    os<<"Pret bilet: "<<b.pret<<'\n';
    os<<"Bagaje incluse: "<<b.nr_bagaje_incluse<<'\n';
    os<<"Masa inclusa: "<<(b.masa_inclusa == 1 ? "Da" : "Nu")<<'\n';
    os<<b.posesor<<'\n';
    os<<"Escale:\n";
    for(unsigned long long i = 0; i < b.escale.size(); i++){
        os<<b.escale[i]<<'\n';
    }
    return os;
}
Bilet::~Bilet() {
    //std::cout<<"Destructor Bilet apelat\n";
}
//getters
int Bilet::getId() {
    return this->id;
}
double Bilet::getPret() {
    return this->pret;
}

Persoana Bilet::getPosesor() {
    return this->posesor;
}

int Bilet::getBagaje() {
    return this->nr_bagaje_incluse;
}

bool Bilet::getMasa() {
    return this->masa_inclusa;
}

std::vector<std::string> Bilet::getEscale() {
    return this->escale;
}

void Bilet::setPosesor(Persoana &posesor_) {
    this->posesor = posesor_;
}

void Bilet::setPret(double pret_) {
    this->pret = pret_;
}

void Bilet::setBagaje(int bagaje) {
    this->nr_bagaje_incluse = bagaje;
}

void Bilet::setMasa(bool masa) {
    this->masa_inclusa = masa;
}

void Bilet::addEscala(std::string esc) {
    this->escale.push_back(esc);
}

void Bilet::removeEscala(std::string esc) {
    int poz = -1;
    for(unsigned long long i = 0; i <= this->escale.size(); ++i){
        if(this->escale[i] == esc){
            poz = i;
        }
    }
    if(poz == -1){
        std::cout<<"Zborul nu are escala la "<<esc<<'\n';
    }
    else{
        this->escale.erase(this->escale.begin()+poz);
    }
}



