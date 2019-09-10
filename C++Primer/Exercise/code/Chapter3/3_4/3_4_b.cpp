#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    if (s1.size() == s2.size())
        std::cout << "The length of two strings are equal!" << std::endl;
    else
        std::cout << "The longer string is "
                  << (s1.size() > s2.size() ? s1 : s2) << std::endl;

    return 0;
}
