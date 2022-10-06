#include <iostream>
#include <iomanip>


struct Workout{
    int duration;     //  in m
    int difficalty;

    Workout() {30, 1;};
    Workout(int min, int dif){duration = min; difficalty = dif;};
    ~Workout(){};

    void make_easy(){difficalty = 1;};

    void make_harder(){difficalty = 3;};
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
    ex2.make_harder();
    print(ex2);

    ex1.make_easy();
    print(ex1);

    change_duration(ex1, 20);
    print(ex1);

    return 0;
};
