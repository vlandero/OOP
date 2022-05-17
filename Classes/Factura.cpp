//
// Created by Vlad on 17.05.2022.
//

#include "Factura.h"

Factura::Factura(const std::shared_ptr<Persoana>& p, const Bilet &bt):
pers(p->clone()),
bilet(bt)
{

}

Factura::Factura(const Factura &other):
pers(other.pers->clone()),
bilet(other.bilet)
{

}


std::ostream &operator<<(std::ostream &os, const Factura &f) {
    os<<"----Factura----\nFactura domnului/doamnei: "<<f.pers->getNume()<<" "<<f.pers->getPrenume()
        <<" pentru achizitionarea urmatorului bilet:\n"<<f.bilet<<'\n';
    return os;
}

Factura &Factura::operator=(const Factura &other) {
    auto copie{other};
    swap(copie,*this);
    return *this;
}

void swap(Factura &f1, Factura &f2) {
    using std::swap;
    swap(f1.pers,f2.pers);
    swap(f1.bilet,f2.bilet);
}
