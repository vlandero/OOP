#include "Bilet.h"

#include <utility>

unsigned long long Bilet::id_max = 0;
double Bilet::pretBagajMana_km = 0.01;
double Bilet::pretBagajCala_km = 0.05;
double Bilet::pretBilet_km = 0.16;
Bilet::Bilet(double pret_, int bagajeCala_,int bagajeMana_,std::vector<Zbor>zboruri_):
    pret(pret_),
    bagajeCala(bagajeCala_),
    bagajeMana(bagajeMana_),
    zboruri(std::move(zboruri_))
{
    id = id_max;
    id_max++;
    //std::cout<<"Bilet creat cu succes\n";
}
std::ostream &operator<<(std::ostream &os, const Bilet& b) {
    os<<"Pret bilet: "<<b.pret<<" euro\n";
    os<<"Bagaje de cala incluse: "<<b.bagajeCala<<'\n';
    os<<"Bagaje de mana incluse: "<<b.bagajeMana<<'\n';
    for(const auto & zbor : b.zboruri)
        os<<zbor;
    return os;
}
Bilet::~Bilet() {
    //std::cout<<"Destructor Bilet apelat\n";
}


void Bilet::citire(std::istream &in, std::ostream &out,std::unordered_map<std::string,Aeroport>aeroporturi) {
    std::string plecareID,destinatieID;
    out<<"Selectati aeroportul plecarii (ID):\n";
    in>>plecareID;
    if(aeroporturi.find(plecareID) == aeroporturi.end())
        throw eroare_consola("Aeroport inexistent");
    out<<"Selectati aeroportul sosirii (ID):\n";
    in>>destinatieID;
    if(aeroporturi.find(destinatieID) == aeroporturi.end())
        throw eroare_consola("Aeroport inexistent");
    int tip;
    out<<"Selectati tipul zborului (1 - fara escala/2 - cu escala/3 - toate):\n";
    in>>tip;
    out<<"Selectati zborul dorit\n";
    Aeroport aeroport_plecare = aeroporturi[plecareID];
    Aeroport aeroport_sosire = aeroporturi[destinatieID];
    if(tip != 1 && tip != 2 && tip != 3)
        throw eroare_consola("Tip invalid");
    std::vector<Zbor> zb1;
    std::vector<std::pair<Zbor,Zbor>>zb2;
    for(auto &z : aeroport_plecare.getPlecari()){
        if(z.getDestinatie() == aeroport_sosire.getAbreviere())
            zb1.push_back(z);
    }
    for(auto &z : aeroport_plecare.getPlecari()){
        auto sosire = z.getDestinatie();
        auto aeroport_intermediar = aeroporturi[sosire];
        for(auto &z1 : aeroport_intermediar.getPlecari()){
            if(z1.getDestinatie() == aeroport_sosire.getAbreviere()){
                auto temp1 = z.getDetaliiPlecare();
                auto temp2 = z.getDetaliiSosire();
                time_t t1 = mktime(&temp1);
                time_t t2 = mktime(&temp2);
                double dif = difftime(t2,t1)/(60*60*24);
                if(dif > 0 && dif < 1)
                    zb2.emplace_back(z,z1);
            }
        }
    }
    unsigned long long i = 0;
    switch(tip){
        case 1: //fara escala
            if(zb1.empty())
                return;
            for(auto &z : zb1){
                out<<"Zbor "<<++i<<":\n"<<z;
            }
            break;
        case 2: //cu escala
            if(zb2.empty())
                return;
            for(auto &z:zb2){
                out<<"Zbor "<<++i<<":\n";
                out<<z.first<<z.second<<'\n';
            }
            break;
        case 3:
            if(zb1.empty() && zb2.empty())
                return;
            for(auto &z : zb1){
                out<<"Zbor "<<++i<<":\n"<<z;
            }
            for(auto &z:zb2){
                out<<"Zbor "<<++i<<":\n";
                out<<z.first<<z.second<<'\n';
            }
            break;
        default:
            break;
    }
    unsigned long long nrz;

    in>>nrz;
    if(nrz > i){
        throw eroare_input{"Zbor invalid"};
    }
    if(i == 0){
        return;
    }
    out<<i<<' '<<nrz<<'\n';
    i--;
    nrz--;
    out<<i<<' '<<nrz<<'\n';
    Zbor zbor_selectat;
    std::pair<Zbor,Zbor> zbor_selectat_esc;
    if(tip == 3){
        if(nrz >= zb1.size())
        {
            zbor_selectat_esc = zb2[i-nrz];
            zboruri.push_back(zbor_selectat_esc.first);
            zboruri.push_back(zbor_selectat_esc.second);
        }
        else{
            zbor_selectat = zb1[nrz];
            zboruri.push_back(zbor_selectat);
        }
    }
    else if(tip == 2){
        zbor_selectat_esc = zb2[nrz];
        zboruri.push_back(zbor_selectat_esc.first);
        zboruri.push_back(zbor_selectat_esc.second);
    }
    else{
        zbor_selectat = zb1[nrz];
        zboruri.push_back(zbor_selectat);
    }



}

Bilet::Bilet(std::istream &in,std::unordered_map<std::string,Aeroport>aeroporturi) {
    citire(in,std::cout,std::move(aeroporturi));
    id = id_max;
    id_max++;
}

void Bilet::setPret(double prett) {
    Bilet::pret = prett;
}



double Bilet::getPretBagajManaKm() {
    return pretBagajMana_km;
}

double Bilet::getPretBagajCalaKm() {
    return pretBagajCala_km;
}

double Bilet::getPretBiletKm() {
    return pretBilet_km;
}

const std::vector<Zbor> &Bilet::getZboruri() const {
    return zboruri;
}

void Bilet::setBagajeCala(int bagajeC) {
    Bilet::bagajeCala = bagajeC;
}

void Bilet::setBagajeMana(int bagajeM) {
    Bilet::bagajeMana = bagajeM;
}

unsigned long long int Bilet::getId() const {
    return id;
}






