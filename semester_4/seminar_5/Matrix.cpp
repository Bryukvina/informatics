#include <iostream>
#include <cassert> 


template<typename T, unsigned  n, unsigned  m>
class MATRIX{
  public:
    T** Matrix;

    MATRIX()
    {
      Matrix = (T**) new T*[m];
      for (int i = 0; i < m; i++){Matrix[i] = (T*)new T[n];};
      for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){Matrix[i][j] = 0;};
      };
    };

    MATRIX(const MATRIX& _M)
    {
      Matrix = (T**) new T*[m];
      for (int i = 0; i < m; i++){Matrix[i] = (T*) new T[n];};
      for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){Matrix[i][j] = _M.Matrix[i][j];};
      };
    };

    void print(){
      for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){std::cout << Matrix[i * m + j] << " ";};
        std::cout << std::endl;
      };
    };

    void SetMij(int i, int j, T value){
        Matrix[i][j] = value;
    };
};

template<typename T, unsigned n1, unsigned m1, unsigned n2, unsigned m2>
MATRIX<T, n1, m1> operator+(MATRIX<T, n1, m1> M1, MATRIX<T, n2, m2> M2){
  assert((n1 == n2) && (m1 == m2));
  MATRIX<T, n1, m1> res;
    for (int i = 0; i < m1; i++){
      for (int j = 0; j < n1; j++){res.Matrix[i][j] = M1.Matrix[i][j] + M2.Matrix[i][j];};
    };
    return res;
  };
  
  
template<typename T, unsigned n1, unsigned m1, unsigned n2, unsigned m2>
MATRIX<T, n1, m2> operator*(MATRIX<T, n1, m1> M1, MATRIX<T, n2, m2> M2){
  assert(n2 == m1);
  MATRIX<T, n1, m2> res;
  for (int i = 0; i < n1; i++){
    for (int j = 0; j < m2; j++){
        for (int k = 0; k < m1; k++){res.Matrix[i][j] += M1.Matrix[i][k] * M2.Matrix[k][j];};
    };
    return res;
  };
};
  

int main(){
    MATRIX<int, 2, 3> Mat1;
    MATRIX<int, 2, 3> Mat2;
    
    Mat1.SetMij(0, 0, 1);
    Mat1.SetMij(0, 1, 2);
    Mat1.SetMij(1, 0, 3);
    Mat1.SetMij(1, 1, 4);
    Mat1.SetMij(0, 2, 5);
    
    Mat2.SetMij(0, 0, 6);
    Mat2.SetMij(0, 1, 7);
    Mat2.SetMij(1, 0, 8);
    Mat2.SetMij(1, 1, 9);
    Mat2.SetMij(0, 2, 1);
    
    Mat2 = Mat2 + Mat1;
    Mat2.print();
    Mat1 = Mat1 * Mat2;
    Mat1.print();
    return 0;
};
