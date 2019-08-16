#include<iostream>

int main()
{
    int val1 = 0, val2 = 0;
    std::cout << "Please input two numbers:" << std::endl;
    std::cin >> val1 >> val2;

    int min = 0, max = 0;
    if (val1 > val2) {
        min = val2;
        max = val1;
    } else {
        min = val1;
        max = val2;
    }

    while (min <= max) {
        std::cout << min << std::endl;
        ++min;
    }

    return 0;
}
