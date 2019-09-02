- Initialization and assignment are different operations in C++
  Initialization happens when a variable is given a value when it is created. Assignment obliterates an object's current
  value and replaces that value with a new one.


.. code-block:: cpp

   int a = 0;
   int a = {0};
   int a{0};
   int a(0);

When used with variables of built-in type, list initialization has one important property: The compiler will not let us
list initialize variables of built-in type if the initializer might lead to the loss of information:

.. code-block:: cpp

   long double ld = 3.14159265357;
   int a{ld}, b = {ld};  // error: narrowing conversion required
   int c(ld), d = (ld);  // ok: but value will be truncated

The compiler rejects the initializations of a and b because using a long double to initialize an int is likely to lose
data. At a minimum, the fractional part of ld will be truncated. In addition, the integer part in ld might be too large
to fit in an int.

Default Initialization
=======================

When we define a variable without an initializer, the variable is default initialized. What that default value is
depends on the type of the variable and may also depend on where the variable if defined

Uninitialized objects of built-in type defined inside a function body have undefined value.
Objects of class type that we do not explicitly initialize have a value that is defined by the class

Built-in type
-------------

The value of an object of built-in type that is not explicitly initialized depends on where it is defined.

Variables defined outside any function body are initialized to zero.
Variables defined inside a function are uninitialized. The value of an uninitialized variable of built-in type is
undefined.

Class
---------

Each class controls how we initialize objects of that class type.

Pointer
-------------

Like other built-in types, pointer defined at block scope have undefined value if they are not initialized.
