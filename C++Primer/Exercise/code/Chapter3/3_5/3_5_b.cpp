#include <iostream>
#include <string>

int main()
{
    std::string concatenation, s;
    std::cin >> concatenation;
    while (std::cin >> s)
        concatenation += ' ' + s;
    std::cout << "The concatenated string is: " << concatenation << std::endl;

    return 0;
}
