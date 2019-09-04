#include<iostream>

using std::cout;
using std::endl;

int main()
{
    int val = 50, sum = 0;
    while (val <= 100) {
        sum += val;
        ++val;
    }
    cout << "Sum of 50 to 100 inclusive is " << sum << endl;

    return 0;
}

