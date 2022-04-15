#include "Aplicatie.h"

void Aplicatie::citire_fisiere() {
    int n,i;
    //citire aeroporturi
    fin_aeroport>>n;
    fin_aeroport.get();
    for(i = 0; i < n; ++i){
        Aeroport a{fin_aeroport};
        this->aeroporturi[a.getAbreviere()] = a;
    }
    //citire zboruri
    fin_zbor>>n;
    for(i = 0; i < n; ++i){
        Zbor z{fin_zbor};
        this->zboruri[z.getId()] = z;
        this->aeroporturi[this->zboruri[z.getId()].getPlecare()].addPlecare(z);
        this->aeroporturi[this->zboruri[z.getId()].getDestinatie()].addSosire(z);
    }
    std::cout<<"Files loaded\n";
}

void Aplicatie::run() {
    this->citire_fisiere();
    bool running = true;
    int input;
    while(running){
        std::cout<<"\nAlege numarul actiunii pe care vrei sa il faci\n"
        <<"1 - Vezi aeroporturi inregistrate\n"
        <<"2 - Vezi zboruri inregistrate\n"
        <<"3 - Vezi persoane inregistrate\n"
        <<"4 - Adauga persoana\n"
        <<"5 - Adauga bilet pentru o persoana\n"
        <<"6 - Iesi din aplicatie\n";
        std::cin>>input;
        switch (input) {
            case 1:
                checkAeroporturi();
                break;
            case 2:
                checkZboruri();
                break;
            case 3:
                checkPersoane();
                break;
            case 4:
                addPersoana();
                break;
            case 5:
                addBilet();
                break;
            case 6:
                running = false;
                break;
        }
    }
}

Aplicatie::~Aplicatie() {
//    std::cout<<"Destructor app apelat\n";
}

Aplicatie &Aplicatie::createApp() {
    static Aplicatie app;
    return app;
}

void Aplicatie::checkAeroporturi() {
    for(auto &a : aeroporturi){
        std::cout<<a.second;
    }
}

void Aplicatie::checkZboruri() {
    for(auto &zbor : zboruri){
        std::cout<<zbor.second;
    }
}

void Aplicatie::checkPersoane() {
    for(auto &pers : persoane){
        std::cout<<*pers.second;
        std::cout<<'\n';
    }
}

void Aplicatie::addPersoana() {
    try{
        auto p = Persoana::create(std::cin);
        std::cout<<*p;
        persoane[p->getId()] = p;
    }
    catch (eroare_consola& err){
        std::cout<<err.what()<<'\n';
    }
}

void Aplicatie::addBilet() {

}

