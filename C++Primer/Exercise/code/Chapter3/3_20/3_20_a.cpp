#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (decltype(v.size()) i = 0; i < v.size(); i += 2) {
        if (i + 1 < v.size())
            std::cout << v[i] + v[i + 1] << " ";
        else
            std::cout << v[i];
    }
    std::cout << std::endl;

    return 0;
}
