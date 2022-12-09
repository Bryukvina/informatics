#include <iostream>
#include <typeinfo>

template<class T> struct add_const { typedef const T type; };

int main(){
    int a = 12;
    
    std::cout << typeid( add_const<int>::type ).name() << std::endl;
    std::cout << typeid( int ).name() << std::endl;
};
