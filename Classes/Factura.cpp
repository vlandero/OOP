//
// Created by Vlad on 17.05.2022.
//

#include "Factura.h"

template<typename T>
Factura<T>::Factura(const std::shared_ptr<Persoana>& p, const Bilet &bt,const T tva):
pers(p->clone()),
bilet(bt),
TVA(tva)
{

}

template<typename T>
Factura<T>::Factura(const Factura<T> &other):
pers(other.pers->clone()),
bilet(other.bilet),
TVA(other.TVA)
{

}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Factura<T> &f) {
    os<<"----Factura----\nFactura domnului/doamnei: "<<f.pers->getNume()<<" "<<f.pers->getPrenume()
        <<" pentru achizitionarea urmatorului bilet:\n"<<f.bilet<<'\n'<<"TVA: "<<f.TVA<<"% ";
    return os;
}
template<typename T>
Factura<T> &Factura<T>::operator=(const Factura<T> &other) {
    auto copie{other};
    swap(copie,*this);
    return *this;
}
template<typename T>
void swap(Factura<T> &f1, Factura<T> &f2) {
    using std::swap;
    swap(f1.pers, f2.pers);
    swap(f1.bilet, f2.bilet);
}

template
class Factura<int>;

template
std::ostream &operator<<<>(std::ostream &o, const Factura<int> &x);

template
class Factura<double>;

template
std::ostream &operator<<<>(std::ostream &o, const Factura<double> &x);
