#include <iostream>
#include "CircleList.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

int main() {
    CircleList<string> l;
    l.add("A");
    l.add("B");
    l.add("C");
    l.add("D");
    cout << "1) " << l.toString() << endl;
    l.advance();
    l.advance();
    cout << "2) " << l.toString() << endl;
    l.remove();
    cout << "3) " << l.toString() << endl;
    cout << "Front: " << l.front() << endl;




    return 0;
}
