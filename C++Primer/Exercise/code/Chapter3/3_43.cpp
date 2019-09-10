#include <iostream>
#include <cstddef>

void printArrayByRangeBasedLoop()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (const int (&row)[4] : ia)
        for (const int &col : row)
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
    for (int (*p)[4] = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
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
