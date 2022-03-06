#include <iostream>
#include "Classes/Bilet.h"
int main() {
    Persoana p{"Rosu","Vlad-Andrei",19,"5020712******"};
    std::cout<<p<<"\n";
    Bilet b{230,1,1,p,std::vector<std::string>{"Paris", "Londra", "NY"}};
    std::cout<<b<<'\n';
    b.removeEscala("Paris");
    std::cout<<b<<'\n';

    return 0;
}
