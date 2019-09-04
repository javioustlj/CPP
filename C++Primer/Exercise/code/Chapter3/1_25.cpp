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
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> price >> purchasePrice) {
        total.revenue = total.units_sold * price;
        total.profit = total.units_sold * (price - purchasePrice);
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> price >> purchasePrice) {
            trans.revenue = trans.units_sold * price;
            trans.profit = trans.units_sold * (price - purchasePrice);
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
                total.profit += trans.profit;
            } else {
                cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " ";
                if (total.units_sold != 0)
                    cout << total.revenue / total.units_sold << " ";
                else
                    cout << "(no sales)" << " ";

                cout << total.profit << endl;
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
    } else {
        cerr << "No data?!" << endl;
    }

    return 0;
}
