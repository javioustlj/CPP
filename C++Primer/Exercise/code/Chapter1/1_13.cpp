#include<iostream>

int main()
{
    for (int i = 50; i <= 100; ++i)
        std::cout << i << std::endl;
    for (int i = 10; i >= 0; --i)
        std::cout << i << std::endl;
    int val1, val2;
    std::cout << "Please input two numbers:" << std::endl;
    std::cin >> val1 >> val2;
    for (int i = val1; i <= val2; ++i)
        std::cout << i << std::endl;

    return 0
}
