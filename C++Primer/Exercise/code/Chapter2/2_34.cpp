#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r; // a is an int (r is an alias for i, which has type int)
    auto b = ci; // b is an int (top-level const in ci is dropped)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i; // d is an int *
    auto e = &ci; // e is an const int * ??
    const auto f = ci;
    auto &g = ci; // g is a const int &
    auto &h = 42;
    const auto &j = 42;
    auto k = ci, &l = i;
    auto &m = ci, *p = &ci;
    //auto &n = i, *p2 = &ci;


    std::cout << "a = " << a << '\n'
              << "b = " << b << '\n'
              << "c = " << c << '\n'
              << "d = " << d << '\n'
              << "e = " << e << '\n'
              << "f = " << f << '\n'
              << "g = " << g << '\n'
              // << "h = " << h << '\n'
              << "i = " << i << '\n'
              << "j = " << j << '\n'
              << "k = " << k << '\n'
              << "l = " << l << '\n'
              << "m = " << m << '\n'
              // << "n = " << n << '\n'
              << "p = " << p << std::endl;
    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // f = 42;
    // g = 42;

    std::cout << "a = " << a << '\n'
              << "b = " << b << '\n'
              << "c = " << c << '\n'
              << "d = " << d << '\n'
              << "e = " << e << '\n'
              << "f = " << f << '\n'
              << "g = " << g << '\n'
              // << "h = " << h << '\n'
              << "i = " << i << '\n'
              << "j = " << j << '\n'
              << "k = " << k << '\n'
              << "l = " << l << '\n'
              << "m = " << m << '\n'
              // << "n = " << n << '\n'
              << "p = " << p << std::endl

    return 0;
}
