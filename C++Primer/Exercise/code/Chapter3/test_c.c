#include <stdio.h>

int main()
{
        int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int *p = &a[3];

        printf("%d", p[-2]);

        return 0;
}
