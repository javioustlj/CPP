1. 在16位C编译系统上，若定义long a; 则能给a赋40000的正确语句是( )

     A. a = 20000 + 20000;
     B. a = 4000 * 10;
     C. a = 30000 + 10000;
     D. a = 4000L * 10L;

2. This output 0x789A3456

   .. code-block:: cpp

     #include <iostream>

     int main()
     {
         long long b = 0x123456789A;
         int a = b;

         std::cout << a << std::endl;

         return 0;
     }

3. For local variable, it can be initialized to 0 with " {} ".

     The following code, a and stuA have undefined value while b and stuB have value zero.

     .. code-block:: cpp

       #include <iostream>

       struct Student
       {
           char name[10];
           unsigned score;
       };

       int main()
       {
           Student stuA, stuB{ };
           int a, b{ };

           return 0;
       }

4. The index used with arrays can be a negative value both in C and CPP;
   The C++ library types such as vector and string that have subscript operators force the index to be an unsigned type.

     The following program will output 1.

     .. code-block:: cpp

       #include <stdio.h>

       int main()
       {
               int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
               int *p = &a[3];

               printf("%d", p[-2]);

               return 0;
       }
