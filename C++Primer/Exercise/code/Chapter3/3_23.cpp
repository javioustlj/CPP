#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v(10, 8);
    for (auto it = v.begin(); it != v.end(); ++it)
        *it += *it;
    for (const auto &i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
