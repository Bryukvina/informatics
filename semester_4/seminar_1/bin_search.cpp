#include <cmath>
#include <vector>

auto binsearch(std::vector arr, int key){
    auto it_beg = arr.begin();
    auto it_end = arr.end();
    auto it_mid = it_beg + (it_end - it_beg) / 2;
    while (it_mid != it_end *it_mid != key) {
        if (*it_mid > key) it_end = it_mid;
        else it_beg = it_mid + 1;

        it_mid = it_beg + (it_end - it_beg) / 2;
    }
 return it_mid;
