#include <iostream>
#include <string>
#include <vector>

void printVector(const std::vector<int> &v)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printVector(const std::vector<std::string> &v)
{
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};
    std::cout << "v1:" << std::endl;
    printVector(v1);
    std::cout << "v2:" << std::endl;
    printVector(v2);
    std::cout << "v3:" << std::endl;
    printVector(v3);
    std::cout << "v4:" << std::endl;
    printVector(v4);
    std::cout << "v5:" << std::endl;
    printVector(v5);
    std::cout << "v6:" << std::endl;
    printVector(v6);
    std::cout << "v7:" << std::endl;
    printVector(v7);

    return 0;
}
