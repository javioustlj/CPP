#include <iostream>
#include <iterator>

int main()
{
    int a[] = {0, 1, 2, 3};
    int b[] = {0, 1, 2};
    int *pbega = std::begin(a), *penda = std::end(a);
    int *pbegb = std::begin(b), *pendb = std::end(b);
    if (pendb - pbegb != penda - pbega) {
        std::cout << "Two arrays are not equal!" << std::endl;
    } else {
        while (pbega != penda) {
            if (*pbega != *pbegb) {
                std::cout << "Two arrays are not equal!" << std::endl;
                break;
            }
            ++pbega;
            ++pbegb;
        }
        if (pbega == penda)
            std::cout << "Two arrays are equal." << std::endl;
    }

    return 0;
}
