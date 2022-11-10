#include <iostream>
#include <cmath>
#include "frac.hpp"

int NOD(int x, int y)
{   if (y == 0) return x;
    return NOD(y, x % y);
};


void Fraction::Reduction(){
    int nod;
    nod = NOD(num, den);
    num /= nod;
    den /= nod;
};

Fraction operator + (Fraction f1, Fraction f2){
    Fraction res;
    int d, n;
    n = f1.num * f2.den + f2.num * f1.den;
    d = f2.den * f1.den;
    res.num = n;
    res.den = d;
    res.Reduction();
    return res;
};

Fraction operator + (int f1, Fraction f2){
    int n, d;
    Fraction res;
    n = f1 * f2.den + f2.num;
    d = f2.den;
    res.num = n;
    res.den = d;
    res.Reduction();
    return res;
};


void Fraction::operator ++ (){
    int nod;
    num += den;
    nod = NOD(num, den);
    num = num / nod;
    den = den / nod;
};

void Fraction::operator ++ (int f1){
    int nod;
    num += den;
    nod = NOD(num, den);
    num = num / nod;
    den = den / nod;
};

Fraction operator - (Fraction f1, Fraction f2){
    Fraction res;
    int d, n;
    n = f1.num * f2.den - f2.num * f1.den;
    d = f2.den * f1.den;
    res.num = n;
    res.den = d;
    res.Reduction();
    return res;
};
Fraction operator - (int f1, Fraction f2){
    int n, d;
    Fraction res;
    n = f1 * f2.den - f2.num;
    d = f2.den;
    res.num = n;
    res.den = d;
    res.Reduction();
    return res;
};

void Fraction::operator --(){
    num += den;
    Reduction();
};


void Fraction::operator --(int f1){
    num += den;
    Reduction();
};

void Fraction::operator -(){
    num = -num;
};

Fraction operator* (Fraction f1, Fraction f2){
    Fraction res;
    res.num = f1.num * f2.num;
    res.den = f1.den * f2.den;
    res.Reduction();
    return res;
};

Fraction operator* (int f1, Fraction f2){
    Fraction res;
    res.num *= f1;
    res.Reduction();
    return res;
};


Fraction operator/ (Fraction f1, Fraction f2){
    Fraction res;
    res.num = f1.num * f2.den;
    res.den = f1.den * f2.num;
    res.Reduction();
    return res;
};

Fraction operator/ (int f1, Fraction f2){
    Fraction res;
    res.num = f1 * f2.den;
    res.den = f2.num;
    res.Reduction();
    return res;
};


bool operator == (Fraction f1, Fraction f2){
    return f1.num == f2.num and f1.den == f2.den;
};
bool operator != (Fraction f1, Fraction f2){
    return f1.num != f2.num or f1.den != f2.den;
};
bool operator > (Fraction f1, Fraction f2){
    return f1.num * f2.den > f1.den * f2.num;
};
bool operator < (Fraction f1, Fraction f2){
    return f1.num * f2.den < f1.den * f2.num;
};
bool operator >= (Fraction f1, Fraction f2){
    return f1.num * f2.den >= f1.den * f2.num;
};
bool operator <= (Fraction f1, Fraction f2){
    return f1.num * f2.den <= f1.den * f2.num;
};


void Fraction::operator += (Fraction f){
    num = num * f.den + den * f.num;
    den = den * f.den;
    Reduction();
};
void Fraction::operator -= (Fraction f){
    num = num * f.den - den * f.num;
    den = den * f.den;
    Reduction();
};
void Fraction::operator *= (Fraction f){
    num *= f.num;
    den *= f.den;
    Reduction();
};
void Fraction::operator /= (Fraction f){
    num *= f.den;
    den *= f.num;
    Reduction();
};

std::istream &operator>> (std::istream &input, Fraction &f)
{
  int n, d;
  char slash;
  input >> n;
  input >> slash;
  input >> d;

  f = Fraction(n, d);
  return input;
};

std::ostream &operator << (std::ostream &output, const Fraction& frac)
{
  return output << frac.num << "/" << frac.den;
};
