#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double profit = 0.0;
};

int main()
{
    double price{0.0}, purchasePrice{0.0};
    Sales_data total, data;
    std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice;
    data.revenue = data.units_sold * price;
    data.profit = data.units_sold * (price - purchasePrice);
    total = data;
    while (std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
        data.revenue = data.units_sold * price;
        data.profit = data.units_sold * (price - purchasePrice);
        if (total.bookNo == data.bookNo) {
            total.units_sold += data.units_sold;
            total.revenue += data.revenue;
            total.profit += data.profit;
        } else {
            std::cerr << "Data must refer to the same ISBN" << std::endl;
            break;
        }
    }

    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << " ";
    if (total.units_sold != 0)
        std::cout << total.revenue / total.units_sold << " ";
    else
        std::cout << "(no sales)" << " ";

    std::cout << total.profit << std::endl;

    return 0;
}
