//
// Created by Vlad on 17.05.2022.
//

#ifndef OOP_FACTURA_H
#define OOP_FACTURA_H
#include "VIP.h"
#include "Angajat.h"
#include "Client.h"
#include "Bilet.h"


class Factura {
    std::shared_ptr<Persoana> pers;
    Bilet bilet;

public:
    Factura() = default;
    Factura(const std::shared_ptr<Persoana>& p, const Bilet& bt);
    Factura(const Factura& other);
    friend std::ostream& operator<<(std::ostream& os,const Factura& f);
    friend void swap(Factura& f1, Factura& f2);
    Factura& operator=(const Factura& other);
};


#endif //OOP_FACTURA_H
