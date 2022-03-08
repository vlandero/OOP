#include <iostream>
#include "citire_fisiere.cpp"


int main() {

    Zbor z1{"Paris","Roma",16,35,18,20};
    Zbor z2{"Roma","Washington",20,05,23,25};
    Bilet b{"a1",1500,1,1,1,std::vector{z1,z2}};
    Persoana p{"Rosu","Vlad-Andrei",19,"5020712******",std::vector{b}};

    std::cout<<p;
    return 0;
}
