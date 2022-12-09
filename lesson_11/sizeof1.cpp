#include <iostream>

template <typename ... Args>
double size(Args&... args)
{
    double res;
    res = (sizeof...(args) + ...);
    return res;
};
