#include <iostream>
#include <string>

int main()
{
    std::string s{"Hello World!"};
    for (auto &c : s)
        c = 'X';

    for (std::string::size_type index = 0; index != s.size(); ++index)
        s[index] = 'X';

    std::string::size_type index{0};
    while(index != s.size()) {
        s[index] = 'X';
        ++index;
    }

    std::cout << s << std::endl;

    return 0;
}
