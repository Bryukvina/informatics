#include <iostream>


template <typename T>
class shared_ptr {
    private:
        T* ptr;
        size_t *count;
    public:
        shared_ptr(){
            ptr = nullptr;
            count = nullptr;
        };

        shared_ptr(T* ptr1):ptr(ptr){
            count = new size_t(1);
        };

        shared_ptr(shared_ptr<T>& other){
            count = other.count;
            ptr = other.ptr;
            (*count)++;};

        ~shared_ptr(){
            if (count){
                if (*count == 1){
                    delete count;
                    delete ptr;
                }
                else (*count)--;}
            throw "Object don't exist"; 
        };

        shared_ptr<T> operator=(shared_ptr<T>& other){
            if (other != *this){
            count = other.count;
            ptr = other.ptr;

            if (this != &other){
                if (*count == 1) {
                        delete count;
                        delete ptr;
                    }
                    else (*count)--;
                }
                ptr = other.ptr;
                count = other.count;
                (*count)++;};
            throw "Shared_ptr can't point to itself";
        return *this;};
        
        size_t how_many(){
            return *count;
        };
        
        
};


template<class T, class U>
bool operator==(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept {
    return lhs.ptr==rhs.ptr;
    };

template<class T, class U>
bool operator!=(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept{
    return lhs.ptr!=rhs.ptr;
    };

template<class T, class U>
bool operator<(const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept{
    return lhs.ptr<rhs.ptr;
    };

template<class T, class U>
bool operator>( const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept{
    return lhs.ptr>rhs.ptr;
    };

template<class T, class U>
bool operator<=( const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept{
    return lhs.ptr<=rhs.ptr;
    };

template<class T, class U>
bool operator>=( const shared_ptr<T>& lhs, const shared_ptr<U>& rhs) noexcept{
    return lhs.ptr>=rhs.ptr;
    };

template<class T, class Arg>
shared_ptr<T> make_shared(Arg&& arg){
    return shared_ptr<T>(new Arg(arg));
};


int main(){
    shared_ptr<int> p1(new int(9));
    std::cout << "p1.count " << p1.how_many() << "\n";
 
    shared_ptr<int> p2(p1);
    std::cout << "p2.count " << p2.how_many() << "\n";
    std::cout << "p1.count " << p1.how_many() << "\n";
 
    shared_ptr<int> p3(p2);
    std::cout << "p1.count " << p1.how_many() << "\n";
    std::cout << "p2.count " << p1.how_many() << "\n";
    std::cout << "p3.count " << p3.how_many() << "\n";
    
    shared_ptr<int> p4 = make_shared<int>(5);
    std::cout << "p4.count " << p4.how_many() << "\n";

};
