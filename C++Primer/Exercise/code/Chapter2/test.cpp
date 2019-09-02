#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    decltype(++a) e = a;
    decltype(a++) f;

    std::cout << "a = " << a << '\n'
              << "b = " << b << '\n'
              << "c = " << c << '\n'
              << "d = " << d << '\n'
              << "e = " << e << '\n'
              << "f = " << f << '\n'
              << std::endl;

    return 0;
}

