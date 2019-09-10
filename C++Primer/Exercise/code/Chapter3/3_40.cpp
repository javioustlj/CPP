#include <iostream>
#include <cstring>

int main()
{
    const char *s1 = "Hello";
    const char *s2 = "World";
    char s3[11] = { };
    std::strcpy(s3, s1);
    std::strcat(s3, s2);
    std::cout << s3 << std::endl;

    return 0;
}
