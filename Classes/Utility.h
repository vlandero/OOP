//
// Created by Vlad on 17.05.2022.
//

#ifndef OOP_UTILITY_H
#define OOP_UTILITY_H

#include <string>
#include "Erori.cpp"

class Utility {
public:
    static int verifInt(const std::string &s);

    static void verifCNP(std::string cnp);

    static bool validDate(int year, int month, int day);
};


#endif //OOP_UTILITY_H
