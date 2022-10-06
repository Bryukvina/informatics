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
        case Jan: std::cout << " 31" << std::endl; break;
        case Feb: std::cout << " 28" << std::endl; break;
        case Mar: std::cout << " 31" << std::endl; break;
        case Apr: std::cout << " 30" << std::endl; break;
        case May: std::cout << " 31" << std::endl; break;
        case Jun: std::cout << " 30" << std::endl; break;
        case Jul: std::cout << " 31" << std::endl; break;
        case Aug: std::cout << " 31" << std::endl; break;
        case Sep: std::cout << " 30" << std::endl; break;
        case Oct: std::cout << " 31" << std::endl; break;
        case Nov: std::cout << " 30" << std::endl; break;
        case Dec: std::cout << " 31" << std::endl; break;
    }
    
    return 0;
};
