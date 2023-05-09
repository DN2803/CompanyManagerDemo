#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <string>
Date::Date(/* args */)
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int dd, int mm, int yyyy)
{
    day = dd;
    month = mm;
    year = yyyy;
}

Date::~Date()
{
}
std::istream& operator>> (std::istream& is, Date& src)
{
    char skip;
    is >> src.day;
    is >> skip;
    is >> src.month;
    is >> skip;
    is >> src.year;
    if (is.rdbuf() != std::cin.rdbuf()) is >> skip;
    return is;
}
std::ostream& operator<< (std::ostream& os, const Date& src)
{
    std::string t = std::to_string(src.day) + '/' + std::to_string(src.month) + '/' + std::to_string(src.year);
    os << t.c_str();
    return os;
}
bool Date::checkdate()
{
    //kiem tra ngay co phu hop khong 
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // Convert current date to tm struct
    std::tm* now_tm = std::localtime(&now_c);
    // Convert user-entered date to time_point
    std::tm user_tm = { 0, 0, 0, day, month - 1, year - 1900 };
    std::time_t user_c = std::mktime(&user_tm);
    auto user_tp = std::chrono::system_clock::from_time_t(user_c);
    if (user_tp < now) {
        return false;
    };
    return true;
}
int Date::days_in_month(int month)
{
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return 29;
        }
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}
long Date::days_since_epoch()
{
    long total_days = 0;
    for (int i = 1970; i < year; i++) {
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            total_days += 366;
        }
        else {
            total_days += 365;
        }
    }
    for (int i = 1; i < month; i++) {
        total_days += days_in_month(i);
    }
    total_days += day - 1;
    return total_days;
}
int Date::days_between(Date& other)
{
    int days1 = days_since_epoch();
    int days2 = other.days_since_epoch();
    return abs(days2 - days1);
}
int Date::day_in_week()
{
    long day = days_since_epoch();
    return (day + 5) % 7;
}
void Date::randDate()
{

    // lấy ngày tháng năm hiện tại của hệ thống
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    int current_year = timeinfo->tm_year + 1900;
    int current_month = timeinfo->tm_mon + 1;
    int current_day = timeinfo->tm_mday;

    // tạo ngày ngẫu nhiên trước ngày hiện tại
    day = rand() % current_day + 1;
    month = rand() % current_month + 1;
    year = rand() % current_year;
    if (year < 1980) year = 1980 + rand() % 40;

}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}
