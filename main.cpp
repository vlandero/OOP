#include "Classes/Aplicatie.h"
int main() {

    Aplicatie& app = Aplicatie::createApp();

    app.run();

    return 0;
}
