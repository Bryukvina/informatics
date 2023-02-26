#include <iostream>
#include <cmath>
#include <vector>


//RA-iterators
int binsearch_RA(std::vector arr, int key){
    auto it_beg = arr.begin();
    auto it_end = arr.end();
    auto it_mid = it_beg + (it_end - it_beg) / 2;
    while (it_mid != it_end *it_mid != key) {
        if (*it_mid > key) it_end = it_mid;
        else it_beg = it_mid + 1;

        it_mid = it_beg + (it_end - it_beg) / 2;
    }
 return it_mid;

//forward-iterator
 int binsearch_for(std::vector arr, int key){
    auto it_beg = arr.begin();
    auto it_end = arr.end();
    int n = arr.size() / 2;
    int i;
    while (n > 1 && *it_sup != key) {
        auto it_sup = it_beg;
        for (i = 0, n, i++){++it_sup};
        if (*it_sup < key) {auto it_beg = it_sup};
        n /= 2;
    }
 return it_sup;

//bidirectional -iterators
int binsearch_for(std::vector arr, int key){
    auto it_beg = arr.begin();
    auto it_end = arr.end();
    int n = arr.size() / 2;
    int i;
    while (it_beg < it_end && *it_end != key) {
        if (*it_mid < key){
            for (i = 0, n, i++){++it_beg};
        };
        else {
            for (i = 0, n, i++){--it_end};
        };
        n /= 2;
    }
 return it_end;
