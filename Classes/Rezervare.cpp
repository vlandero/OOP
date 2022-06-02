//
// Created by Vlad on 01.06.2022.
//

#include "Rezervare.h"

unsigned long long Rezervare::id_max = 0;

unsigned long long int Rezervare::getId() const {
    return id;
}

std::ostream &operator<<(std::ostream &os, const Rezervare &rezervare) {
    os << "Numele persoanei pe care s-a facut rezervarea: " << rezervare.nume_pers << "\nRestaurant: " << rezervare.restaurant << "\nAeroport: "
       << rezervare.aeroport << "\nNumarul de persoane: " << rezervare.nr_persoane << "\nID-ul rezervarii este:"<<rezervare.id<<'\n';
    if(rezervare.reducere){
        std::cout<<"Reducere "<<rezervare.reducere<<"%\n";
    }
    if(rezervare.buget){
        std::cout<<"Buget "<<rezervare.buget<<" euro\n";
    }
    return os;
}
