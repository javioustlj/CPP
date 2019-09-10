#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int val1, val2;
    cout << "Please input two numbers:" << endl;
    cin >> val1 >> val2;
    while (val1 <= val2) {
        cout << val1 << endl;
        ++val1;
    }

    return 0;
}
