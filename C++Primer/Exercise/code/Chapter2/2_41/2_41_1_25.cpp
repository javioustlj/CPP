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
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> price >> purchasePrice) {
        total.revenue = total.units_sold * price;
        total.profit = total.units_sold * (price - purchasePrice);
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price >> purchasePrice) {
            trans.revenue = trans.units_sold * price;
            trans.profit = trans.units_sold * (price - purchasePrice);
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
                total.profit += trans.profit;
            } else {
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << " ";
                else
                    std::cout << "(no sales)" << " ";

                std::cout << total.profit << std::endl;
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
    } else {
        std::cerr << "No data?!" << std::endl;
    }

    return 0;
}
