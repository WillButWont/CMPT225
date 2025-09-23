#include "AList.h"
#include <iostream>
using namespace std;

int main() {
    AList<int> list;

    list.addRight(10);

    list.display(); // displays 10
    list.ddisplay();

    list.addRight(20);
    list.display(); // displays 10 20
    list.ddisplay();

    list.addLeft(5);
    list.display(); // displays 5 10 20
    list.ddisplay();

    list.addLeft(1);
    list.display(); // displays 1 5 10 20
    list.ddisplay();

    list.removeLeft();
    list.removeRight();

    list.display(); // displays 5 10
    list.ddisplay();

    list.clear(); // clear
    list.display(); // displays nothing

    return 0;
}