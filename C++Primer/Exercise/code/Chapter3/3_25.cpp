#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100)
            ++*(scores.begin() + grade / 10);
    }
    for (const auto &i : scores)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
