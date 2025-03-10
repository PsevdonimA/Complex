#include <iostream>
#include "complex.h"

int main()
{
    Complex a(1, 0);
    Complex b(1, 1);
    Complex c = a + b;
    c = a + 1;
    b = 1 + b;
    c = -c;
    a = 1 / b;
    a + b / c - 5 + 4 * a / 4 + 4 / a * 5;
    a *= 4;
    return 0;
}
