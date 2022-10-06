#include <iostream>
#include <iomanip>

struct Data
{
    unsigned int year: 12;
    unsigned int month: 4;
    unsigned int day: 5;
    unsigned int hours: 5;
    unsigned int minuts: 6;
    unsigned int seconds: 6;
    unsigned int mseconds: 7;
};

void print(Data data)
{
    std::cout << std::setw(2) << data.day << "." << std::setw(2) << data.month << "." << std::setw(4) << data.year << " ";
    std::cout << std::setw(2) << data.hours << ":" << std::setw(2) << data.minuts << ":" << std::setw(2) << data.seconds << ":" << std::setw(2) << data.mseconds << std::endl;
};

int main()
{
    Data data;
    data.day = 28;
    data.month = 7;
    data.year = 2003;
    data.hours = 7;
    data.seconds = 30;
    data.mseconds = 20;

    print(data);
}
