//
// PolynomialsCLion
// main.cpp
// Created by Luigi Catello on 20/04/21.
//
//

#include <iostream>
#include "Polynomials.h"

using std::cout;
using std::endl;

int main() {
//    double c[] = {1, 2.5, 4, 3.2};
//    Polynomials p1{c, 4};
//    cout << "p1 = " << p1 << endl;
//    Polynomials p2 = p1;
//    cout << "p1 " << ((p1 == p2) ? "=" : "!=") << " p2" << endl;
//    Polynomials p3;
//    cout << "p1 " << ((p1 == p3) ? "=" : "!=") << " p3" << endl;
//    Polynomials p4(4);
//    cout << "deg(p1) = " << p1.degree() << endl;
//    cout << "deg(p3) = " << p3.degree() << endl;
//    p1.print();
//    cout << endl;
//    p1 += p4;
//    cout << "p1 = " << p1 << endl;
//    p1 *= 2;
//    cout << "p1 = " << p1 << endl;
//    Polynomials p5 = p1 * 3;
//    cout << "p5 = " << p5 << endl;
//    Polynomials p6 = 3 * p1;
//    cout << "p5 " << ((p5 == p6) ? "=" : "!=") << " p6" << endl;

    double a[] = {1.0, 2.0, 3.0, 4.0};
    double b[] = {2, 4, 1};

    Polynomials pa(a, 4);
    Polynomials pb(b, 3);

    Polynomials pc = pa * pb;

    cout << "( " << pa << " ) ( " << pb << " ) =" << endl;
    cout << "= " << pc << endl;

    return 0;
}
