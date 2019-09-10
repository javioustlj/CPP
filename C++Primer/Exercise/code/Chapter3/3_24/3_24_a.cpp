#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (auto it = v.cbegin(); it < v.cend(); it += 2) {
        if (it + 1 != v.cend())
            std::cout << *it + *(it + 1) << " ";
        else
            std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
