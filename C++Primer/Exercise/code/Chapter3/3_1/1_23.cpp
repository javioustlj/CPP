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
    Sales_data currData, valData;
    if (cin >> currData.bookNo >> currData.units_sold >> price >> purchasePrice) {
        currData.revenue = currData.units_sold * price;
        currData.profit = currData.units_sold * (price - purchasePrice);
        unsigned cnt = 1;
        while (cin >> valData.bookNo >> valData.units_sold >> price >> purchasePrice) {
            valData.revenue = valData.units_sold * price;
            valData.profit = valData.units_sold * (price - purchasePrice);
            if (currData.bookNo == valData.bookNo) {
                ++cnt;
            } else {
                cout << currData.bookNo << " occurs "
                          << cnt << " times" << endl;
            }
        }
        cout << currData.bookNo << " occurs "
                  << cnt << " times" << endl;
    }

    return 0;
}
