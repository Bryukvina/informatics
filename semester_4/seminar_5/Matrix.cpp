#include <iostream>
#include <cassert> 

template <typename T>

class MATRIX
{
private:
  T** Matrix; // матрица
  int m; // строки
  int n; // столбцы

public:
  MATRIX()
  {
    n = m = 0;
    Matrix = nullptr;
  };

  MATRIX(int _m, int _n)
  {
    m = _m;
    n = _n;
    Matrix = (T**) new T*[m];
    for (int i = 0; i < m; i++){Matrix[i] = (T*)new T[n];};
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){Matrix[i][j] = 0;};
    };
  };

  MATRIX(const MATRIX& _M)
  {
    m = _M.m;
    n = _M.n;
    Matrix = (T**) new T*[m];
    for (int i = 0; i < m; i++){Matrix[i] = (T*) new T[n];};
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){Matrix[i][j] = _M.Matrix[i][j];};
    };
  };

  MATRIX operator=(const MATRIX& M)
  {
    if (n > 0)
    {
      for (int i = 0; i < m; i++)
        delete[] Matrix[i];
    }
    if (m > 0)
    {
      delete[] M;
    }
    m = M.m;
    n = M.n;
    Matrix = (T**) new T*[m];
    for (int i = 0; i < m; i++){Matrix[i] = (T*) new T[n];};
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){Matrix[i][j] = M.Matrix[i][j];};
    };
    return *this;
  };

  ~MATRIX()
  {
    if (n > 0)
    {
      for (int i = 0; i < m; i++)
        delete[] Matrix[i];
    }
    if (m > 0)
      delete[] Matrix;
  };

  T GetMij(int i, int j)
  {
    assert(m > i && n > j );
    return Matrix[i][j];
  };

  void SetMij(int i, int j, T value)
  {
    assert(m > i && n > j );
    Matrix[i][j] = value;
  };

  MATRIX Sum(MATRIX M1, MATRIX M2){
    assert((M1.n == M2.n) && (M1.m == M2.m));
    MATRIX res(M1.m, M1.n);
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++)
        {res.Matrix[i][j] = M1.Matrix[i][j] + M2.Matrix[i][j];};
    };
    return res;
  };

  MATRIX operator+(const MATRIX& M)
    {
      assert ((M.n == this->n) && (M.m == this->m));
      if (this->n > 0)
      {
        for (int i = 0; i < m; i++){
          delete[] this->Matrix[i];};
      }
      if (this->m > 0)
      {
        delete[] M;
      }
      for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){this->Matrix[i][j] += M.Matrix[i][j];};
      };
      return *this;
    };


  MATRIX dif(MATRIX M1, MATRIX M2){
    assert((M1.n == M2.n) && (M1.m == M2.m));
    MATRIX res(M1.m, M1.n);
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++)
        {res.Matrix[i][j] = M1.Matrix[i][j] + M2.Matrix[i][j];};
    };
    return res;
  };

  MATRIX operator-(const MATRIX& M)
    {
      assert ((M.n == this->n) && (M.m == this->m));
      if (this->n > 0)
      {
        for (int i = 0; i < m; i++)
          {delete[] this->Matrix[i];};
      }
      if (this->m > 0)
      {
        delete[] M;
      }
      for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){this->Matrix[i][j] -= M.Matrix[i][j];};
      };
      return *this;
    };
};

int main(){
    MATRIX m(2, 3);
    m.SetMij(0, 0, 2);
    m.SetMij(1, 1, 3);
    MATRIX n(2, 3);
    n.SetMij(0, 1, 2);
    n.SetMij(1, 0, 3);
    m = m + n;
    std::cout << m.GetMij(0, 1) << std::endl;
};
