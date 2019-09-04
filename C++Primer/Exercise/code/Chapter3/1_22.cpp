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
    Sales_data total, data;
    cin >> data.bookNo >> data.units_sold >> price >> purchasePrice;
    data.revenue = data.units_sold * price;
    data.profit = data.units_sold * (price - purchasePrice);
    total = data;
    while (cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
        data.revenue = data.units_sold * price;
        data.profit = data.units_sold * (price - purchasePrice);
        if (total.bookNo == data.bookNo) {
            total.units_sold += data.units_sold;
            total.revenue += data.revenue;
            total.profit += data.profit;
        } else {
            cerr << "Data must refer to the same ISBN" << endl;
            break;
        }
    }

    cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << " ";
    if (total.units_sold != 0)
        cout << total.revenue / total.units_sold << " ";
    else
        cout << "(no sales)" << " ";

    cout << total.profit << endl;

    return 0;
}
