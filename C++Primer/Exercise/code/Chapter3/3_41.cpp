#include <vector>
#include <iterator>

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5};
    std::vector<int> v(std::begin(a), std::end(a));

    return 0;
}
