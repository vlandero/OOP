#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H
#include "Bilet.h"

class Persoana {
    int id;
    std::string nume;
    std::string prenume;
    int varsta;
    std::string CNP;
    std::vector<Bilet>bilete;
public:
    Persoana(std::string nume_,std::string prenume_,int varsta, std::string CNP_,std::vector<Bilet>b);
    friend std::ostream& operator<<(std::ostream& os,const Persoana& p);
    Persoana& operator=(const Persoana& other);
    Persoana(const Persoana &other);
    ~Persoana();
};


#endif //OOP_PERSOANA_H
