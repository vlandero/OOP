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
        if(aeroporturi.find(this->zboruri[z.getId()].getPlecare()) == aeroporturi.end())
            throw eroare_fisier("Aeroport inexistent");
        if(aeroporturi.find(this->zboruri[z.getId()].getDestinatie()) == aeroporturi.end())
            throw eroare_fisier("Aeroport inexistent");
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
        <<"6 - Fa o rezervare pentru un restaurant din aeroport\n"
        <<"7 - Iesi din aplicatie\n";
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
                rezerva();
                break;
            case 7:
                running = false;
                break;

            default:
                std::cout<<"Nu ai introdus ce trebuie\n";
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
    printMap<Aeroport,std::string>(aeroporturi);
}

void Aplicatie::checkZboruri() {
    printMap<Zbor,unsigned long long>(zboruri);
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
        persoane[p->getId()] = p->clone();
    }
    catch (eroare_consola& err){
        std::cout<<err.what()<<'\n';
    }
}

void Aplicatie::addBilet() {
    try{
        std::cout<<"Introduceti ID-ul persoanei pentru care vreti sa creati un bilet\n";
        int ID;
        std::string idd;
        std::cin>>idd;
        ID = Utility::verifInt(idd);
        if(persoane.find(ID) == persoane.end()){
            std::cout<<"Persoana inexistenta\n";
            return;
        }
        auto p = persoane[ID];
        auto b = Bilet();
        b.citire(std::cin,std::cout,aeroporturi);
        if(b.getZboruri().empty()){
            std::cout<<"Nu exista zboruri\n";
            return;
        }
        p->calculeazaPret(b,std::cin,std::cout);
        p->addBilet(b);
        bilete[b.getId()] = b;
        Factura<int> f{p,b,19};
        facturi[b.getId()] = f; //fiecare factura corespunde unui bilet, astfel fac conexiunea prin id
        std::cout<<f;

    }
    catch (eroare_consola& err){
        std::cout<<err.what()<<'\n';
    }
}

void Aplicatie::rezerva() {
    std::string aeroport,restaurant;
    std::cout<<"Introduceti ID-ul persoanei pe numele careia faceti rezervarea\n";
    unsigned long long id;
    std::cin>>id;
    std::cin.get();
    if(persoane.find(id) == persoane.end())
    {
        std::cout<<"ID inexistent\n";
        return;
    }
    std::cout<<"Introduceti numarul de persoane pentru care se face rezervarea\n";
    int nr;
    std::cin>>nr;
    std::cin.get();
    std::cout<<"Introduceti aeroportul pentru care se face rezervarea\n";
    std::getline(std::cin,aeroport);
    std::cout<<"Introduceti restaurantul pentru care se face rezervarea\n";
    std::getline(std::cin,restaurant); //daca ma gandeam de dinainte, faceam frumos un vector de restaurante in aeroport, dar acum nu mai am timp :))
    builder_rezervare b;
    Rezervare r = b.pers(persoane[id]->getNume()).nr_persoane(nr).reducere(persoane[id]->reducereRestaurant()).
            buget(persoane[id]->bugetMancare()).aeroport(aeroport).restaurant(restaurant).build();
    rezervari[r.getId()] = r;
    std::cout<<r;

}

