#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>

class MyClass{
    public:
        int size=10;
        *arr = new int[size];
        std::vector vect;

        MyClass() = default;

        MyClass(const MyClass &object){
            size = object.size;
            arr = object.arr;
            vect = object.vect;
            const auto end_time = std::chrono::steady_clock::now();
            const auto dur = end_time - start_time_;
            std::cout << "copy: ";
            std::cout << "operation time" << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;
        };

        MyClass operator=(const MyClass& object){
            if (this == &object) return *this;
            size = object.size;
            arr = object.arr;
            vect = object.vect;
            return *this
        };
        MyClass(MyClass&& Object) noexcept 
        {size = object.size;
            arr = object.arr;
            vect = object.vect;
            object.size = 0;
            delete object.arr;
            object.vect = 0;
            std::cout << "move: ";
            std::cout << "operation time" << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" << std::endl;
        };
            };
        
        MyClass& operator=(const MyClass& object){
            if (this == &object) return *this;
            size = object.size;
            arr = object.arr;
            vect = object.vect;
            object.size = 0;
            delete object.arr;
            object.vect = 0;
            return *this
        };

        ~MyClass() = default; 
};
