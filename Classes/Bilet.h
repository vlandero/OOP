#ifndef OOP_BILET_H
#define OOP_BILET_H
#include <vector>
#include "Zbor.h"
#include "Aeroport.h"
#include "Erori.cpp"
#include <unordered_map>
class Bilet {
    unsigned long long id;
    double pret;
    int bagajeCala;
    int bagajeMana;
    bool masa_inclusa;
    std::vector<Zbor>zboruri;
    int verifInt(const std::string& s);
public:
    static unsigned long long id_max;
    Bilet(double pret_,int bagajeCala_,int bagajeMana_,bool masa_inclusa_,std::vector<Zbor>zboruri_);
    friend std::ostream& operator<<(std::ostream& os,const Bilet& b);
    void citire(std::istream &in, std::ostream &out,std::unordered_map<std::string,Aeroport>aeroporturi);
    explicit Bilet(std::istream &in,std::unordered_map<std::string,Aeroport>aeroporturi);
    ~Bilet();
};


#endif //OOP_BILET_H
