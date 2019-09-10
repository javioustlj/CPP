#include <iostream>
#include <string>

using std::cin;
using std::cout;
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
    Sales_data data;
    while (cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
        data.revenue = data.units_sold * price;
        data.profit = data.units_sold * (price - purchasePrice);
        cout << data.bookNo << " "
                  << data.units_sold << " "
                  << data.revenue << " ";
        if (data.units_sold)
            cout << data.revenue / data.units_sold << " ";
        else
            cout << 0 << " ";
        cout << data.profit << endl;
    }

    return 0;
}

