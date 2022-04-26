#include "Bilet.h"

#include <utility>

unsigned long long Bilet::id_max = 0;
Bilet::Bilet(double pret_, int bagajeCala_,int bagajeMana_, bool masa_inclusa_,std::vector<Zbor>zboruri_):
    pret(pret_),
    bagajeCala(bagajeCala_),
    bagajeMana(bagajeMana_),
    masa_inclusa(masa_inclusa_),
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
    os<<"Masa inclusa: "<<(b.masa_inclusa ? "Da" : "Nu")<<'\n';
    for(const auto & zbor : b.zboruri)
        os<<zbor<<'\n';
    return os;
}
Bilet::~Bilet() {
    //std::cout<<"Destructor Bilet apelat\n";
}

int Bilet::verifInt(const std::string& s) {
    int num = 0;
    for(auto &n : s){
        if(!std::isdigit(n)){
            throw eroare_consola{"Introduceti numar"};
        }
        num = num * 10 + int(n - '0');
    }
    return num;
}

void Bilet::citire(std::istream &in, std::ostream &out,std::unordered_map<std::string,Aeroport>aeroporturi) {
    out<<"Introduceti ID-ul persoanei pentru care vreti sa creati un bilet\n";
    int ID;
    std::string idd;
    try{
        ID = verifInt(idd);
    }
    catch(eroare_consola& err){
        throw;
    };
    std::cout<<ID<<'\n';
    std::string plecareID,destinatieID;
    out<<"Selectati aeroportul plecarii (ID):\n";
    in>>plecareID;
    if(aeroporturi.find(plecareID) == aeroporturi.end())
        throw eroare_consola("Aeroport inexistent");
    out<<"Selectati aeroportul sosirii (ID):\n";
    in>>destinatieID;
    if(aeroporturi.find(destinatieID) == aeroporturi.end())
        throw eroare_consola("Aeroport inexistent");
    std::string tip;
    out<<"Selectati tipul zborului (Cu escale/Fara escale):\n";
    in>>tip;
    if(tip != "Cu escale" && tip != "Fara escale")
        throw eroare_consola("Tip invalid");
}

Bilet::Bilet(std::istream &in,std::unordered_map<std::string,Aeroport>aeroporturi) {
    citire(in,std::cout,std::move(aeroporturi));
}






