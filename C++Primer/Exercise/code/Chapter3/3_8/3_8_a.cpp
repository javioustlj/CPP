#include <iostream>
#include <string>

int main()
{
    std::string s{"Hello World!"};
    for (std::string::size_type index = 0; index != s.size(); ++index)
        s[index] = 'X';
    std::cout << s << std::endl;

    return 0;
}
