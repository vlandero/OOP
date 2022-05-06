//
// Created by Vlad on 05.05.2022.
//

#include "Time.h"
std::vector<int> Time::monthDays{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

[[maybe_unused]] Time::Time(int day_, int month_, int year_, int hr, int min):
day(day_),
month(month_),
year(year_),
hour(hr),
minute(min)
{

}

int Time::getDifInMinutes(const Time& t1, const Time& t2) {

    int days1 = 366,days2 = 366; // zile de la 1 ianuarie 2020 incoace
    days1 += t1.day + (t1.year - 2021) * 365;
    days2 += t2.day + (t2.year - 2021) * 365;
    for(int i = 1; i < t1.month; ++i){
        days1 += monthDays[i];
    }
    for(int i = 1; i < t2.month; ++i){
        days2 += monthDays[i];
    }
    int minutes1 = days1 * 1440 + t1.hour * 60 + t1.minute;
    int minutes2 = days2 * 1440 + t2.hour * 60 + t2.minute;

    return minutes2 - minutes1;
}

Time::Time(tm t) {
    day = t.tm_mday;
    month = t.tm_mon;
    year = t.tm_year;
    hour = t.tm_hour;
    minute = t.tm_min;
}
