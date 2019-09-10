#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (auto lit = v.cbegin(), rit = v.cend() - 1; lit < rit; ++lit, --rit)
        std::cout << *lit + *rit << " ";
    std::cout << std::endl;

    return 0;
}
