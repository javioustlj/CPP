#include <iostream>
#include "Sales_data.h"

int main()
{
    double price{0.0}, purchasePrice{0.0};
    Sales_data data;
    while (std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
        data.revenue = data.units_sold * price;
        data.profit = data.units_sold * (price - purchasePrice);
        std::cout << data.bookNo << " "
                  << data.units_sold << " "
                  << data.revenue << " ";
        if (data.units_sold)
            std::cout << data.revenue / data.units_sold << " ";
        else
            std::cout << 0 << " ";
        std::cout << data.profit << std::endl;
    }

    return 0;
}

