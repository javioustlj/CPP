#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    if (s1 == s2)
        std::cout << "The two strings are equal!" << std::endl;
    else
        std::cout << "The larger string is " << (s1 > s2 ? s1 : s2) << std::endl;

    return 0;
}
