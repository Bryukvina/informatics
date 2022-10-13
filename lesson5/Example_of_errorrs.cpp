#include <iostream>
#include <iomanip>

class Test_system{
    public:
        int value_1;
        int value_2;

        Test_system();
        ~Test_system() = default;

        void test_function_1();
        void test_function_2();

};

void Test_system::test_function_1(){
    value_1 = value_1 + value_2;
};

void Test_system::test_function_1(){
    value_2 = value_1 + value_2;
};

int main(){
    Test_system ex1;
    Test_system ex2;

    ex1.value_1 = 1;
    ex1.value_2 = 2;

    ex2.value_1 = 1;
    ex2.value_2 = 2;

    ex1.test_function_1();
    ex2.test_function_2();
};
