#include <iostream>

enum  MONTHS {
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
        case Jan: std::cout << "January" << " 31" << std::endl; break;
        case Feb: std::cout << "February" << " 28" << std::endl; break;
        case Mar: std::cout << "March" << " 31" << std::endl; break;
        case Apr: std::cout << "April" << " 30" << std::endl; break;
        case May: std::cout << "May" << " 31" << std::endl; break;
        case Jun: std::cout << "June" << " 30" << std::endl; break;
        case Jul: std::cout << "July" << " 31" << std::endl; break;
        case Aug: std::cout << "August" << " 31" << std::endl; break;
        case Sep: std::cout << "September" << " 30" << std::endl; break;
        case Oct: std::cout << "October" << " 31" << std::endl; break;
        case Nov: std::cout << "November" << " 30" << std::endl; break;
        case Dec: std::cout << "December" << " 31" << std::endl; break;
    }
    
    return 0;
};
