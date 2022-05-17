//
// Created by Vlad on 05.05.2022.
//

#include "Time.h"
#include <iostream>
std::vector<int> Time::monthDays{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

[[maybe_unused]] Time::Time(int day_, int month_, int year_, int hr, int min):
day(day_),
month(month_),
year(year_),
hour(hr),
minute(min)
{

}

double Time::getDifInDays(const Time& t1, const Time& t2) {
    struct std::tm a{0,t1.minute,t1.hour,t1.day,t1.month,t1.year,0,0,0};
    struct std::tm b{0,t2.minute,t2.hour,t2.day,t2.month,t2.year,0,0,0};
    std::time_t at = std::mktime(&a);
    std::time_t bt = std::mktime(&b);
    double diff = std::difftime(bt,at) / (60*60*24);
    return diff;
}

Time::Time(tm t) {
    day = t.tm_mday;
    month = t.tm_mon;
    year = t.tm_year;
    hour = t.tm_hour;
    minute = t.tm_min;
}
