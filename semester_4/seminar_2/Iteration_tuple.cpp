#include <iostream>
#include <iterator>
#include <tuple>

template <typename T>
void El(const T& x) {
    std::cout << x << ',';
};

template <typename Tup, std::size_t... list_s>
void Iterate_Tuple(const Tup& tp) {
    (El(std::get<list_s>(tp)), ...);
}

/*Вызов функции*/
int main(){
    std::tuple<int> tp = {1, 2, 3, 4, 8, 9};
    Iterate_Tuple(tp, std::make_index_sequence<std::tuple_size<decltype(tp)>::value>{});
    return 0;
};
