#include <iostream>
#include <cmath>
#include <vector>

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
        };
  
        MyClass operator=(const MyClass& object){
            if (this == &object) return *this;
            size = object.size;
            arr = object.arr;
            vect = object.vect;
            return *this
        };
  
        MyClass(MyClass&& Object) noexcept {
            size = object.size;
            arr = object.arr;
            vect = object.vect;
            object.size = 0;
            delete object.arr;
            object.vect = 0;
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
