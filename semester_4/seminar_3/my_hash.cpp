#include <iostream>
#include <math.h>

int hash(float value){
    long int s = value / std::abs(value);
    long int e = std::ceil(std::log10(value));
    long int m = value * std::pow(10, e)
    int x;
    int hash = 0;

    while (m > 0){
        x = m % 10;
        m = m / 10;
        hash = (hash * 5 + x) % 1321;
    };
    while (e > 0){
        x = e % 10;
        e = e / 10;
        hash = (hash * 5 + x) % 1321;
    }
    return hash * s;
};
