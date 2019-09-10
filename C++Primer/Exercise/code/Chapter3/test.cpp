#include <iostream>

int main()
{
    int a = 1, b = 0, *p1 = &a, *p2 = &b;

    std::cout << (p1 + p2) << std::endl;

    return 0;
}
