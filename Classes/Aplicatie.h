//
// Created by Vlad on 09.04.2022.
//

#ifndef OOP_APLICATIE_H
#define OOP_APLICATIE_H
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include "Zbor.h"
#include "Angajat.h"
#include "Aeroport.h"


class Aplicatie {
    std::ifstream fin_zbor{"files/zboruri.txt"};
    std::ifstream fin_aeroport{"files/aeroporturi.txt"};
    std::unordered_map<unsigned long long,std::shared_ptr<Persoana>>persoane;
    std::unordered_map<std::string,Aeroport>aeroporturi;
    std::unordered_map<std::string,Bilet>bilete;
    std::unordered_map<std::string,Zbor>zboruri;
    Aplicatie() = default;

    void checkAeroporturi();
    void checkZboruri();
    void checkPersoane();
    void addPersoana();
    void addBilet();

public:
    Aplicatie(const Aplicatie&) = delete;
    Aplicatie& operator=(const Aplicatie&) = delete;
    static Aplicatie& createApp();
    ~Aplicatie();

    void citire_fisiere();
    void run();
};


#endif //OOP_APLICATIE_H
