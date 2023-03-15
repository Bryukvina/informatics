#include <iostream>
#include <math.h>

int hash(float value){
    long int s = value / std::abs(value);
    value = std::abs(value);
    long int e;
    long int m;
    int x;
    int hash = 0;
    
    while ((value - std::floor(value)) > 0){
        value = value * 10;
        m += 1;
    };
    e = std::floor(value);

    
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
