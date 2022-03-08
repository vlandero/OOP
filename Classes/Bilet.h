#ifndef OOP_BILET_H
#define OOP_BILET_H
#include <vector>
#include "Zbor.h"

class Bilet {
    std::string id;
    double pret;
    int bagajeCala;
    int bagajeMana;
    bool masa_inclusa;
    std::vector<Zbor>zboruri;
public:
    Bilet(std::string _id,double pret_,int bagajeCala_,int bagajeMana_,bool masa_inclusa_,std::vector<Zbor>zboruri_);
    friend std::ostream& operator<<(std::ostream& os,const Bilet& b);
    ~Bilet();
};


#endif //OOP_BILET_H
