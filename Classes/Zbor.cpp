#include "Zbor.h"

#include <utility>

Zbor::Zbor(std::string plecare_, std::string destinatie_, int max_pas, std::tm plecare,std::tm sosire,std::string ID):
    id(std::move(ID)),
    max_pasageri(max_pas),
    plecare(std::move(plecare_)),
    destinatie(std::move(destinatie_)),
    detalii_plecare(plecare),
    detalii_sosire(sosire)
{
//    nr_zboruri++;
}

Zbor::~Zbor() = default;

std::ostream &operator<<(std::ostream &os, const Zbor &z) {
    char plecare[100],sosire[100];
    strftime(plecare,100,"%Y-%m-%d, %H:%M",&z.detalii_plecare);
    strftime(sosire,100,"%Y-%m-%d, %H:%M",&z.detalii_sosire);
    os<<z.plecare<<'('<<plecare<<")->"<<z.destinatie<<'('<<sosire<<")\n";
    os<<"Maxim locuri: "<<z.max_pasageri<<'\n';
    return os;
}

Zbor::Zbor(std::istream &in) {
    //id  max_pasageri  abreviere plecare  abreviere sosire \n data ora plecare \n data ora sosire
    //data ora sunt de format an luna zi ora minut
    std::string ID;
    int maxpas;
    in>>ID>>maxpas;
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

    this->id = ID;
    this->max_pasageri = maxpas;
    this->plecare = abvplec;
    this->destinatie = abvsos;
    this->detalii_plecare = tmp;
    this->detalii_sosire = tms;
}

const std::string &Zbor::getId() const {
    return id;
}

const std::string &Zbor::getPlecare() const {
    return plecare;
}

const std::string &Zbor::getDestinatie() const {
    return destinatie;
}
