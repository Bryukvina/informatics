#include <iostream>
#include <cmath>

class Fraction{
    public:
        int num; 
        int den;
        Fraction();
        Fraction(int n, int d){num = n; den = d;};
        Fraction(int n){num = n; den = 1;};
        ~Fraction() = default;

    void Reduction();

    friend Fraction operator+ (Fraction f1, Fraction f2);
    friend Fraction operator+ (int f1, Fraction f2);

    void operator++ ();
    void operator++ (int f1);

    friend Fraction operator- (Fraction f1, Fraction f2);
    friend Fraction operator- (int f1, Fraction f2);

    void operator-- ();
    void operator-- (int f1);

    void operator- ();

    friend Fraction operator* (Fraction f1, Fraction f2);
    friend Fraction operator* (int f1, Fraction f2);

    friend Fraction operator/ (Fraction f1, Fraction f2);
    friend Fraction operator/ (int f1, Fraction f2);

    friend bool operator == (Fraction f1, Fraction f2);
    friend bool operator != (Fraction f1, Fraction f2);
    friend bool operator > (Fraction f1, Fraction f2);
    friend bool operator < (Fraction f1, Fraction f2);
    friend bool operator >= (Fraction f1, Fraction f2);
    friend bool operator <= (Fraction f1, Fraction f2);


    Fraction& operator += (Fraction f);
    Fraction& operator -= (Fraction f);
    Fraction& operator *= (Fraction f);
    Fraction& operator /= (Fraction f);
};

std::ostream& operator<<(std::ostream &out, Fraction& i);
std::istream& operator>>(std::istream &in, Fraction& i);
