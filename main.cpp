#include <iostream>
#include <string>
#include <ctime>
#include "Classes/Persoana.h"
#include "Classes/Aplicatie.h"
int main() {

    Aplicatie& app = Aplicatie::createApp();

    app.run();

    return 0;
}
