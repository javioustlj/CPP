#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, book;
    std::cin >> book;
    total = book;
    while (std::cin >> book)
        total += book;
    std::cout << total << std::endl;

    return 0;
}
