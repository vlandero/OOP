#include "Zbor.h"

#include <utility>
unsigned long long Zbor::id_max = 0;
Zbor::Zbor(std::string plecare_, std::string destinatie_, int dist, std::tm plecare,std::tm sosire):
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
    std::tm tmp{};
    tmp.tm_hour = ora;
    tmp.tm_min = min;
    tmp.tm_year = an - 1900;
    tmp.tm_mon = luna - 1;
    tmp.tm_mday = zi;

    in>>an>>luna>>zi>>ora>>min;
    std::tm tms{};
    tms.tm_hour = ora;
    tms.tm_min = min;
    tms.tm_year = an - 1900;
    tms.tm_mon = luna - 1;
    tms.tm_mday = zi;

    this->id = id_max;
    id_max++;
    this->distanta = dist;
    this->plecare = abvplec;
    this->destinatie = abvsos;
    this->detalii_plecare = tmp;
    this->detalii_sosire = tms;
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

const tm &Zbor::getDetaliiPlecare() const {
    return detalii_plecare;
}

const tm &Zbor::getDetaliiSosire() const {
    return detalii_sosire;
}
