#include<iostream>

int main()
{
    int val = 0, sum = 0;
    while (std::cin >> val)
        if (val % 2)
            sum += val;
    std::cout << "Sum of odd numbers is " << sum << std::endl;

    return 0;
}
