template <typename ...>
struct Sum {};

template <>
struct Sum<> 
{ enum { value = 0 }; };

template <typename first, typename... other>
struct Sum<first, other...>
{ enum { value = first + Sum<other...>::value }; };

template <class... Types>
struct Sizeof
{ enum { value = Sum<sizeof(Types)...>::value }; };
