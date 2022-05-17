//
// Created by Vlad on 17.05.2022.
//

#include "Utility.h"
int Utility::verifInt(const std::string& s) {
    int num = 0;
    for(auto &n : s){
        if(!std::isdigit(n)){
            throw eroare_consola{"Introduceti numar"};
        }
        num = num * 10 + int(n - '0');
    }
    return num;
}

void Utility::verifCNP(std::string cnp) {
    if(cnp.size() != 13)
        throw eroare_consola{"CNP invalid"};
    for(auto &n : cnp){
        if(!std::isdigit(n)){
            throw eroare_consola{"CNP invalid"};
        }
    }
    std::string p;
    int day,month,year;
    p.push_back(cnp[1]);
    p.push_back(cnp[2]);
    year = std::stoi(p);
    p.clear();
    p.push_back(cnp[3]);
    p.push_back(cnp[4]);
    month = std::stoi(p);
    p.clear();
    p.push_back(cnp[5]);
    p.push_back(cnp[6]);
    day = std::stoi(p);
    p.clear();

    if(!validDate(year,month,day))
        throw eroare_consola{"CNP invalid"};
}

bool Utility::validDate(int year, int month, int day) {
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if ((year % 4 == 0) && (year % 100 != 0))
            return (day <= 29);
        else
            return (day <= 28);
    }
    if (month == 4 || month == 6 ||
        month == 9 || month == 11)
        return (day <= 30);
    return true;
}