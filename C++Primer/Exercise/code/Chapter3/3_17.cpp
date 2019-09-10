#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string s;
    std::vector<std::string> v;
    while (std::cin >> s)
        v.push_back(s);
    for (auto &s : v)
        for (auto &c : s)
            c = std::toupper(c);
    unsigned cnt{ };
    for (auto &s : v)
        std::cout << s << (++cnt % 8 ? ' ' : '\n');
    std::cout << std::endl;

    return 0;
}
