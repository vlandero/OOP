//
// Created by Vlad on 04.05.2022.
//

#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include "Persoana.h"

class Client : public Persoana {
public:
    void calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) override;
    void aplicareReducere(Bilet &b, std::ostream &out) override;
    void afisare(std::ostream &os) const override;
    void citire(std::istream &is,std::ostream &os) override;
    Client() = default;
    friend std::ostream& operator<<(std::ostream& os,const Client& p);
    Client(const std::string &nume, const std::string &prenume, int varsta, const std::string &cnp,
            const std::vector<Bilet> &b);
    [[maybe_unused]] [[nodiscard]] std::shared_ptr<Persoana> clone() const override;
    ~Client() override;
};



#endif //OOP_CLIENT_H
