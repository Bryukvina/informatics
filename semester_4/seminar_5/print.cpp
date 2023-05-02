#include <iostream>

void print(){};

template<typename first_arg, typename... args>
void print(first_arg&& arg1, args&&... args2) {
	std::cout << arg1 << std::endl;
	print(std::forward<args>(args2)...);
}

int main(){
  int N = 5;
  float m = 2.3;
  std::string str = "str";
  print(N, m, str);
};
