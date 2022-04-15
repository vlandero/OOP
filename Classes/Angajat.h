//
// Created by Vlad on 08.04.2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H
#include "Persoana.h"

class Angajat : public Persoana {
    int salariu{};
    std::string post;
public:
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is,std::ostream &os) override;
    Angajat() = default;
    friend std::ostream& operator<<(std::ostream& os,const Angajat& p);
    Angajat(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
            const std::vector<Bilet> &b, int salariu,std::string post_);
    [[nodiscard]] std::shared_ptr<Persoana> clone() const override;
    ~Angajat() override;
};


#endif //OOP_ANGAJAT_H
