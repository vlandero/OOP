#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H

#include <memory>
#include "Bilet.h"

class Persoana {

protected:
    unsigned long long id{};
    std::string nume;
    std::string prenume;
    int varsta{};
    std::string CNP;
    std::vector<Bilet>bilete;
    Persoana() = default;
    static void provCalculeazaPret(Bilet &b,int discount_zboruri,int bagajeCala_incluse,int bagajeMana_incluse, std::istream &in, std::ostream &out);
    static unsigned long long id_max;

public:

    virtual void calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) = 0;

    Persoana(std::string nume_,std::string prenume_,int varsta, std::string CNP_,std::vector<Bilet>b);
    Persoana(const Persoana &other);

    virtual void citire(std::istream &is,std::ostream &out);
    virtual void afisare(std::ostream &os) const;
    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<Persoana> clone() const = 0;
    static std::shared_ptr<Persoana> create(std::istream &is);

    friend std::ostream& operator<<(std::ostream& os,const Persoana& p);
    Persoana& operator=(const Persoana& other);

    [[nodiscard]] const std::string &getNume() const;

    [[nodiscard]] const std::string &getPrenume() const;

    virtual ~Persoana();

    [[nodiscard]] unsigned long long int getId() const;

    void addBilet(Bilet& b);
};


#endif //OOP_PERSOANA_H
