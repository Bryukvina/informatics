#include <iostream>
#include <iomanip>

class Workout{
    public: 
        int difficalty;
        int duration;

        Workout(){};
        Workout(int min, int dif){duration = min; difficalty = dif;};
        ~Workout() = default;

        void make_easy();

        void make_harder();
    
        void print();

        friend Workout operator+ (Workout ex1, Workout ex2);

    private:

        std::string sub_name;
};
