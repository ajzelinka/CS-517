#include <iostream>
using namespace std;

int main() {
    double x = 1.2;
    double *p;

    p = &x;

    cout << "*p: " << *p;
    cout << "p:  " << p;
}