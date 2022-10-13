#include <iostream>
#include <iomanip>

class Protected_class1{
    public:
        Protected_class1();
        ~Protected_class1() = default;

    private:
        int const protected_value = 10;
};

class general_class{
    public:
        int value;

        general_class();
        ~general_class() = default;
        friend void func(general_class val);
    private:
        class Protected_class;
};

void func(general_class val){
    std::cout << val.value << std::endl;
    std::cout << general_class::Protected_class::protected_value << std::endl;
};
