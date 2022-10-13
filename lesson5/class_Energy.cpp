#include <iostream>
#include <iomanip>

class Energy{
    public:
        double value; // значение храниться в СИ

        Energy();
        Energy(double val){value = val;};
        ~Energy() = default;

        void print_SI();
        void print_GSSE();
        double Get_value_SI();
        double Get_value_GSSE();
        void Write_SI(double val);
        void Write_GSSE(double val);

        friend Energy operator + (Energy e1, Energy e2);
        friend Energy operator - (Energy e1, Energy e2);

    private:
        static const double SI_GSSE = 6.242e+18;
};

void Energy::print_SI(){std::cout << value << " Кл" << std::endl;};

void Energy::print_GSSE(){std::cout << value * SI_GSSE << " эВ" << std::endl;};

double Energy::Get_value_GSSE(){return value * SI_GSSE;};

double Energy::Get_value_SI(){return value;}

void Energy::Write_SI(double val){value = val;};

void Energy::Write_GSSE(double val){value = val * SI_GSSE;};

Energy operator + (Energy e1, Energy e2){
    Energy e;
    e.value = e1.value + e2.value;
    return e;
};

Energy operator - (Energy e1, Energy e2){
    Energy e;
    e.value = e1.value - e2.value;
    return e;
};


int main(){
    
};
