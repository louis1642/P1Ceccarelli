#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    LinkedList<int> I;
    I.addFront(10);
    I.addFront(14);
    cout << I.front() << endl;
    I.removeFront();
    cout << I.front() << endl;
    // creo uno scope
    {
        LinkedList<string> S;
        S.addFront("ASD");
        S.addFront("QWE");
        S.addFront("sdfsd");
        cout << S.front() << endl << "Size: " << S.size() << endl;
        cout << S[1] << endl;
    }
    // uscito dallo scope, S dovrebbe venire eliminata



    return 0;
}
