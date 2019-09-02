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
