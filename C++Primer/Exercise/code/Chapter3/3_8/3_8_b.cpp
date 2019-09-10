#include <iostream>
#include <string>

int main()
{
    std::string s{"Hello World!"};
    std::string::size_type index{0};
    while(index != s.size()) {
        s[index] = 'X';
        ++index;
    }
    std::cout << s << std::endl;

    return 0;
}
