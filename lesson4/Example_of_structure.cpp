#include <iostream>
#include <iomanip>


struct Day{
    int day;     // day of the month
    int month;      // number of the month
    int year;       // number of the year

    public:
        Day(int, int, int);
        Day();
        ~Day();
        
        tomorrow
}




void print_day(Day data)
{   
    std::string array = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satuday", "Sunday"};
    std::cout << std::setw(2) << data.day << "." << std::setw(2) << data.month << "." << std::setw(4) << data.year << std::endl;
}

