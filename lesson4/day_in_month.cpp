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
        case MONTHS::Jan: std::cout << "31" << std::endl; break;
        case MONTHS::Feb: std::cout << "28" << std::endl; break;
        case MONTHS::Mar: std::cout << "31" << std::endl; break;
        case MONTHS::Apr: std::cout << "30" << std::endl; break;
        case MONTHS::May: std::cout << "31" << std::endl; break;
        case MONTHS::Jun: std::cout << "30" << std::endl; break;
        case MONTHS::Jul: std::cout << "31" << std::endl; break;
        case MONTHS::Aug: std::cout << "31" << std::endl; break;
        case MONTHS::Sep: std::cout << "30" << std::endl; break;
        case MONTHS::Oct: std::cout << "31" << std::endl; break;
        case MONTHS::Nov: std::cout << "30" << std::endl; break;
        case MONTHS::Dec: std::cout << "31" << std::endl; break;
    }
    
    return 0;
};
