//
// Created by Vlad on 05.05.2022.
//

#ifndef OOP_TIME_H
#define OOP_TIME_H
#include <vector>
#include <ctime>

class Time {
    int day{};
    int month{};
    int year{};
    int hour{};
    int minute{};
    static std::vector<int>monthDays;
public:

    [[maybe_unused]] Time(int day_, int month_, int year_,int hr,int min);
    Time() = default;
    explicit Time(tm t);
    static int getDifInMinutes(const Time& t1, const Time& t2); //numar minutele de pe 1 ian 2020

};


#endif //OOP_TIME_H
