//
// Created by Vlad on 17.05.2022.
//

#ifndef OOP_FACTURA_H
#define OOP_FACTURA_H

#include "VIP.h"
#include "Angajat.h"
#include "Client.h"

template<typename T>
class Factura;

template<typename T>
std::ostream &operator<<(std::ostream &o, const Factura<T> &c);

template<typename T>
void swap(Factura<T> &f1, Factura<T> &f2);

template<typename T>
class Factura {
    std::shared_ptr<Persoana> pers;
    Bilet bilet;
    T TVA{};
public:
    Factura() = default;

    Factura(const std::shared_ptr<Persoana> &p, const Bilet &bt, T tva);

    Factura(const Factura<T> &other);

    friend std::ostream &operator
    <<<T>(
    std::ostream &os,
    const Factura<T> &f
    );

    friend void swap<>(Factura<T> &f1, Factura<T> &f2);

    Factura &operator=(const Factura<T> &other);
};

#endif //OOP_FACTURA_H
