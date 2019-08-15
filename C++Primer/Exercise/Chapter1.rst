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
     :linenos:

      #include<iostream>
      int main()
      {
          std::cout << 3 * 5 << std::endl;

          return 0;
      }


5. We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

  .. code-block:: cpp
     :linenos:

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
     :linenos:

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
     :linenos:

     #include<iostream>
     int main()
     {
         std::cout << "/*";
         std::cout << "*/";
         //std::cout << /* "*/" */; This failed.
         std::cout << /* "*/" /*  "/*"  */;

         return 0;
     }
