#include <iostream>
#include <cmath>
#include <vector>
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



class MyClass{
    public:
        int size=10;
        *arr = new int[size];
        std::vector vect;

        MyClass() = default;

        MyClass(const MyClass &object){
            LogDuration ld("copy:");
            size = std::copy(object.size);
            arr = std::copy(object.arr);
            vect = std::copy(object.vect);
        };

        MyClass operator=(const MyClass& object){
            LogDuration ld("copy operator:");
            size = std::copy(object.size);
            arr = std::copy(object.arr);
            vect = std::copy(object.vect);
            return *this;
        };

        MyClass(MyClass&& Object) noexcept {
            LogDuration ld("move");
            size = std::move(object.size);
            arr = std::move(Object.arr);
            size = std::move(Object.size);
            vect = std::move(Object.vect);
        };
        
        MyClass& operator=(const MyClass&& object){
            LogDuration ld("move operator:");
            arr = std::move(Object.arr);
            size = std::move(Object.size);
            vect = std::move(Object.vect);
            return *this;
        };

        ~MyClass() = default; 
};


int main(){
    MyClass cl;
    std::vector<int> vect = {1, 2, 3}
    cl.vect = vect;
    
    
    
    return 0;
};
