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
    Sales_data data1, data2;
    std::cin >> data1.bookNo >> data1.units_sold >> price >> purchasePrice;
    data1.revenue = data1.units_sold * price;
    data1.profit = data1.units_sold * (price - purchasePrice);
    std::cin >> data2.bookNo >> data2.units_sold >> price >> purchasePrice;
    data2.revenue = data2.units_sold * price;
    data2.profit = data2.units_sold * (price - purchasePrice);

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        double totalProfit = data1.profit + data2.profit;
        std::cout << data1.bookNo << " "
                  << totalCnt << " "
                  << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << " ";
        else
            std::cout << "(no sales)" << " ";

        std::cout << totalProfit << std::endl;

        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;

        return -1;
    }
}

