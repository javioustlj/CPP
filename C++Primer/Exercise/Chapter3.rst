.. hightlignt:: cpp

Chapter 3 Strings, Vectors, And Arrays
=========================================

1. Rewrite the exercise from 1.41(p.13) and 2.62(p.76) with appropriate using declarations.

     For exercise 1.9:

     .. literalinclude:: code/Chapter3/3_1/1_9.cpp
        :language: cpp

     For exercise 1.10:

     .. literalinclude:: code/Chapter3/3_1/1_10.cpp
        :language: cpp

     For exercise 1.11:

     .. literalinclude:: code/Chapter3/3_1/1_11.cpp
        :language: cpp

     For exercise 1.20:

     .. literalinclude:: code/Chapter3/3_1/1_20.cpp
        :language: cpp

     For exercise 1.21:

     .. literalinclude:: code/Chapter3/3_1/1_21.cpp
        :language: cpp

     For exercise 1.22:

     .. literalinclude:: code/Chapter3/3_1/1_22.cpp
        :language: cpp

     For exercise 1.23:

     .. literalinclude:: code/Chapter3/3_1/1_23.cpp
        :language: cpp

     For exercise 1.25:

     .. literalinclude:: code/Chapter3/3_1/1_25.cpp
        :language: cpp

2. Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

     A program to read the standard input a line::

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s;
           getline(std::cin, s);

           return 0;
       }

    A program to read the standard input a word::

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s;
           std::cin >> s;

           return 0;
       }

3. Explain how white space characters are handled in the ``string`` input operator and in the ``getline`` function.

     The string input operator discards any leading whitespace and then reads characters until the next whitespace
     character encounter.

     The getline function won't ignore the whitespace in input.

4. Write a program to read two strings and report whether the strings are equal. If not, report which of the two is
   larger. Now, change the program to report whether the ``string`` have the same length, and if not, report which is
   longer.

     A program to report whether the strings are equal::

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s1, s2;
           std::cin >> s1 >> s2;

           if (s1 == s2)
               std::cout << "The two strings are equal!" << std::endl;
           else
               std::cout << "The larger string is " << (s1 > s2 ? s1 : s2) << std::endl;

           return 0;
       }

     A program to report whether the strings size are equal::

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s1, s2;
           std::cin >> s1 >> s2;

           if (s1.size() == s2.size())
               std::cout << "The length of two strings are equal!" << std::endl;
           else
               std::cout << "The longer string is "
                         << (s1.size() > s2.size() ? s1 : s2) << std::endl;

           return 0;
       }

5. Write a program to read strings from the standard input, concatenating what is read into one large string. Print
   the concatenated string. Next, change the program to separate adjacent input strings by a space.

     The program of version 1:

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string concatenation, s;
           while (std::cin >> s)
               concatenation += s;
           std::cout << "The concatenated string is: " << concatenation << std::endl;

           return 0;
       }

     The program of version 2:

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string concatenation, s;
           std::cin >> concatenation;
           while (std::cin >> s)
               concatenation += ' ' + s;
           std::cout << "The concatenated string is: " << concatenation << std::endl;

           return 0;
       }

6. Use a range for to change all the characters in a string to X.

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s{"Hello World!"};
           for (auto &c : s)
               c = 'X';
           std::cout << s << std::endl;

           return 0;
       }

7. What would happen if you define the loop control variable in the previous exercise as type char? Predict the results
   and then change your program to use a char to see if you were right.

     The result is same with the previous exercise.

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s{"Hello World!"};
           for (char &c : s)
               c = 'X';
           std::cout << s << std::endl;

           return 0;
       }

8. Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the
   three approaches do you prefer and why?

     I have no bias for these three approaches. Each is suitable for different situation. For this situation,
     range-based for loop is most suitable.

     A program that used traditional for

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s{"Hello World!"};
           for (std::string::size_type index = 0; index != s.size(); ++index)
               s[index] = 'X';
           std::cout << s << std::endl;

           return 0;
       }

     A program that use while:

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s{"Hello World!"};
           std::string::size_type index{0};
           while(index != s.size()) {
               s[index] = 'X';
               ++index;
           }
           std::cout << s << std::endl;

           return 0;
       }


9. What does the following program do? Is it valid? If not, why not?
     ::

       string s;
       cout << s[0] << endl;

     It try to output the first character of s. But it's invalid, because s is empty. Using an out-of-range subscript is
     undefined.

#. Write a program that reads a string of characters including punctuation and writes what was read but with the
   punctuation removed.

     .. code-block:: cpp

       #include <iostream>
       #include <string>

       int main()
       {
           std::string s;
           std::cin >> s;
           for (auto c : s)
               if (!ispunct(c))
                   std::cout << c;
           std::cout << std::endl;

           return 0;
       }

#. Is the following range for legal? If so, what's the type of c?
     ::

       const string s = "Keep out!";
       for (auto &c : s) { /* ... */ }

     The type of c is const char &. The code will be legal if it won't change the value that c refers to.

12. Which, if any, of the following ``vector`` definitions are in error? For those that are legal, explain what the
    definition does. For those that are not legal, explain why they are illegal.

      a. ``vector<vector<int>> ivec;``
      b. ``vector<string> svec = ivec;``
      c. ``vector<string> svec(10, "null");``

      a. Legal. Vector whose elements are vectors that hold strings.
      b. Illegal. svec holds strings, not int.
      c. Legal. svec holds ten strings, each element is "null".

13. How many elements are there in each of the following vectors? What are the values of the elements?

      a. ``vector<int> v1;``
      b. ``vector<int> v2(10);``
      c. ``vector<int> v3(10, 42);``
      d. ``vector<int> v4{10};``
      e. ``vector<int> v5{10, 42};``
      f. ``vector<string> v6{10};``
      g. ``vector<string> v7{10, "hi"}``

      a. 0 elements.
      b. 10 elements, each value is 0;
      c. 10 elements, each value is 42;
      d. 1 element, its value is 10;
      e. 2 elements, the values is 10 and 42;
      f. 10 elements, 10 empty strings.
      g. 10 elements, each is "hi".

14. Write a program to read a sequence of ints from cin and store those values in a vector.

      .. code-block:: cpp

        #include <iostream>
        #include <vector>

        int main()
        {
            int i;
            std::vector<int> v;
            while (std::cin >> i)
                v.push_back(i);

            return 0;
        }

15. Repeat the previous program but read strings this time.

      .. code-block:: cpp

        #include <iostream>
        #include <vector>
        #include <string>

        int main()
        {
            std::string s;
            std::vector<std::string> v;
            while (std::cin >> s)
                v.push_back(s);

            return 0;
        }

16. Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that
    exercise were correct. If not, restudy 3.3.1(p.97) until you understand you were wrong.

      .. code-block:: cpp

        #include <iostream>
        #include <string>
        #include <vector>

        void printVector(const std::vector<int> &v)
        {
            for (const auto &i : v)
                std::cout << i << " ";
            std::cout << std::endl;
        }

        void printVector(const std::vector<std::string> &v)
        {
            for (const auto &s : v)
                std::cout << s << " ";
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

      The result is::

        PS C:\my\CPP\C++Primer\Exercise\code\Chapter3> g++ -Wall .\3_16.cpp
        PS C:\my\CPP\C++Primer\Exercise\code\Chapter3> .\a.exe
        v1:

        v2:
        0 0 0 0 0 0 0 0 0 0
        v3:
        42 42 42 42 42 42 42 42 42 42
        v4:
        10
        v5:
        10 42
        v6:

        v7:
        hi hi hi hi hi hi hi hi hi hi
        PS C:\my\CPP\C++Primer\Exercise\code\Chapter3>

17. Read a sequence of words from cin and store the values a vector. After you have read all the words, process the
    vector and change each word to uppercase. Print the transformed elements, eight words to a line.

      .. code-block:: cpp

        #include <iostream>
        #include <vector>
        #include <string>

        int main()
        {
            std::string s;
            std::vector<std::string> v;
            while (std::cin >> s)
                v.push_back(s);
            for (auto &s : v)
                for (auto &c : s)
                    c = std::toupper(c);
            unsigned cnt{ };
            for (auto &s : v)
                std::cout << s << (++cnt % 8 ? ' ' : '\n');
            std::cout << std::endl;

            return 0;
        }

18. Is the following program legal? If not, how might you fix it?

      .. code-block:: cpp

        vector<int> ivec;
        ivec[0] = 42;

      Illegal. It could be write as this::

        vector<int> ivec{42};

19. List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a
    preferred way to do so and why.

      - ``vector<int> v1{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};``
      - ``vector<int> v2(10, 42);``
      - Third way:

          .. code-block:: cpp

            vector<int> v3;``
            for (int i = 0; i != 10; ++i)
               v3.push_back(42);

      Second way is preferred. In this situation, it's easiest to do so.


20. Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that
    it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

      The first program:

      .. code-block:: cpp

        #include <iostream>
        #include <vector>

        int main()
        {
            std::vector<int> v;
            int i;
            while (std::cin >> i)
                v.push_back(i);
            for (decltype(v.size()) i = 0; i < v.size(); i += 2) {
                if (i + 1 < v.size())
                    std::cout << v[i] + v[i + 1] << " ";
                else
                    std::cout << v[i];
            }
            std::cout << std::endl;

            return 0;
        }

      The second program:

      .. code-block:: cpp

        #include <iostream>
        #include <vector>

        int main()
        {
            std::vector<int> v;
            int i;
            while (std::cin >> i)
                v.push_back(i);
            for (decltype(v.size()) i = 0; i < v.size(); i += 2) {
                if (i + 1 < v.size())
                    std::cout << v[i] + v[i + 1] << " ";
                else
                    std::cout << v[i];
            }
            std::cout << std::endl;

            return 0;
        }

21. Redo the first exercise from 3.3.3(p.105) using iterators.

      .. code-block:: cpp

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

22. Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to
    the first paragraph to all uppercase. After you've updated text, print its contents.

      .. code-block:: cpp

        for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
            for (auto sit = it->begin(); sit != it->end(); ++sit)
                *sit = toupper(*sit);
        for (auto it = text.cbegin(); it != text.end() && !it->empty(); ++it)
            cout << *it << endl;

23. Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is
    twice its current value. Test your program by printing the vector.

      .. code-block:: cpp

        #include <iostream>
        #include <vector>

        int main()
        {
            std::vector<int> v(10, 8);
            for (auto it = v.begin(); it != v.end(); ++it)
                *it += *it;
            for (const auto &i : v)
                std::cout << i << " ";
            std::cout << std::endl;

            return 0;
        }

24. Redo the last exercise from 3.3.3(p.105) using iterators.

    .. code-block:: cpp

      #include <iostream>
      #include <vector>

      int main()
      {
          std::vector<int> v;
          int i;
          while (std::cin >> i)
              v.push_back(i);
          for (auto it = v.cbegin(); it < v.cend(); it += 2) {
              if (it + 1 != v.cend())
                  std::cout << *it + *(it + 1) << " ";
              else
                  std::cout << *it;
          }
          std::cout << std::endl;

          return 0;
      }

    .. code-block:: cpp

      #include <iostream>
      #include <vector>

      int main()
      {
          std::vector<int> v;
          int i;
          while (std::cin >> i)
              v.push_back(i);
          for (auto lit = v.cbegin(), rit = v.cend() - 1; lit < rit; ++lit, --rit)
              std::cout << *lit + *rit << " ";
          std::cout << std::endl;

          return 0;
      }

25. Rewrite the grade clustering program from 3.3.3(p.104) using iterators instead of subscripts.

      .. code-block:: cpp

        vector<unsigned> scores(11, 0);
        unsigned grade;
        while (std::cin >> grade) {
            if (grade <= 100)
                ++*(scores.begin() + grade / 10);
        }

26. In the binary search program on page 112, why did we write mid = beg + (end - beg) / 2; instead of
    mid = (beg + end) / 2;?

      It's not defined that adding an iterator to another iterator. We can add (or subtract) an integral value and an
      iterator. end - beg returns a number; so we could add beg + (end -beg) / 2.

27. Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions
    are illegal? Explain why.

      ``unsigned buf_size = 1024;``

      a. int ia[buf_size];
      b. int ia[4 * 7 - 14];
      c. int ia[txt_size()];
      d. char st[11] = "fundamental";

      a. Illegal.
      b. Legal.
      c. Illegal. The reason is below:
      d. Illegal. No space for the null.

      There are lots of copies of solution to C++ Primer exercises. Many of them think that option a is illegal, but it
      should be legal since buf_size is defined preceded. For option c, it's legal in C language (C99 or newer); C++
      standard doesn't support VLA. But g++ and clang do support this as an extension to C++.

      https://www.quora.com/Does-the-following-code-in-C++-allocate-array-at-run-time-or-at-compile-time

28. What are the values in the following arrays?

      .. code-block:: cpp

        string sa[10];
        int ia[10];
        int mani()
        {
            string sa2[10];
            int    ia2[10];
        }

      - Each element of sa has value empty string
      - Each element of ia has value 0
      - Each element of sa2 has value empty string
      - Each element of ia2 has undefined value.

29. List some of the drawbacks of using an array instead of a vector.

      - Less flexible.

30. Identify the indexing errors in the following code:

      .. code-block:: cpp

        constexpr size_t array_size = 10;
        int ia[array_size];
        for (size_t ix = 1; ix <= array_size; ++ix)
            ia[ix] = ix;

      Index of arras starts from 0, not 1. It should be write like this.

      .. code-block:: cpp

        constexpr size_t array_size = 10;
        int ia[array_size];
        for (size_t ix = 0; ix < array_size; ++ix)
            ia[ix] = ix;


31. Write a program to define an array of ten ints. Give each element the same value as its position in the array.

      .. code-block:: cpp

        int main()
        {
            int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

            return 0;
        }

32. Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.

      A program to copy an array:

      .. code-block:: cpp

        #include<cstddef>

        int main()
        {
            int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            int ib[10] = { };
            for (std::size_t i = 0; i != 10; ++i)
                ib[i] = ia[i];

            return 0;
        }

      A program to copy a vector:

      .. code-block:: cpp

        #include <vector>

        int main()
        {
            std::vector<int> va{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            std::vector<int> vb = va;

            return 0;
        }

33. What would happen if we did not initialize the scores array in the program on page 116?

      It would cause undefined output.

34. Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or
    p2 that make this code illegal?

      ``p1 += p2 - p1;``

      It will make p1 points to the element that p2 points 2. p1 will be equal to p2.

      If p1 and p2 point to elements in the same array, it won't be illegal.

35. Using pointers, write a program to set the elements in an array to zero.

      .. code-block:: cpp

        #include <iostream>
        #include <iterator>

        int main()
        {
            int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (int *pbeg = std::begin(ia); pbeg != std::end(ia); ++pbeg)
                *pbeg = 0;
            for (const auto &i : ia)
                std::cout << i << " ";
            std::cout << std::endl;

            return 0;
        }

36. Write a program to compare two arrays for equality. Write a similar program to compare two vectors.

      The element types of two array must be same to compare for equality. So do the vectors.

      A program to compare two arrays:

      .. code-block:: cpp

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

      A program to compare two vectors:

      .. code-block:: cpp

        #include <iostream>
        #include <vector>

        int main()
        {
            std::vector<int> iva(10, 0);
            std::vector<int> ivb(10, 1);
            std::cout << (iva == ivb) << std::endl;

            return 0;
        }

37. What does the following program do?

      .. code-block:: cpp

        const char ca[] = {'h', 'e', 'l', 'l', 'o'};
        const char *cp = ca;
        while (*cp) {
            cout << *cp << endl;
            ++cp;
        }

      It tries to tranverse the character array, but it will access memory illegally. ca has no null character, so the
      while loop won't stop until it encounter a null character.

38. In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding
    two pointers be meaningless?

      A pointer holds the address of the object that it point to. When adding two pointers, we would get a new address,
      which is undefined. We don't know what's stored in this new address. Accessing such memory may cause fatal crashes.

39. Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.

      .. code-block:: cpp

        #include <iostream>
        #include <string>
        #include <cstring>

        void compareTwoStrings()
        {
            std::string s1{"Hello"};
            std::string s2{"World"};
            if (s1 == s2)
                std::cout << "Two strings are equal!" << std::endl;
            else
                std::cout << "Two strings are not equal!" << std::endl;
        }

        void compareTwoCStyleStrings()
        {
            const char *s1 = "Hello";
            const char *s2 = "World";
            if (!std::strcmp(s1, s2))
                std::cout << "Two C-style strings are equal!" << std::endl;
            else
                std::cout << "Two C-style strings are not equal!" << std::endl;
        }

        int main()
        {
            compareTwoStrings();
            compareTwoCStyleStrings();

            return 0;
        }

40. Write a program to define two character arrays initialized from string literals. Now define a third character array
    to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.

      .. code-block:: cpp

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

41. Write a program to initialize a vector from an array of ints.

      .. code-block:: cpp

        int a[] = {0, 1, 2, 3, 4, 5};
        std::vector<int> v(std::begin(a), std::end(a));

42. Write a program to copy a vector of ints into an array of ints.

      .. code-block:: cpp

        #include <iostream>
        #include <vector>

        int main()
        {
            std::vector<int> v{0, 1, 2, 3, 4, 5};
            int a[6] = { };
            int j = 0;
            for (const auto &i : v)
                a[j++] = i;
            for (const auto &i : a)
                std::cout << i << " ";
            std::cout << std::endl;

            return 0;
        }

43. Write three different versions of a program to print the elements of ia. One version should use a range for to
    manage the iteration, the other two should use the ordinary for loop in one case using subscripts and in the other
    using pointers. In all three  programs write all the types directly. That is, do not use a type alias, auto, or
    decltype to simplify the code.

      .. code-block:: cpp

        #include <iostream>
        #include <cstddef>

        void printArrayByRangeBasedLoop()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (const int (&row)[4] : ia)
                for (const int &col : row)
                    std::cout << col << " ";
            std::cout << std::endl;
        }

        void printArrayBySubscripts()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (std::size_t row = 0; row != 3; ++row)
                for (std::size_t col = 0; col != 4; ++col)
                    std::cout << ia[row][col] << " ";
            std::cout << std::endl;
        }

        void printArrayByPointers()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (int (*p)[4] = ia; p != ia + 3; ++p)
                for (int *q = *p; q != *p + 4; ++q)
                    std::cout << *q << " ";
            std::cout << std::endl;
        }

        int main()
        {
            printArrayByRangeBasedLoop();
            printArrayBySubscripts();
            printArrayByPointers();

            return 0;
        }

44. Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.

      .. code-block:: cpp

        #include <iostream>
        #include <cstddef>

        typedef int int_array[4]; // using int_array = int[4];

        void printArrayByRangeBasedLoop()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (const int_array &row : ia)
                for (const int &col : row)
                    std::cout << col << " ";
            std::cout << std::endl;
        }

        void printArrayBySubscripts()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (std::size_t row = 0; row != 3; ++row)
                for (std::size_t col = 0; col != 4; ++col)
                    std::cout << ia[row][col] << " ";
            std::cout << std::endl;
        }

        void printArrayByPointers()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (const int_array *p = ia; p != ia + 3; ++p)
                for (const int *q = *p; q != *p + 4; ++q)
                    std::cout << *q << " ";
            std::cout << std::endl;
        }

        int main()
        {
            printArrayByRangeBasedLoop();
            printArrayBySubscripts();
            printArrayByPointers();

            return 0;
        }

45. Rewrite the programs again, this time using auto.

      .. code-block:: cpp

        #include <iostream>
        #include <cstddef>

        void printArrayByRangeBasedLoop()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (const auto &row : ia)
                for (const auto &col : row)
                    std::cout << col << " ";
            std::cout << std::endl;
        }

        void printArrayBySubscripts()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (std::size_t row = 0; row != 3; ++row)
                for (std::size_t col = 0; col != 4; ++col)
                    std::cout << ia[row][col] << " ";
            std::cout << std::endl;
        }

        void printArrayByPointers()
        {
            int ia[3][4] = {
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11}
            };
            for (auto p = std::begin(ia); p != std::end(ia); ++p)
                for (auto q = std::begin(*p); q != std::end(*p); ++q)
                    std::cout << *q << " ";
            std::cout << std::endl;
        }

        int main()
        {
            printArrayByRangeBasedLoop();
            printArrayBySubscripts();
            printArrayByPointers();

            return 0;
        }
