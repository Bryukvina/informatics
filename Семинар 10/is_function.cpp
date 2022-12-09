#include <iostream>

template<class T>
struct is_function : std::integral_constant<
    bool,
    !std::is_const<const T>::value && !std::is_reference<T>::value
> {};

int f();


int main(){
    int a = 12;

    std::cout << "#1 " << is_function<decltype(f)>::value << '\n';
    std::cout << "#2 " << is_function<int>::value << '\n';
}
