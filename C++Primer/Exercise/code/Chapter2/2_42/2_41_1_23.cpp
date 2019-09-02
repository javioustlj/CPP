#include <iostream>
#include "Sales_data.h"

int main()
{
    double price{0.0}, purchasePrice{0.0};
    Sales_data currData, valData;
    if (std::cin >> currData.bookNo >> currData.units_sold >> price >> purchasePrice) {
        currData.revenue = currData.units_sold * price;
        currData.profit = currData.units_sold * (price - purchasePrice);
        unsigned cnt = 1;
        while (std::cin >> valData.bookNo >> valData.units_sold >> price >> purchasePrice) {
            valData.revenue = valData.units_sold * price;
            valData.profit = valData.units_sold * (price - purchasePrice);
            if (currData.bookNo == valData.bookNo) {
                ++cnt;
            } else {
                std::cout << currData.bookNo << " occurs "
                          << cnt << " times" << std::endl;
            }
        }
        std::cout << currData.bookNo << " occurs "
                  << cnt << " times" << std::endl;
    }

    return 0;
}
