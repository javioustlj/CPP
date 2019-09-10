#include <iostream>
#include <iterator>

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int *pbeg = std::begin(ia); pbeg != std::end(ia); ++pbeg)
        *pbeg = 0;
    for (const auto &i : ia)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
