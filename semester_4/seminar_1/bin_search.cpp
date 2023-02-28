#include <iostream>
#include <cmath>
#include <vector>
#include <interator>
#include <chrono>

class LogDuration {
public:
    LogDuration(std::string id)
        : id_(std::move(id)) {
    }

    ~LogDuration() {
        const auto end_time = std::chrono::steady_clock::now();
        const auto dur = end_time - start_time_;
        std::cout << id_ << ": ";
        std::cout << "operation time"
                  << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
                  << " ms" << std::endl;
    }

private:
    const std::string id_;
    const std::chrono::steady_clock::time_point start_time_ = std::chrono::steady_clock::now();
};




template <typename value, std::forward_interator It>;

value binsearch(std::vector<value> arr, value key){
    LogDuration ld("identifier");
    It it_beg = arr.begin();
    It it_end = arr.end();
    int n = arr.size() / 2;
    int i;
    while (n > 1 && *it_sup != key) {
        It it_sup = it_beg;
        for (i = 0, n, i++){++it_sup};
        if (*it_sup < key) {It it_beg = it_sup};
        n /= 2;
    }
    return it_sup;
};



template <typename value, std::random_access_iterator It>;

value binsearch(std::vector<value> arr, value key){
    LogDuration ld("identifier");
    It it_beg = arr.begin();
    It it_end = arr.end();
    It it_mid = it_beg + (it_end - it_beg) / 2;
    while (it_mid != it_end *it_mid != key) {
        if (*it_mid > key) it_end = it_mid;
        else it_beg = it_mid + 1;
        it_mid = it_beg + (it_end - it_beg) / 2;
    }
    return it_mid;
};


template <typename value, std::bidirectional_iterator It>;

int binsearch(std::vector arr, int key){
    LogDuration ld("identifier");
    It it_beg = arr.begin();
    It it_end = arr.end();
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
}
