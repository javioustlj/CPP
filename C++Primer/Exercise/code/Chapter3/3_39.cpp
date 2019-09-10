#include <iostream>
#include <string>
#include <cstring>

void compareTwoStrings()
{
    std::string s1{"Hello"};
    std::string s2{"World"};
    if (s1 == s2)
        std::cout << "Two strings are equal!" << std::endl;
    else
        std::cout << "Two strings are not equal!" << std::endl;
}

void compareTwoCStyleStrings()
{
    const char *s1 = "Hello";
    const char *s2 = "World";
    if (!std::strcmp(s1, s2))
        std::cout << "Two C-style strings are equal!" << std::endl;
    else
        std::cout << "Two C-style strings are not equal!" << std::endl;
}

int main()
{
    compareTwoStrings();
    compareTwoCStyleStrings();

    return 0;
}
