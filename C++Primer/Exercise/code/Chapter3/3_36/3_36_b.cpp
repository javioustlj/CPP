#include <iostream>
#include <vector>

int main()
{
    std::vector<int> iva(10, 0);
    std::vector<int> ivb(10, 1);
    std::cout << (iva == ivb) << std::endl;

    return 0;
}
