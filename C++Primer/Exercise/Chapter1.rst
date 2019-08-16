Chapter 1 Getting started
==========================

1. Review the documentation for your complier and determine what file naming convention it uses. Compile and run the
   ``main`` program from page 2.

  C++ source files conventionally use one of the suffixes '.C' , '.cc' , '.cpp' , 'CPP' , '.c++', '.cp' , or '.cxx' ; C++
  header files often use '.hh' , '.hpp' , '.H' , or (for shared template code) '.tcc' ; and preprocessed C++ files use the
  suffix '.ii'. GCC recognizes files with these names and compiles them as C++ programs even if you call the compiler the
  same way as for compiling C programs (usually with the name gcc).

  https://gcc.gnu.org/onlinedocs/gcc-9.2.0/gcc/Invoking-G_002b_002b.html#Invoking-G_002b_002b

2. Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed.
   Recompile and return your program to see how your system treats a failure indicator from main.

  This is in windows cmd::

    c:\my\learning\C++Primer\Exercise\code\Chapter1>a.exe
    c:\my\learning\C++Primer\Exercise\code\Chapter1>echo %ERRORLEVEL%
    -1
    c:\my\learning\C++Primer\Exercise\code\Chapter1>

  This is in windows powershell::

    PS C:\my\learning\C++Primer\Exercise\code\Chapter1> .\a.exe
    PS C:\my\learning\C++Primer\Exercise\code\Chapter1> $?
    False
    PS C:\my\learning\C++Primer\Exercise\code\Chapter1> $LASTEXITCODE
    -1

3. Write a program to print Hello, World on the standard output.

  .. code-block:: cpp

      #include<iostream>

      int main()
      {
          std::cout << "Hello, World" << std::endl;

          return 0;
      }

4. Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication
   operator, \*, to print the product instead.

  .. code-block:: cpp

      #include<iostream>

      int main()
      {
          std::cout << 3 * 5 << std::endl;

          return 0;
      }


5. We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

  .. code-block:: cpp

      #include<iostream>

      int main()
      {
          std::cout << "Enter two numbers:";
          std::cout << std::endl;
          int v1 = 0, v2 = 0;
          std::cin >> v1 >> v2;
          std::cout << "The sum of ";
          std::cout << v1;
          std::cout << " and ";
          std::cout << v2;
          std::cout << " is ";
          std::cout << v1 + v2;
          std::cout << std::endl;

          return 0;
      }

6. Explain whether the following program fragment is legal.

   .. code-block:: cpp

     std::cout << "The sum of " << v1;
               << " and " << v2;
               << " is " << v1 + v2 << std::endl;

   If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

   The program is not legal; because semicolon halt ``std::cout << "The sum of " << v1;`` , so for code in second line,
   "<<" doesn't have left operand. It is not a legal statement.

  .. code-block:: cpp

     std::cout << "The sum of " << v1
               << " and " << v2
               << " is " << v1 + v2 << std::endl;

7. Compile a program that has incorrectly nested comments.

  .. code-block:: cpp

      /* comment pairs /*    */ cannot nest.
       * "cannot nest" is considered source code
       * as is the rest of the program
       */
      int main()
      {
          return 0;
      }

  Compiled by g++ in Windows::

      PS C:\my\learning\C++Primer\Exercise\code\Chapter1> g++ .\1_7.cpp -Wall
      .\1_7.cpp:1:18: warning: "/*" within comment [-Wcomment]
          1 | /* comment pairs /*    */ cannot nest.
            |
      .\1_7.cpp:1:27: error: 'cannot' does not name a type
          1 | /* comment pairs /*    */ cannot nest.
            |                           ^~~~~~

8. Indicate which, if any, of the following output statements are legal::

    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */;
    std::cout << /* "*/" /*  "/*"  */;

   After you've predicted what will happen test your answers by compiling a program with each of these statements. Correct
   any errors you encounter.

  .. code-block:: cpp

     #include<iostream>

     int main()
     {
         std::cout << "/*";
         std::cout << "*/";
         //std::cout << /* "*/" */; This failed.
         std::cout << /* "*/" /*  "/*"  */;

         return 0;
     }

9. Write a program that uses  a while to sum the numbers from 50 to 100.

   .. code-block:: cpp

      #include<iostream>

      int main()
      {
          int val = 50, sum = 0;
          while (val <= 100) {
              sum += val;
              ++val;
          }
          std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

          return 0;
      }

10. In addition to the ++ operator that adds 1 to its operand, there is a decrement operator(--) that subtracts 1. Use
    the decrement operator to write a while that prints the numbers from ten down to zero.

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          int val = 10;
          while (val >= 0) {
              std::cout << val << ' ';
              --val;
          }
          std::cout << std::endl;

          return 0;
      }

11. Write a program that prompts the user for two integers. Print each number in the range specified by those two
    integers.

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          int val1, val2;
          std::cout << "Please input two numbers:" << std::endl;
          std::cin >> val1 >> val2;
          while (val1 <= val2) {
              std::cout << val1 << std::endl;
              ++val1;
          }

          return 0;
      }

12. What does the following for loop do? What is the final value of sum?

    .. code-block:: cpp

      int sum = 0;
      for (int i = -100; i <= 100; ++i)
          sum += i;

    The for loop sums the numbers from -100 to 100. The final value of sum is 0.

13. Rewrite the exercise from 1.4.1 (p. 13) using for loops.

    These three programs for 1.9、1.10、1.11, respectively

    1.9:

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          for (int i = 50; i <= 100; ++i)
              std::cout << i << std::endl;

          return 0
      }

    1.10:

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          for (int i = 10; i >= 0; --i)
              std::cout << i << std::endl;

          return 0
      }

    1.11:

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          for (int i = val1; i <= val2; ++i)
              std::cout << i << std::endl;

          return 0
      }

14. Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to
    using either form?

    There is no essential difference between "for" and "while". "for" is just a syntactic sugar for "while".

    http://www.cplusplus.com/forum/beginner/73584/


15. Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the
    messages the compiler generates.

    .. code-block:: cpp

      int main()
      {
          int a = "Hello, World";    // type error
          int b = c;                 // Declaration error
          int d:                     // Syntax error

          return 0;
      }


    Compiled by g++ in Windows Powershell::

      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> g++ -Wall .\1_15.cpp
      .\1_15.cpp: In function 'int main()':
      .\1_15.cpp:3:13: error: invalid conversion from 'const char*' to 'int' [-fpermissive]
          3 |     int a = "Hello, World";
            |             ^~~~~~~~~~~~~~
            |             |
            |             const char*
      .\1_15.cpp:4:13: error: 'c' was not declared in this scope
          4 |     int b = c;
            |             ^
      .\1_15.cpp:5:10: error: expected initializer before ':' token
          5 |     int d:
            |          ^
      .\1_15.cpp:3:9: warning: unused variable 'a' [-Wunused-variable]
          3 |     int a = "Hello, World";
            |         ^
      .\1_15.cpp:4:9: warning: unused variable 'b' [-Wunused-variable]
          4 |     int b = c;
            |         ^

16. Write your own version of a program that prints the sum of a set of integers read from ``cin``.

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          int val = 0, sum = 0;
          while (std::cin >> val)
              if (val % 2)
                  sum += val;
          std::cout << "Sum of odd numbers is " << sum << std::endl;

          return 0;
      }

17. What happens in the program presented in this section if the input values are all equal? What if there are no
    duplicated values?

    - In the case that all input values are all equal, the output will be a line that shows the number of input value.
    - In the case that there are no duplicated values, one value input and one line output with "value occurs 1 times".

18. Compile and run the program from this section giving it only equal values as input. Run it again giving it values in
    which no number is repeated.

    This is the prints in Powershell::

      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> .\a.exe
      5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 ^Z
      5 occurs 17 times
      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> .\a.exe
      1 2 3 4 5 6 7 8 9 10 ^Z
      1 occurs 1 times
      2 occurs 1 times
      3 occurs 1 times
      4 occurs 1 times
      5 occurs 1 times
      6 occurs 1 times
      7 occurs 1 times
      8 occurs 1 times
      9 occurs 1 times
      10 occurs 1 times

19. Revise the program you wrote for the exercise in 1.4.1 (p.13) that printed a range of numbers so that it handles
    input in which the first number is smaller than the second.

    .. code-block:: cpp

      #include<iostream>

      int main()
      {
          int val1 = 0, val2 = 0;
          std::cout << "Please input two numbers:" << std::endl;
          std::cin >> val1 >> val2;

          int min = 0, max = 0;
          if (val1 > val2) {
              min = val2;
              max = val1;
          } else {
              min = val1;
              max = val2;
          }

          while (min <= max) {
              std::cout << min << std::endl;
              ++min;
          }

          return 0;
      }

20. http://www.informit.com/title/0321714113 contains a copy of ``Sales_item.h`` in the Chapter 1 code directory. Copy
    that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing
    each transaction to the standard output.

    .. code-block:: cpp

      #include <iostream>
      #include "Sales_item.h"

      int main()
      {
          Sales_item book;
          while (std::cin >> book)
              std::cout << book << std::endl;

          return 0;
      }

21. Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

    .. code-block:: cpp

      #include <iostream>
      #include "Sales_item.h"

      int main()
      {
          Sales_item item1, item2;
          std::cin >> item1  >> item2;
          std::cout << item1 + item2 << std::endl;

          return 0;
      }

22. Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were
    read.

    .. code-block:: cpp

      #include <iostream>
      #include "Sales_item.h"

      int main()
      {
          Sales_item total, book;
          std::cin >> book;
          total = book;
          while (std::cin >> book)
              total += book;
          std::cout << total << std::endl;

          return 0;
      }
23. Write a program that reads several transactions and counts how many transactions occur for each ISBN.

    .. code-block:: cpp

      #include <iostream>
      #include "Sales_item.h"

      int main()
      {
          Sales_item currItem, valItem;
          if (std::cin >> currItem) {
              int cnt = 1;
              while (std::cin >> valItem) {
                  if (currItem.isbn() == valItem.isbn()) {
                      ++cnt;
                  } else {
                      std::cout << currItem.isbn() << " occurs "
                                << cnt << " times" << std::endl;
                      currItem = valItem;
                      cnt = 1;
                  }
              }
              std::cout << currItem.isbn() << " occurs "
                        << cnt << " times" << std::endl;
          }

          return 0;
      }

24. Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN
    should be grouped together.

    Test result::

      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> g++ .\1_23.cpp -Wall
      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> .\a.exe
      0-201-78345-X 3 20.00 0-201-78345-X 3 25.00
      AAAAAAAAAAAAA 4 60.00 AAAAAAAAAAAAA 4 45.00 AAAAAAAAAAAAA 5 34.22
      0-201-78345-X occurs 2 times
      BBBBB 2 34.9 BBBBB 3 23.3
      AAAAAAAAAAAAA occurs 3 times
      ^Z
      BBBBB occurs 2 times
      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1>

25. Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this
    section.


    Test result::

      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> g++ .\1_25.cpp -Wall
      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1> .\a.exe
      0-201-78345-X 3 20.00 0-201-78345-X 3 25.00
      AAAAAAAAAAAAA 4 60.00 AAAAAAAAAAAAA 4 45.00 AAAAAAAAAAAAA 5 34.22
      0-201-78345-X 6 135 22.5
      BBBBB 2 34.9 BBBBB 3 23.3
      AAAAAAAAAAAAA 13 591.1 45.4692
      ^Z
      BBBBB 5 139.7 27.94
      PS C:\my\CPP\C++Primer\Exercise\code\Chapter1>
