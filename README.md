# OOP College Project

This is a complex project I created for the OOP course.
The project presents a system which helps users buy fictional tickets for fictional flights all around the world (stored in a file, in a specific format). They can also check the tickets bought by a specific user as well as available flights from an airport to another.
I used all of the 4 OOP principles (inheritance, abstraction, polymorphism, encapsulation) and also some design patterns (builder and singleton). The project is involved in a Continuous Integration system, created by an analyst, to compile and check our code on different machines. I've also made some tests for the CI system to run over 80% of the code to check for memory errors.

Below are the requirements for the project, in Romanian, for the analyst that checked the project.

# OOP Template

### Tema 0

- [ ] Nume proiect (îl puteți schimba ulterior)
- [ ] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [ ] definirea a minim 3-4 clase folosind compunere
- [ ] constructori de inițializare
- [ ] pentru o clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [ ] `operator<<` pentru toate clasele
- [ ] cât mai multe `const`
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese
- [ ] scenariu de utilizare a claselor definite (crearea de obiecte și apelarea funcțiilor membru publice în main)
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri
  - [ ] funcții virtuale (pure), constructori virtuali (clone)
  - [ ] apelarea constructorului din clasa de bază 
  - [ ] smart pointers
  - [ ] `dynamic_cast`
- [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [ ] excepții
  - [ ] ierarhie proprie (cu baza `std::exception` sau derivată din `std::exception`)
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] o clasă șablon cu sens; minim 2 instanțieri
- [ ] o specializare pe funcție/clasă șablon
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit
