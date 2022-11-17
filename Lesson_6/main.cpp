#include <iostream>
#include <cmath>
#include "frac.cpp"

int main(){
    Fraction f1, f2;
    double c = 2.5;
    int k = 3;
    std::cin >> f1;
    f2 = Fraction(c);
    std::cout << f2;
    std::cout << f1 * f2 << std::endl;
    std::cout << k + f2 << std::endl;
    std::cout << f1 + f2 << std::endl;
    std::cout << f1 - f2 << std::endl;
    std::cout << f1 / f2 << std::endl;

    f1 += 2;
    std::cout << f1 << std::endl;
    f2 -= f1;
    std::cout << f2 << std::endl;
    std::cout << "f1 == f2?" << (f1 == f2) << std::endl;
};
