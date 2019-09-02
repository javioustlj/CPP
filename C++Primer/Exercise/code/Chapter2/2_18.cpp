int main()
{
    int a = 0, *p = nullptr;
    p = &a;  // Change the value of a pointer
    *p = 100; // Change the value to which the pointer points

    return 0;
}
