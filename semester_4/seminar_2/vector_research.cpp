#include <vector>
#include <iostream>

int main ()
{
  std::vector<int> myvector;
  for (int i=0; i<30; i++) {
    myvector.push_back(i);
    std::cout << "capacity: " << (int) myvector.capacity() << '\n';}

  /*
  При последовательном увеличении вектора при переполнении объем памяти увеличивается в 2 раза
  */

    std::vector<int> myvector;
    myvector.reserve(29);
    for (int i=0; i<70; i++) {
    myvector.push_back(i);
    std::cout << "capacity: " << (int) myvector.capacity() << '\n';};

    
  /*
  В данном случае вектор увеличивается вдвое, но начиная с того размера, который задан в функции reserve
  */
    std::vector<int> myvector;
    std::vector<int>::size_type sz;
    int i;
    myvector.reserve(10000000);
    sz = myvector.capacity();
    for(i=0; i<10000000000; i++){
        myvector.push_back(i); 
        if(myvector.capacity() != sz){
            sz = myvector.capacity();
            std::cout << "new capacity = " << sz << std::endl;
        };
    };
    /*
    память увеличивается до значения capacity = 1280000000, а при попытки увеличить -> выдает ошибку
    */
  return 0;
  }
