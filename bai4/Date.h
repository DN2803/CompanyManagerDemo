#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <assert.h>
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(/* args */);
    Date(int dd, int mm, int yyyy);
    ~Date();
    friend std::istream& operator>> (std::istream& is, Date& src);
    friend std::ostream& operator<< (std::ostream& os, const Date& src);
    bool checkdate();
    int days_in_month(int month);
    long days_since_epoch();
    int days_between(Date& other);
    int day_in_week();
    void randDate();
    //gettor
    int getMonth();
    int getYear();
};

#endif