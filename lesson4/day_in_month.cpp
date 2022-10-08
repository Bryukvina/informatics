#include <iostream>

enum  class MONTHS {
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

int main(){


    int x;

    std::cout << "Enter the number of the month" << std::endl;
    
    std::cin >> x;
    MONTHS month = static_cast < MONTHS > (x);
    
    switch (month)
    {
        case MONTHS::Jan:;
        case MONTHS::Mar:;
        case MONTHS::May:;
        case MONTHS::Jul:;
        case MONTHS::Aug:;
        case MONTHS::Oct:;
        case MONTHS::Dec: std::cout << "31" << std::endl; break;

        case MONTHS::Feb: std::cout << "28" << std::endl; break;

        case MONTHS::Apr:;
        case MONTHS::Jun:;
        case MONTHS::Sep:;
        case MONTHS::Nov: std::cout << "30" << std::endl; break;

    }
    
    return 0;
};
