#include <iostream>
#include <cstddef>

typedef int int_array[4]; // using int_array = int[4];

void printArrayByRangeBasedLoop()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for (const int_array &row : ia)
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
        for (size_t col = 0; col != 4; ++col)
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
    for (const int_array *p = ia; p != ia + 3; ++p)
        for (const int *q = *p; q != *p + 4; ++q)
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
