#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (decltype(v.size()) i = 0; i < v.size() / 2; ++i)
        std::cout << v[i] + v[v.size() - 1 - i] << " ";
    std::cout << std::endl;

    return 0;
}
