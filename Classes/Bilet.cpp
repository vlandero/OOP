#include "Bilet.h"

#include <utility>


Bilet::Bilet(std::string _id,double pret_, int bagajeCala_,int bagajeMana_, bool masa_inclusa_,std::vector<Zbor>zboruri_):
    id(std::move(_id)),
    pret(pret_),
    bagajeCala(bagajeCala_),
    bagajeMana(bagajeMana_),
    masa_inclusa(masa_inclusa_),
    zboruri(std::move(zboruri_))
{
    //std::cout<<"Bilet creat cu succes\n";
}
std::ostream &operator<<(std::ostream &os, const Bilet& b) {
    os<<"Pret bilet: "<<b.pret<<" euro\n";
    os<<"Bagaje de cala incluse: "<<b.bagajeCala<<'\n';
    os<<"Bagaje de mana incluse: "<<b.bagajeMana<<'\n';
    os<<"Masa inclusa: "<<(b.masa_inclusa == 1 ? "Da" : "Nu")<<'\n';
    for(const auto & i : b.zboruri)
        os<<i<<'\n';
    return os;
}
Bilet::~Bilet() {
    //std::cout<<"Destructor Bilet apelat\n";
}




