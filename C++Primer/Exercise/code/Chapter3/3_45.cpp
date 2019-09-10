#include <iostream>
#include <cstddef>

void printArrayByRangeBasedLoop()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (const auto &row : ia)
        for (const auto &col : row)
            std::cout << col << " ";
    std::cout << std::endl;
}

void printArrayBySubscripts()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (std::size_t row = 0; row != 3; ++row)
        for (std::size_t col = 0; col != 4; ++col)
            std::cout << ia[row][col] << " ";
    std::cout << std::endl;
}

void printArrayByPointers()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (auto p = std::begin(ia); p != std::end(ia); ++p)
        for (auto q = std::begin(*p); q != std::end(*p); ++q)
            std::cout << *q << " ";
    std::cout << std::endl;
}

int main()
{
    printArrayByRangeBasedLoop();
    printArrayBySubscripts();
    printArrayByPointers();

    return 0;
}
