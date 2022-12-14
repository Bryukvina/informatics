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


        void operator += (Fraction f);
        void operator -= (Fraction f);
        void operator *= (Fraction f);
        void operator /= (Fraction f);
    
        friend std::ostream& operator<<(std::ostream &out, const Fraction& i);
        friend std::istream& operator>>(std::istream &in, const Fraction& i);
};
