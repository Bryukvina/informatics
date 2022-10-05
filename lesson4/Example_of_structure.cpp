#include <iostream>
#include <iomanip>


struct Workout{
    int duration;     //  in m
    int difficalty;

    Workout() {
        duration = 30;
        difficalty = 1;
    };
    ~Workout(){};
};

void make_easy(Workout ex){
    ex.difficalty = 1;
};

void make_harder(Workout ex){
    ex.difficalty = 3;
};

void change_duration(Workout ex, int time){
    ex.duration = time;
};

Workout operator + (Workout ex1, Workout ex2){
    Workout result;
    result.difficalty = std::max(ex1.difficalty, ex2.difficalty);
    result.duration = ex1.duration + ex2.duration;
    return result;
};

void print(Workout ex){
    std::cout << "Duration = " << ex.duration << ", Difficalty = " << ex.difficalty << std::endl;
};

int main(){
    Workout ex1;
    Workout ex2;
    ex1.duration = 30;
    ex2.duration = 40;
    ex1.difficalty = 3;
    ex2.difficalty = 2;

    print(ex1 + ex2);
    make_harder(ex2);
    print(ex2);

    make_easy(ex1);
    print(ex1);

    change_duration(ex1, 20);
    print(ex1);

    return 0;
};
