#include <stdexcept>

class eroare_input : public std::runtime_error {
public:
    explicit eroare_input(const std::string &arg) : runtime_error(arg) {}
};

class eroare_fisier : public eroare_input {
public:
    explicit eroare_fisier(const std::string &arg) : eroare_input(arg) {}
};

class eroare_consola : public eroare_input {
public:
    explicit eroare_consola(const std::string &arg) : eroare_input(arg) {}
};

