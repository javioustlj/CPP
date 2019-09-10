#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5};
    int a[6] = { };
    int j = 0;
    for (const auto &i : v)
        a[j++] = i;
    for (const auto &i : a)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
