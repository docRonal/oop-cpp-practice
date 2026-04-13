#include <iostream>
using namespace std;
#include "complex.h"

int main()
{
    Complex a(3, 2), b(0, 13), c;
    Complex g(1, -4), s(12, 3);
    c = 10;
    cout << c << endl;
    c = -a;
    cout << c << endl;
    c = a + b;
    c = c - Complex(10);
    cout << c << endl;
    c = 10 - a;
    (c -= b) -= 10;
    cout << c << endl;

    cout << g.abs() << " abs" << endl;
    cout << g.conj() << " conj" << endl;
    cout << g.phase() << " phase" << endl;
    cout << g / a << " /" << endl;
    a /= g;
    cout << a << " /=" << endl;
    Complex w = g / s;
    cout << w << " /" << endl;
    w = 2 / s;
    cout << w << " /=" << endl;
}
