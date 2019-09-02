Chapter 2 Variables and basic types
====================================

1. What are the differences between ``int``, ``long``, ``long long``, and ``short``? Between an unsigned and a signed
   type? Between a float and a double?

     The standard guarantees minimum sizes between ``int``, ``long``, ``long long`` and ``short`` are various.

     A signed type represents negative of positive numbers (including 0); an unsigned type represents only values
     greater than or equal to zero. In an unsigned type, all the bits represent value; in an signed type, the range should be evenly divide between
     positive and negative values.

     For a float type and a double type, the minimum numbers of significant digits are different.

2. To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you
   selected each type.

     ``double`` should be used.

     The rate, principal and payment are usually not integer, so they should be represented by floating-point types.
     ``float`` usually does not have enough precision, and the cost of double-precision calculations versus single
     precision is negligible.

3. What output will the following code produce?

   .. code-block:: cpp

     unsigned u = 10, u2 = 42;
     std::cout << u2 - u << std::endl;    // 32
     std::cout << u - u2 << std::endl;    // if 32-bits int, 4294967264
     int i = 10, i2 = 42;
     std::cout << i2 - i << std::endl;    // 32
     std::cout << i - i2 << std::endl;    // -32
     std::cout << i - u << std::endl;     // 0
     std::cout << u - i << std::endl;     // 0

4. Write a program to check whether your predictions were correct. If not, study this section until you understand what
   the problem is.

     .. code-block:: cpp

       #include <iostream>

       int main()
       {
           unsigned u = 10, u2 = 42;
           std::cout << u2 - u << std::endl;    // 32
           std::cout << u - u2 << std::endl;    // if 32-bits int, 4294967264
           int i = 10, i2 = 42;
           std::cout << i2 - i << std::endl;    // 32
           std::cout << i - i2 << std::endl;    // -32
           std::cout << i - u << std::endl;     // 0
           std::cout << u - i << std::endl;     // 0

           return 0;
       }

     Reseult::

       PS C:\my\CPP\C++Primer\Exercise\code\Chapter2> g++ -Wall .\2_4.cpp
       PS C:\my\CPP\C++Primer\Exercise\code\Chapter2> .\a.exe
       32
       4294967264
       32
       -32
       0
       0

5. Determine the type of each of the following literals. Explain the differences among the literals in each of the four
   examples.

     a) 'a', L'a', "a", L"a"
     b) 10, 10u, 10L, 10uL, 012, 0xC
     c) 3.14, 3.14f, 3.14L
     d) 10, 10u, 10., 10e-2

     a) 'a' ---> char, L'a' ---> wchar_t, "a" ---> array of constant chars, L"a" ---> array of constant wchar_t
     b) 10 ---> int, 10u ---> unsigned, 10L ---> long, 10uL ---> unsigned long, 012 ---> int, 0xC ---> int
     c) 3.14 ---> double, 3.14f ---> float, 3.14L ---> long double
     d) 10 ---> int, 10u ---> unsigned, 10. ---> double, 10e-2 ---> double

6. What, if any, are the differences between the following definitions:

     .. code-block:: cpp

       int month = 9, day = 7;
       int month = 09, day = 07;

     The second definition is illegal, because octal digits don't contain 9.

7. What values do these literals represent? What type does each have?

     a) "Who goes with F\145rgus?\012"
     b) 3.14e1L
     c) 1024f
     d) 3.14L

     a) "Who goes with Fergus? (newline)", array of constant chars
     b) 31.4, long double
     c) The suffix "f" is only valid for floating-point literals.
     d) 3.14, long double

8. Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab,
   then an M, followed by a newline.

     The fist program

     .. code-block:: cpp

       #include <iostream>

       int main()
       {
           std::cout << "\x32\x4D\n" << std::endl;

           return 0;
       }

     The modified program

     .. code-block:: cpp

       #include <iostream>

       int main()
       {
           std::cout << "\x32\t\x4D\n" << std::endl;

           return 0;
       }

9. Explain the following definitions. For those that are illegal, explain what's wrong and how to correct it.

     a) ``std::cin >> int input_value;``
     b) ``int i = {3.14};``
     c) ``double salary = wage = 9999.99;``
     d) ``int i = 3.14;``

     a) Illegal. Because a variable must be defined before it could be used. In addition, the operator >> expects its
        right-hand operands to be variables.
        .. code-block:: cpp

          int input_value;
          std::cin >> input_value;
     b) Illegal. Narrowing conversion is not allowed by list initialization.
        ``int i = 3;`` or ``double i = 3.14``
     c) Illegal.  --> ``double salary{9999.99}, wage{salary};``
     d) Legal.

10. What are the initial value, if any, of each of the following variables?

      .. code-block:: cpp

        std::string global_str;
        int global_int;

        int main()
        {
            int local_int;
            std::string local_str;
        }

      - The value of global_int is 0.
      - The value of local_int is undefined.
      - The value of local_str is empty string (zero size and unspecified capacity)
      - The value of global_str is empty string (zero size and unspecified capacity)

      https://en.cppreference.com/w/cpp/string/basic_string/basic_string

11. Explain whether each of the following is a declaration or a definition:

      a) ``extern int ix = 1024;``
      b) ``int iy;``
      c) ``extern int iz;``

      a) A definition
      b) A definition
      c) A declaration

12. Which, if any, of the following names are invalid?

      a) ``int double = 3.14;``
      b) ``int _;``
      c) ``int catch-22;``
      d) ``int 1_or_2 = 1;``
      e) ``double Double = 3.14;``

      a. Invalid. ``double`` is one of C++ keywords.
      c. Invalid. Identifiers in C++ can be composed of letters, digits, and the underscore character; '-' is not included.
      d. Invalid. Identifiers must begin with either a letter or an underscore.

13. What is the value of j in the following program?

      .. code-block:: cpp

        int i = 42;
        int main()
        {
            int i = 100;
            int j = i;
        }

      The value of j is 100;

14. Is the following program legal? If so, what values are printed?

      .. code-block:: cpp

        int i = 100, sum = 0;
        for (int i = 0; i != 10; ++i)
            sum += i;
        std::cout << i << " " << sum << std::endl;

        The program is legal. It prints::

          100 55

15. Which of the following definitions, if any, are invalid? Why?

      a) ``int ival = 1.01;``
      b) ``int &rval1 = 1.01``
      c) ``int &rval2 = ival;``
      d) ``int &rval3;``

      b. Invalid. Initializer must be an object, not a literal.
      d. A reference must be initialized.

16. Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
    ``int i = 0, &r1 = i; double d = 0, &r2 d;``

      a) ``r2 = 3.14159;``
      b) ``r2 = r1;``
      c) ``i = r2;``
      d) ``r1 = d;``

      a. Valid. It assigns 3.14159 to d
      b. Valid. It assigns the value of i to d;
      c. Valid. It assigns the value of d to i;
      d. Valid. It assigns the value of d to i;

17. What does the following code print?

      .. code-block:: cpp

        int i, &ri = i;
        i = 5; ri = 10;
        std::cout << i << " " << ri << std::endl;

        It prints::

          10 10

18. Write code to change the value of a pointer. Write code to change the value to which the pointer points.

      .. code-block:: cpp

        int main()
        {
            int a = 0, *p = nullptr;
            p = &a;  // Change the value of a pointer
            *p = 100; // Change the value to which the pointer points

            return 0;
        }

19. Explain the key difference between pointers and references.

      A pointer is a variable that holds memory address of another variable.

      A reference variable is an alias, that is, another name for an already existing variable.

      https://www.geeksforgeeks.org/pointers-vs-references-cpp/
      https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
      https://techdifferences.com/difference-between-pointer-and-reference-2.html
      https://www.educba.com/c-plus-plus-reference-vs-pointer/
      https://www.quora.com/What-are-the-differences-between-references-and-pointers-in-coding

20. What does the following program do?

      .. code-block:: cpp

         int i = 42;
         int *p1 = &i;
         *p1 = *p1 * *p1;

      It calculate 42 * 42 and assign it to , i;

21. Explain each of the following definitions. Indicate whether any are illegal and, if so, why.

      ``int i = 0;``

      a) ``double * dp = &i;``
      b) ``int *ip = i;``
      c) ``int *p = &i;``

      a. Illegal. The types of the pointer and the object to which it points must match.
      b. Illegal. It's illegal to assign an int variable to a pointer.
      c. Legal.

22. Assuming p is a pointer to int, explain the following code.

      ``if (p) // ...``

      ``if (*p) // ...``

      ``if (p)`` evaluates whether the pointer p is a nonzero pointer or not.

      ``if (*p)`` evaluates whether the value of the int object that p points to is zero or not.

23. Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

      To determine whether p points to a valid object, we need more information.

24. Why is the initialization of p legal but that of lp illegal?

      .. code-block:: cpp

        int i = 42;        void *p = &i;        long *lp = &i;

      The types of the pointer and the object to which it points must match. lp is a pointer points long, i has type int.
      So, it is illegal.

      The type void* is a special pointer type that can hold the address of any object.

25. Determine the types and values of each of the following variables.

      a) ``int* ip, i, &r = i;``
      b) ``int i, *p = 0;``
      c) ``int* ip, ip2;``

      a. ip is a pointer to an int, i is an int, r is a reference to an int.
      b. i is an int, p is a pointer to an int and its value is 0.
      c. ip is a pointer to an int, ip2 is an int.

26. Which of the following are legal? For those that are illegal, explain why?

      a) ``const int buf;``
      b) ``int cnt = 0;``
      c) ``const int sz = cnt;``
      d) ``++cnt; ++sz``

      The exercise is very confusing, since it doesn't specify whether the for statements are belong to a program or not.
      If not, it's meaningless for c and d. So I just assume that they are sequentially.

      a. Illegal. A const object must be initialized.
      b. Legal
      c. It will be legal if buf was initialized.
      d. ``++cnt;`` is legal. ``++sz;`` is illegal: the value of a const object can't be changed.

27. Which of the following initializations are legal? Explain why.

      a) ``int i = -1, &r = 0;``
      b) ``int *const p2 = &i2;``
      c) ``const int i = -1, &r = 0;``
      d) ``const int *const p3 = &i2;``
      e) ``const int *p1 = &i2;``
      f) ``const int &const r2;``
      g) ``const int i2 = i, &r = i;``

      This exercise is quite ambiguous due to the type of i2 is unknown.

      ``int i2 = 0`` is assumed.

      a. Illegal. r is a plain, nonconst reference.
      b. Legal.
      c. Legal.
      d. Legal.
      e. Legal.
      f. Illegal. An reference must be initialized; the second const is redundant.
      g. Legal.

28. Explain the following definitions. Identify any that are illegal.

      a) ``int i, *const cp;``
      b) ``int *p1, *const p2;``
      c) ``const int ic, &r = ic;``
      d) ``const int *const p3;``
      e) ``const int *p;``

      a. Illegal. cp is a const pointer point to an int. An const must be initialized.
      b. Illegal with the same reason with list item a.
      c. Illegal. ic must be initialized.
      d. Illegal. p3 is a const pointer point to an const that is an int.
      e. Legal. p is a pointer point to a const that is a int.

29. Using the variable in the previous exercise, which of the following assignments are legal? Explain why.

      a) ``i = ic;``
      b) ``p1 = p3;``
      c) ``p1 = &ic;``
      d) ``p3 = &ic;``
      e) ``p2 = p1;``
      f) ``ic = *p3;``

      a. Legal.
      b. Illegal. p3 has low-level const, but p1 doesn't
      c. Illegal. p1 is a plain pointer while ic is a const int.
      d. Illegal. p3 is a const. An const can't be assigned.
      e. Illegal. p2 is a const. An const can't be assigned.
      f. Illegal. ic is a const. An const can't be asiigned.

30. For each of the following declarations indicate whether the object being declared has top-level or low-level const.

      .. code-block:: cpp

        const int v2 = 0; int v1 = v2;
        int *p1 = &v1, &r1 = v1;
        const int *p2 = &v2, *const p3 = &i, &r2 = v2;


      v2 and p3 has top-level const; p2, r2 and p3 has low-level const.

31. Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how
    the top-level or low-level const applies in each case.

      .. code-block:: cpp

        r1 = v2;
        p1 = p2;        p2 = p1;
        p1 = p3;        p2 = p3;

      - ``r1 = v2`` is legal.
      - ``p1 = p2`` is illegal because p1 is a pointer pointe to a plain int while p2 is a pointer point to a const int.
      - ``p2 = p1`` is legal.
      - ``p1 = p3`` is illegal with same reason with ``p1 = p2``.
      - ``p2 = p3`` is legal.

32. Is the following code legal or not? If not, how might you make it legal?

      ``int null = 0, *p = null;``

      It is illegal to assign an int variable to a pointer. It can be written as ``int null = 0, *p = nullptr;``

33. Using the variable definitions from this section, determine what happens in each of these assignments.

      .. code-block:: cpp

        a = 42; b = 42; c = 42;
        d = 42; e = 42; g = 42;

      - a was assigned with value 42.
      - b was assigned with value 42.
      - c was assigned with value 42.
      - Illegal. d is an int \*. It's illegal to assign an int variable to a pointer.
      - Illegal. e is a const int \*. It's illegal to assign an int variable to a pointer.
      - g is a const int &. It's illegal to assign to a const.

34. Write a program containing the variables and assignments from the previous exercise. Print the variables before and
    after the assignments to check whether your predictions in the previous exercise were correct. If not, study the
    examples until you can convince yourself you know what led you to the wrong conclusion.

      .. code-block:: cpp

        #include <iostream>

        int main()
        {
            int i = 0, &r = i;
            const int ci = i, &cr = ci;

            auto a = r; // a is an int (r is an alias for i, which has type int)
            auto b = ci; // b is an int (top-level const in ci is dropped)
            auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
            auto d = &i; // d is an int *
            auto e = &ci; // e is an const int * ??
            const auto f = ci;
            auto &g = ci; // g is a const int &
            auto &h = 42;
            const auto &j = 42;
            auto k = ci, &l = i;
            auto &m = ci, *p = &ci;
            //auto &n = i, *p2 = &ci;

            std::cout << "a = " << a << '\n'
                      << "b = " << b << '\n'
                      << "c = " << c << '\n'
                      << "d = " << d << '\n'
                      << "e = " << e << '\n'
                      << "f = " << f << '\n'
                      << "g = " << g << '\n'
                      // << "h = " << h << '\n'
                      << "i = " << i << '\n'
                      << "j = " << j << '\n'
                      << "k = " << k << '\n'
                      << "l = " << l << '\n'
                      << "m = " << m << '\n'
                      // << "n = " << n << '\n'
                      << "p = " << p << std::endl;
            a = 42;
            b = 42;
            c = 42;
            // d = 42;
            // e = 42;
            // f = 42;
            // g = 42;

            std::cout << "a = " << a << '\n'
                      << "b = " << b << '\n'
                      << "c = " << c << '\n'
                      << "d = " << d << '\n'
                      << "e = " << e << '\n'
                      << "f = " << f << '\n'
                      << "g = " << g << '\n'
                      // << "h = " << h << '\n'
                      << "i = " << i << '\n'
                      << "j = " << j << '\n'
                      << "k = " << k << '\n'
                      << "l = " << l << '\n'
                      << "m = " << m << '\n'
                      // << "n = " << n << '\n'
                      << "p = " << p << std::endl

            return 0;
        }

35. Determine the types deduced in each of the following definitions. Once you've figured out the types, write a program
    to see whether you were correct.

      .. code-block:: cpp

        const int i = 42;
        auto j = i; const auto &k = i; auto *p = &i;
        const auto j2 = i, &k2 = i;

      - j is an int
      - k is a const int &
      - p is a const int *
      - j2 is a const int
      - k2 is a const int &

36. In the following code, determine the type of each variable and the value each variable has when the code finishes.

      .. code-block:: cpp

        int a = 3, b = 4;
        decltype(a) c = a;
        decltype ( (b) ) d = a;
        ++c;
        ++d;

      - a = 4; a is an int.
      - b = 4; b is an int.
      - c = 4; c is an int.
      - d = 4; d is an reference to a.

37. Assignment is an example of an expression that yields a reference type. The type is an reference to the type of
    left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowlege,
    determine the type and value of each variable in this code:

      .. code-block:: cpp

        int a = 3, b = 4;
        decltype(a) c = a;
        decltype(a = b) d = a;

      There is one important thing is that expression is not executed.
      https://stackoverflow.com/questions/17241614/what-expressions-yield-a-reference-type-when-decltype-is-applied-to-them

      - a = 3; a is an int;
      - b = 4; b is an int;
      - c = 3; c is an int;
      - d = 3; d is an int&;

38. Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto
    and decltype will deduce the same type and an example where they will deduce differing types.

      1. The variable defined by auto must be initialized; it wasn't needed while use decltype;
      2. deduction done by decltype depends on the form of its given expression. decltype ( (variable) ) is always a
         reference type, but decltype (variable) is a reference type only if variable is a reference.
      3. The way decltype handles top-level const and reference is different. When the expression to which we are apply
         decltype is a variable, decltype returns the type of that variable, including top-level const and reference.
      4. When used to an expression that is not a variable and yield objects that can stand on that can stand on the
         left-hand of side the assignment, decltype returns a reference type but auto returns the plain type.

      .. code-block:: cpp

        int a = 10, b = 42;
        auto c = (a = b);         // c is an int;
        decltype(a = b) d = a;    // d is an int&

39. Compile the following program to see what happens when you forget the semicolon after a class denition. Remember the
    message for future reference.

      .. code-block:: cpp

        struct Foo { /* empty */ } // Note: no semicolon
        int main()
        {
            return 0;
        }

      The compile result::

        PS C:\my\CPP\C++Primer\Exercise\code\Chapter2> g++ .\2_39.cpp -Wall
        .\2_39.cpp:1:27: error: expected ';' after struct definition
            1 | struct Foo { /* empty */ } // Note: no semicolon
              |                           ^
              |                           ;
        PS C:\my\CPP\C++Primer\Exercise\code\Chapter2>

40. Write your own version of the Sales_data class.

    .. code-block:: cpp

      struct Sales_data {
          std::string bookNo;
          unsigned units_sold = 0;
          double revenue = 0.0;
          double profit = 0.0;
      };

41. Use your Sales_data class to rewrite the exercise in 1.5.1 (p.22), 1.5.2(p.24), and 1.6(p.25). For now you should
    define your Sales_data class in the same file as your main function.

      For exercise 1.20

      .. code-block:: cpp

        #include <iostream>
        #include <string>

        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
            double profit = 0.0;
        };

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data data;
            while (std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
                data.revenue = data.units_sold * price;
                data.profit = data.units_sold * (price - purchasePrice);
                std::cout << data.bookNo << " "
                          << data.units_sold << " "
                          << data.revenue << " ";
                if (data.units_sold)
                    std::cout << data.revenue / data.units_sold << " ";
                else
                    std::cout << 0 << " ";
                std::cout << data.profit << std::endl;
            }

            return 0;
        }

      For exercise 1.21:

      .. code-block:: cpp

        #include <iostream>
        #include <string>

        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
            double profit = 0.0;
        };

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data data1, data2;
            std::cin >> data1.bookNo >> data1.units_sold >> price >> purchasePrice;
            data1.revenue = data1.units_sold * price;
            data1.profit = data1.units_sold * (price - purchasePrice);
            std::cin >> data2.bookNo >> data2.units_sold >> price >> purchasePrice;
            data2.revenue = data2.units_sold * price;
            data2.profit = data2.units_sold * (price - purchasePrice);

            if (data1.bookNo == data2.bookNo) {
                unsigned totalCnt = data1.units_sold + data2.units_sold;
                double totalRevenue = data1.revenue + data2.revenue;
                double totalProfit = data1.profit + data2.profit;
                std::cout << data1.bookNo << " "
                          << totalCnt << " "
                          << totalRevenue << " ";
                if (totalCnt != 0)
                    std::cout << totalRevenue / totalCnt << " ";
                else
                    std::cout << "(no sales)" << " ";

                std::cout << totalProfit << std::endl;

                return 0;
            } else {
                std::cerr << "Data must refer to the same ISBN" << std::endl;

                return -1;
            }
        }

      For exercise 1.22

      .. code-block:: cpp

        #include <iostream>
        #include <string>

        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
            double profit = 0.0;
        };

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data total, data;
            std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice;
            data.revenue = data.units_sold * price;
            data.profit = data.units_sold * (price - purchasePrice);
            total = data;
            while (std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
                data.revenue = data.units_sold * price;
                data.profit = data.units_sold * (price - purchasePrice);
                if (total.bookNo == data.bookNo) {
                    total.units_sold += data.units_sold;
                    total.revenue += data.revenue;
                    total.profit += data.profit;
                } else {
                    std::cerr << "Data must refer to the same ISBN" << std::endl;
                    break;
                }
            }

            std::cout << total.bookNo << " "
                      << total.units_sold << " "
                      << total.revenue << " ";
            if (total.units_sold != 0)
                std::cout << total.revenue / total.units_sold << " ";
            else
                std::cout << "(no sales)" << " ";

            std::cout << total.profit << std::endl;

            return 0;
        }

      For exercise 1.23

      .. code-block:: cpp

        #include <iostream>
        #include <string>

        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
            double profit = 0.0;
        };

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data currData, valData;
            if (std::cin >> currData.bookNo >> currData.units_sold >> price >> purchasePrice) {
                currData.revenue = currData.units_sold * price;
                currData.profit = currData.units_sold * (price - purchasePrice);
                unsigned cnt = 1;
                while (std::cin >> valData.bookNo >> valData.units_sold >> price >> purchasePrice) {
                    valData.revenue = valData.units_sold * price;
                    valData.profit = valData.units_sold * (price - purchasePrice);
                    if (currData.bookNo == valData.bookNo) {
                        ++cnt;
                    } else {
                        std::cout << currData.bookNo << " occurs "
                                  << cnt << " times" << std::endl;
                    }
                }
                std::cout << currData.bookNo << " occurs "
                          << cnt << " times" << std::endl;
            }

            return 0;
        }

      For exercise 1.25

      .. code-block:: cpp

        #include <iostream>
        #include <string>

        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
            double profit = 0.0;
        };

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data total;
            if (std::cin >> total.bookNo >> total.units_sold >> price >> purchasePrice) {
                total.revenue = total.units_sold * price;
                total.profit = total.units_sold * (price - purchasePrice);
                Sales_data trans;
                while (std::cin >> trans.bookNo >> trans.units_sold >> price >> purchasePrice) {
                    trans.revenue = trans.units_sold * price;
                    trans.profit = trans.units_sold * (price - purchasePrice);
                    if (total.bookNo == trans.bookNo) {
                        total.units_sold += trans.units_sold;
                        total.revenue += trans.revenue;
                        total.profit += trans.profit;
                    } else {
                        std::cout << total.bookNo << " "
                                  << total.units_sold << " "
                                  << total.revenue << " ";
                        if (total.units_sold != 0)
                            std::cout << total.revenue / total.units_sold << " ";
                        else
                            std::cout << "(no sales)" << " ";

                        std::cout << total.profit << std::endl;
                    }
                }
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << " ";
                else
                    std::cout << "(no sales)" << " ";

                std::cout << total.profit << std::endl;
            } else {
                std::cerr << "No data?!" << std::endl;
            }

            return 0;
        }

42. Write your own version of the Sales_data.h header and use it to rewrite the exercise from 2.62(p.76).

      Sales_data.h

      .. code-block:: cpp

        #ifndef SALES_DATA_H
        #define SALES_DATA_H

        #include <string>

        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
            double profit = 0.0;
        };

        #endif

      For exercise 1.20

      .. code-block:: cpp

        #include <iostream>
        #include "Sales_data.h"

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data data;
            while (std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
                data.revenue = data.units_sold * price;
                data.profit = data.units_sold * (price - purchasePrice);
                std::cout << data.bookNo << " "
                          << data.units_sold << " "
                          << data.revenue << " ";
                if (data.units_sold)
                    std::cout << data.revenue / data.units_sold << " ";
                else
                    std::cout << 0 << " ";
                std::cout << data.profit << std::endl;
            }

            return 0;
        }

      For exercise 1.21:

      .. code-block:: cpp

        #include <iostream>
        #include "Sales_data.h"

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data data1, data2;
            std::cin >> data1.bookNo >> data1.units_sold >> price >> purchasePrice;
            data1.revenue = data1.units_sold * price;
            data1.profit = data1.units_sold * (price - purchasePrice);
            std::cin >> data2.bookNo >> data2.units_sold >> price >> purchasePrice;
            data2.revenue = data2.units_sold * price;
            data2.profit = data2.units_sold * (price - purchasePrice);

            if (data1.bookNo == data2.bookNo) {
                unsigned totalCnt = data1.units_sold + data2.units_sold;
                double totalRevenue = data1.revenue + data2.revenue;
                double totalProfit = data1.profit + data2.profit;
                std::cout << data1.bookNo << " "
                          << totalCnt << " "
                          << totalRevenue << " ";
                if (totalCnt != 0)
                    std::cout << totalRevenue / totalCnt << " ";
                else
                    std::cout << "(no sales)" << " ";

                std::cout << totalProfit << std::endl;

                return 0;
            } else {
                std::cerr << "Data must refer to the same ISBN" << std::endl;

                return -1;
            }
        }

      For exercise 1.22

      .. code-block:: cpp

        #include <iostream>
        #include "Sales_data.h"

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data total, data;
            std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice;
            data.revenue = data.units_sold * price;
            data.profit = data.units_sold * (price - purchasePrice);
            total = data;
            while (std::cin >> data.bookNo >> data.units_sold >> price >> purchasePrice) {
                data.revenue = data.units_sold * price;
                data.profit = data.units_sold * (price - purchasePrice);
                if (total.bookNo == data.bookNo) {
                    total.units_sold += data.units_sold;
                    total.revenue += data.revenue;
                    total.profit += data.profit;
                } else {
                    std::cerr << "Data must refer to the same ISBN" << std::endl;
                    break;
                }
            }

            std::cout << total.bookNo << " "
                      << total.units_sold << " "
                      << total.revenue << " ";
            if (total.units_sold != 0)
                std::cout << total.revenue / total.units_sold << " ";
            else
                std::cout << "(no sales)" << " ";

            std::cout << total.profit << std::endl;

            return 0;
        }

      For exercise 1.23

      .. code-block:: cpp

        #include <iostream>
        #include "Sales_data.h"

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data currData, valData;
            if (std::cin >> currData.bookNo >> currData.units_sold >> price >> purchasePrice) {
                currData.revenue = currData.units_sold * price;
                currData.profit = currData.units_sold * (price - purchasePrice);
                unsigned cnt = 1;
                while (std::cin >> valData.bookNo >> valData.units_sold >> price >> purchasePrice) {
                    valData.revenue = valData.units_sold * price;
                    valData.profit = valData.units_sold * (price - purchasePrice);
                    if (currData.bookNo == valData.bookNo) {
                        ++cnt;
                    } else {
                        std::cout << currData.bookNo << " occurs "
                                  << cnt << " times" << std::endl;
                    }
                }
                std::cout << currData.bookNo << " occurs "
                          << cnt << " times" << std::endl;
            }

            return 0;
        }

      For exercise 1.25

      .. code-block:: cpp

        #include <iostream>
        #include "Sales_data.h"

        int main()
        {
            double price{0.0}, purchasePrice{0.0};
            Sales_data total;
            if (std::cin >> total.bookNo >> total.units_sold >> price >> purchasePrice) {
                total.revenue = total.units_sold * price;
                total.profit = total.units_sold * (price - purchasePrice);
                Sales_data trans;
                while (std::cin >> trans.bookNo >> trans.units_sold >> price >> purchasePrice) {
                    trans.revenue = trans.units_sold * price;
                    trans.profit = trans.units_sold * (price - purchasePrice);
                    if (total.bookNo == trans.bookNo) {
                        total.units_sold += trans.units_sold;
                        total.revenue += trans.revenue;
                        total.profit += trans.profit;
                    } else {
                        std::cout << total.bookNo << " "
                                  << total.units_sold << " "
                                  << total.revenue << " ";
                        if (total.units_sold != 0)
                            std::cout << total.revenue / total.units_sold << " ";
                        else
                            std::cout << "(no sales)" << " ";

                        std::cout << total.profit << std::endl;
                    }
                }
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << " ";
                else
                    std::cout << "(no sales)" << " ";

                std::cout << total.profit << std::endl;
            } else {
                std::cerr << "No data?!" << std::endl;
            }

            return 0;
        }
