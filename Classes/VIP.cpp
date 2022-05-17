//
// Created by Vlad on 04.05.2022.
//

#include "VIP.h"

#include <utility>

void VIP::afisare(std::ostream &os) const {
    os<<"VIP\n";
    Persoana::afisare(os);
    os<<"Nivel VIP: "<<nivel_VIP<<'\n';
    os<<"Pret VIP: "<<pretVIP<<'\n';
    os<<"Discount zboruri: "<<discount_zboruri<<"%\n";
    os<<"Discount Duty-Free: "<<discount_duty_free<<"%\n";
    os<<"Buget mancare: "<<buget_mancare<<" (per zbor, fie in aeroport, fie in avion extra)\n";
}

std::ostream &operator<<(std::ostream &os, const VIP &p) {
    p.afisare(os);
    return os;
}

VIP::VIP(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
               const std::vector<Bilet> &b,int nivel, int buget_m,int d_duty_free,int d_zboruri) : Persoana(nume, prenume, varsta, cnp,
                                                       b),nivel_VIP(nivel),buget_mancare(buget_m),discount_duty_free(d_duty_free),discount_zboruri(d_zboruri){
//    std::cout<<"Constructor VIP\n";
}

std::shared_ptr<Persoana> VIP::clone() const {
    return std::make_shared <VIP>(*this);
}

void VIP::citire(std::istream &is, std::ostream &os) {
    Persoana::citire(is, os);
    std::string niv;
    os<<"Introduceti nivelul VIP (1/2/3/4)";
    is>>niv;
    if(niv == "1"){
        nivel_VIP = 1;
        buget_mancare = 30;
        discount_duty_free = 5;
        discount_zboruri = 3;
        bagajeMana_incluse = 0;
        bagajeCala_incluse = 0;
        pretVIP = 80;
    }
    else if(niv == "2"){
        nivel_VIP = 2;
        buget_mancare = 40;
        discount_duty_free = 8;
        discount_zboruri = 8;
        bagajeMana_incluse = 0;
        bagajeCala_incluse = 0;
        pretVIP = 150;
    }
    else if(niv == "3"){
        nivel_VIP = 3;
        buget_mancare = 50;
        discount_duty_free = 12;
        discount_zboruri = 12;
        bagajeMana_incluse = 1;
        bagajeCala_incluse = 0;
        pretVIP = 210;
    }
    else if(niv == "4"){
        nivel_VIP = 4;
        buget_mancare = 60;
        discount_duty_free = 18;
        discount_zboruri = 18;
        bagajeMana_incluse = 1;
        bagajeCala_incluse = 1;
        pretVIP = 320;
    }
    else{
        throw eroare_consola("Nivel VIP invalid");
    }

}

void VIP::calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) {
    Persoana::provCalculeazaPret(b,discount_zboruri,bagajeCala_incluse,bagajeMana_incluse,in,out);
}

VIP::~VIP() = default;
