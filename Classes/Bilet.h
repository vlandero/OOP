#ifndef OOP_BILET_H
#define OOP_BILET_H
#include <vector>
#include "Zbor.h"
#include "Aeroport.h"
#include "Utility.h"
#include <unordered_map>

class Bilet {
    unsigned long long id{};
    double pret{};
    int bagajeCala{};
    int bagajeMana{};
    static double pretBagajMana_km;
    static double pretBagajCala_km;
    static double pretBilet_km;
    std::vector<Zbor>zboruri;
    static unsigned long long id_max;
public:
    Bilet() = default;
    Bilet(double pret_,int bagajeCala_,int bagajeMana_,std::vector<Zbor>zboruri_);
    friend std::ostream& operator<<(std::ostream& os,const Bilet& b);
    void citire(std::istream &in, std::ostream &out,std::unordered_map<std::string,Aeroport>aeroporturi);
    Bilet(std::istream &in,std::unordered_map<std::string,Aeroport>aeroporturi);

    [[nodiscard]] unsigned long long int getId() const;
    static double getPretBagajManaKm();

    static double getPretBagajCalaKm();

    static double getPretBiletKm();

    [[nodiscard]] const std::vector<Zbor> &getZboruri() const;

    void setPret(double pret);

    void setBagajeCala(int bagajeCala);

    void setBagajeMana(int bagajeMana);

    [[nodiscard]] double getPret() const;

    int getBagajeCala() const;

    int getBagajeMana() const;

    ~Bilet();
};


#endif //OOP_BILET_H
