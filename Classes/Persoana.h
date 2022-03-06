//
// Created by Vlad on 02.03.2022.
//

#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H
#include <iostream>
#include <string>
#include <vector>

class Persoana {
    std::string nume;
    std::string prenume;
    int varsta;
    std::string CNP;
public:
    Persoana(std::string nume_,std::string prenume_,int varsta, std::string CNP_);
    friend std::ostream& operator<<(std::ostream& os,const Persoana& p);
    Persoana& operator=(const Persoana& other);
    Persoana(const Persoana &other);
    ~Persoana();
};


#endif //OOP_PERSOANA_H
