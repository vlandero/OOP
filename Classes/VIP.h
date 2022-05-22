//
// Created by Vlad on 04.05.2022.
//

#ifndef OOP_VIP_H
#define OOP_VIP_H


#include "Persoana.h"
#include <unordered_map>

class VIP : public Persoana {
private:
    int nivel_VIP{};
    int buget_mancare{}; //per zbor, fie in aeroport, fie in avion extra
    int discount_duty_free{};
    double discount_zboruri{};
    int pretVIP{};
    int bagajeCala_incluse{};
    int bagajeMana_incluse{};
public:
    void calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) override;
    void aplicareReducere(Bilet &b, std::ostream &out) override;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is,std::ostream &os) override;
    VIP() = default;
    friend std::ostream& operator<<(std::ostream& os,const VIP& p);
    VIP(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
           const std::vector<Bilet> &b,int nivel, int buget_m,int d_duty_free,double d_zboruri);
    [[maybe_unused]] [[nodiscard]] std::shared_ptr<Persoana> clone() const override;
    ~VIP() override;
};


#endif //OOP_VIP_H
