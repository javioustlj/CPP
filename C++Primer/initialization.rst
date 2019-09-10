Initialization
===================

An object that is **initialized** gets the specified value at the moment it is created.


C++ defines several different forms of initialization.

.. code-block:: cpp

   int a = 0;
   int a = {0};
   int a{0};
   int a(0);

.. warning::

  Initialization and assignment are different operations in C++. Initialization happens when a variable is given a value
  when it is created. Assignment obliterates an object's current value and replaces that value with a new one.

List Initialization
=====================

Initialization that use of curly braces is referred to as **list initialization**. Braced lists of initializers can now
be used whenever we initialize an object and in some cases when we assign a new value to an object.

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

When we define a variable without an initializer, the variable is **default initialized**. What that default value is
depends on the type of the variable and may also depend on where the variable if defined

Built-in type
-------------

The value of an object of built-in type that is not explicitly initialized depends on where it is defined.

Variables defined outside any function body are initialized to zero.
Variables defined inside a function are uninitialized. The value of an uninitialized variable of built-in type is
undefined.

Class
---------

Each class controls how we initialize objects of that class type.

Objects of class type that we do not explicitly initialize have a value that is defined by the class

Pointer
-------------

Like other built-in types, pointer defined at block scope have undefined value if they are not initialized.


In-class initialization
========================

Under the new standard, we can supply an **in-class initializer** for a data member. When we create objects, the
in-class initializers will be used to initialize the data member. Members without an initializer are default
initialized.

.. code-block:: cpp

   struct student {
     std::string name;
     unsigned height = 0;   // OK
     unsigned weight{0};    // OK
     unsigned score = {0};  // OK
     unsigned rank(0);      // error: we can't specify an in-class initializer inside parentheses.
   };

.. note::
  In-class initializers are must either be enclosed insede curly braces or follow an = sign. We may not specify an
  in-class initializer inside parentheses.

Direct and Copy Forms of Initialization
==================================

When we initialize a variable using =, we are asking the compiler to **copy initialize** the object by copying the
initializer on the right-hand side into the object being created.

Otherwise, when we omit the =, we use **direct initialization**.

Vector type
================

.. code-block:: cpp

   vector<string> svec;   // default initialization; svec has no elements
   vector<int> ivec;      // initially empty
   vector<int> ivec2(ivec);   // copy elements of ivec into ivec2
   vector<int> ivec3 = ivec;  // copy elements of ivec into ivec3
   vector<int> ivec4{ivec}；   // error:
   vector<string> svec2(ivec)   // error: svec holds strings, not ints

   // list initializing
   vector<string> articles = {"a", "an", "the"};
   vector<string> v1{"a", "an", "the"};   // list initialization
   vector<string> v2("a", "an", "the");   // error, list initialization must use curly braces

   // value initialization
   vector<int> ivec(10);   // ten elements, each initialized to 0
   vector<string> svec(10)  // ten elements, each an empty string

When we use curly braces, {...}, we're saying that, if possible, we want to list initialize the object. That is, if
there is a way to use the values inside the curly braces as a list of element initializers, the class will do so. Only
if it is not possible to list initialize the object will the other ways to initialize the object be considered. On the
other hand, if we use braces and there is no way to use the initializers to list initialize the object, then those
values will be used to construct the object.
