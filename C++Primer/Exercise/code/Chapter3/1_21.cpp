#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double profit = 0.0;
};

int main()
{
    double price{0.0}, purchasePrice{0.0};
    Sales_data data1, data2;
    cin >> data1.bookNo >> data1.units_sold >> price >> purchasePrice;
    data1.revenue = data1.units_sold * price;
    data1.profit = data1.units_sold * (price - purchasePrice);
    cin >> data2.bookNo >> data2.units_sold >> price >> purchasePrice;
    data2.revenue = data2.units_sold * price;
    data2.profit = data2.units_sold * (price - purchasePrice);

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        double totalProfit = data1.profit + data2.profit;
        cout << data1.bookNo << " "
                  << totalCnt << " "
                  << totalRevenue << " ";
        if (totalCnt != 0)
            cout << totalRevenue / totalCnt << " ";
        else
            cout << "(no sales)" << " ";

        cout << totalProfit << endl;

        return 0;
    } else {
        cerr << "Data must refer to the same ISBN" << endl;

        return -1;
    }
}

