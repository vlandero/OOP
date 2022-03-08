//
// Created by Vlad on 08.03.2022.
//

#include "Zbor.h"

#include <utility>

Zbor::Zbor(std::string plecare_, std::string destinatie_, int plecare_h, int plecare_min, int sosire_h,int sosire_min):
    plecare(std::move(plecare_)),
    destinatie(std::move(destinatie_))
{
    this->oraPlecare.h = plecare_h;
    this->oraPlecare.min = plecare_min;
    this->oraSosire.h = sosire_h;
    this->oraSosire.min = sosire_min;
    this->id = 1;
}

Zbor::~Zbor() {

}

std::ostream &operator<<(std::ostream &os, const Zbor &z) {
    os<<z.plecare<<'('<<((z.oraPlecare.h<10)?"0":"")<<z.oraPlecare.h<<':'<<((z.oraPlecare.min<10)?"0":"")
    <<z.oraPlecare.min<<')'<<"->"<<z.destinatie<<'('<<((z.oraSosire.h<10)?"0":"")<<z.oraSosire.h<<':'
    <<((z.oraSosire.min<10)?"0":"")<<z.oraSosire.min<<')';
    return os;
}
