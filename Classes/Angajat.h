//
// Created by Vlad on 08.04.2022.
//

#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H
#include "Persoana.h"

class Angajat : public Persoana {
    int salariu{};
    static double reducere;
    std::string post;
    std::string aeroport;
public:
    void calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) override;
    void aplicareReducere(Bilet &b, std::ostream &out) override;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is,std::ostream &os) override;
    Angajat() = default;
    friend std::ostream& operator<<(std::ostream& os,const Angajat& p);
    Angajat(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
            const std::vector<Bilet> &b, int salariu,std::string post_,std::string aeroport);
    [[maybe_unused]] [[nodiscard]] std::shared_ptr<Persoana> clone() const override;
    ~Angajat() override;
};


#endif //OOP_ANGAJAT_H
