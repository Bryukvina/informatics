#include <iostream>
#include <iomanip>
#include "Class.hpp"


void Workout::make_easy(){difficalty = 1;};

void Workout::make_harder(){difficalty = 3;};

void Workout::print(){std::cout << "Duration = " << duration << ", Difficalty = " << difficalty << std::endl;};

void change_duration(Workout ex, int time){
    ex.duration = time;
};

Workout operator + (Workout ex1, Workout ex2){
    Workout result;
    result.difficalty = std::max(ex1.difficalty, ex2.difficalty);
    result.duration = ex1.duration + ex2.duration;
    return result;
};

int main(){
    
    Workout ex1;
    Workout ex2(40, 2);
    ex1.duration = 30;
    ex1.difficalty = 3;

    
    ex2.make_harder();
    ex2.print();

    ex1.make_easy();
    ex1.print();
    
    (ex1 + ex2).print();
    
    change_duration(ex1, 20);
    ex1.print();

    return 0;
};
