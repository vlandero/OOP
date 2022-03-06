//
// Created by Vlad on 02.03.2022.
//

#ifndef OOP_BILET_H
#define OOP_BILET_H
#include <vector>
#include <iostream>
#include <cstdarg>
#include "Persoana.h"

class Bilet {
    Persoana& posesor;
    int id;
    double pret;
    int nr_bagaje_incluse;
    bool masa_inclusa;
    std::vector<std::string>escale;
public:
    //getters
    int getId();
    double getPret();
    Persoana getPosesor();
    int getBagaje();
    bool getMasa();
    std::vector<std::string> getEscale();
    //setters
    void setPosesor(Persoana& posesor_);
    void setPret(double pret_);
    void setBagaje(int bagaje);
    void setMasa(bool masa);
    void addEscala(std::string esc);
    void removeEscala(std::string esc);
    Bilet(double pret_,int bagaje,bool masa_inclusa_,Persoana& p,std::vector<std::string>escale_);
    friend std::ostream& operator<<(std::ostream& os,const Bilet& b);
    ~Bilet();
};


#endif //OOP_BILET_H
