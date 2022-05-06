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
    static int verifInt(const std::string& s);
    static void verifCNP(std::string cnp);
    static bool validDate(int year, int month, int day);
    Persoana() = default;
    static unsigned long long id_max;
    std::string tip;
public:

    virtual void calculeazaPret(Bilet& b,std::istream &in, std::ostream &out) = 0;
    [[nodiscard]] const std::string &getTip() const;

    Persoana(std::string nume_,std::string prenume_,int varsta, std::string CNP_,std::vector<Bilet>b,std::string tip_);
    Persoana(const Persoana &other);

    virtual void citire(std::istream &is,std::ostream &out);
    virtual void afisare(std::ostream &os) const;
    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<Persoana> clone() const = 0;
    static std::shared_ptr<Persoana> create(std::istream &is);

    friend std::ostream& operator<<(std::ostream& os,const Persoana& p);
    Persoana& operator=(const Persoana& other);

    virtual ~Persoana();

    [[nodiscard]] unsigned long long int getId() const;

    void addBilet(Bilet& b);
};


#endif //OOP_PERSOANA_H
