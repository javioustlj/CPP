#include<iostream>

int main()
{
    int val1, val2;
    std::cout << "Please input two numbers:" << std::endl;
    std::cin >> val1 >> val2;
    while (val1 <= val2) {
        std::cout << val1 << std::endl;
        ++val1;
    }

    return 0;
}
