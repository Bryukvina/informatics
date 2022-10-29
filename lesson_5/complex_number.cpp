#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#define N 100000 //number precision

class Complex_n{
    public:
        double r;
        double phi;
        Complex_n() = default;
        Complex_n(double R, double f, int view = 1){
            if (view = 1){r = R; phi = f;} //trigon. form
            else if (view = 2){r = std::pow(R * R + f * f, 0.5); phi = std::atan(f / R);} // algebr. form
            else {r = R; phi = f;}; // exp form
        };
        ~Complex_n() = default;

        Complex_n conj(){
            Complex_n num;
            return Complex_n(r, -phi);
        };

        friend Complex_n operator + (Complex_n c1, Complex_n c2){
            Complex_n res;
            double x, y;
            x = c1.r * std::cos(c1.phi) + c2.r * std::cos(c2.phi);
            y = c1.r * std::sin(c1.phi) + c2.r * std::sin(c2.phi);
            res.r = std::pow(c1.r * c1.r + c2.r * c2.r + 2 * c1.r * c2.r * std::cos(std::abs(c1.phi - c2.phi)), 0.5);
            res.phi = std::atan(y / x);
            return res;
        };
        friend Complex_n operator - (Complex_n c1, Complex_n c2){
            Complex_n res;
            double x, y;
            x = c1.r * std::cos(c1.phi) - c2.r * std::cos(c2.phi);
            y = c1.r * std::sin(c1.phi) - c2.r * std::sin(c2.phi);
            res.r = std::pow(c1.r * c1.r + c2.r * c2.r - 2 * c1.r * c2.r * std::cos(std::abs(c1.phi + c2.phi)), 0.5);
            res.phi = std::atan(y / x);
            return res;
        };
        friend Complex_n operator * (Complex_n c1, Complex_n c2){
            Complex_n res;
            res.r = c1.r * c2.r;
            res.phi = c1.phi + c2.phi;
            return res;
        };
        friend Complex_n operator / (Complex_n c1, Complex_n c2){
            Complex_n res;

            res.r = c1.r / c2.r;
            res.phi = c1.phi - c2.phi;
            return res;
        };

        Complex_n sqrt(double n){
            Complex_n res;
            res.r = std::pow(r, 1 / n);
            res.phi = phi / n;
            return res;
        };

        Complex_n pow(double n){
            Complex_n res;
            res.r = std::pow(r, n);
            res.phi = phi * n;
            return res;
        };
    void print(){
        std::cout << std::round(r * std::cos(phi) * N) / N << " + " << std::round(r * std::sin(phi) * N) / N << "i" << std::endl; 
    };
};

int main(){
    Complex_n c1;
    Complex_n c2 = {4, 0, 1};
    Complex_n c3;
    
    c1.r = 1;
    c1.phi = M_PI /  2;


    (c1 + c2).print();
    (c1 - c2).print();
    (c1 * c2).print();
    (c1 / c2).print();
    c3 = c1.pow(2);
    c3.print();
    c3 = c2.sqrt(2);
    c3.print();
    return 0;
};
