#include "Zbor.h"

#include <utility>
unsigned long long Zbor::id_max = 0;
Zbor::Zbor(std::string plecare_, std::string destinatie_, int dist, tm plecare,tm sosire):
    distanta(dist),
    plecare(std::move(plecare_)),
    destinatie(std::move(destinatie_)),
    detalii_plecare(plecare),
    detalii_sosire(sosire)
{
    id = id_max;
    id_max++;
}

Zbor::~Zbor() = default;

std::ostream &operator<<(std::ostream &os, const Zbor &z) {
    char plecare[100],sosire[100];
    strftime(plecare,100,"%Y-%m-%d, %H:%M",&z.detalii_plecare);
    strftime(sosire,100,"%Y-%m-%d, %H:%M",&z.detalii_sosire);
    os<<z.plecare<<'('<<plecare<<")->"<<z.destinatie<<'('<<sosire<<")\n";
    os<<"Distanta: "<<z.distanta<<" km\n";
    return os;
}

Zbor::Zbor(std::istream &in) {
    //id  max_pasageri  abreviere plecare  abreviere sosire \n data ora plecare \n data ora sosire
    //data ora sunt de format an luna zi ora minut
    int dist;
    in>>dist;
    std::string abvplec,abvsos;
    in>>abvplec>>abvsos;

    int an,luna,zi,ora,min;
    in>>an>>luna>>zi>>ora>>min;
    detalii_plecare.tm_hour = ora;
    detalii_plecare.tm_min = min;
    detalii_plecare.tm_year = an - 1900;
    detalii_plecare.tm_mon = luna - 1;
    detalii_plecare.tm_mday = zi;

    in>>an>>luna>>zi>>ora>>min;
    detalii_sosire.tm_hour = ora;
    detalii_sosire.tm_min = min;
    detalii_sosire.tm_year = an - 1900;
    detalii_sosire.tm_mon = luna - 1;
    detalii_sosire.tm_mday = zi;

    this->id = id_max++;
    this->distanta = dist;
    this->plecare = abvplec;
    this->destinatie = abvsos;
}

const unsigned long long &Zbor::getId() const {
    return id;
}

const std::string &Zbor::getPlecare() const {
    return plecare;
}

const std::string &Zbor::getDestinatie() const {
    return destinatie;
}

double Zbor::getDistanta() const {
    return distanta;
}

tm Zbor::getDetaliiPlecare() const {
    return detalii_plecare;
}

tm Zbor::getDetaliiSosire() const {
    return detalii_sosire;
}
