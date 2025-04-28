/*
Name: Andrew Zelinka
Due Date: September 8, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows
Description: This program will prompt a user for the terms of the quadratic equation,
 and then it will compute the roots of the equation for the provided terms.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main2(){
    float a, b, c, rt, rt1, rt2, i1, i2;
    float min0 = -0.000001, max0 = 0.000001;

    cout << fixed << setprecision(3) << "\nWelcome to the root calculator! Here for all your root calculation needs.\nThe quadratic formula is as follows:\na*x^2 + b*x + c = 0.\n\nPlease enter values for a, b, and c, separated by spaces. We'll do the rest: ";
    cin >> a >> b >> c;
    cout << "\n";

    rt = (b*b) - (4*a*c);

    if (min0 < a && max0 > a) {
        rt1 = -(c / b);
        cout << "You only have one root, which is: " << rt1;
    }
    else if (min0 < rt && max0 > rt){
        rt1 = -b/(2*a);
        cout << "You only have one root, which is: " << rt1;
    }
    else if (max0 > rt){
        i1 = -b/(2*a);
        i2 = sqrt(-1*rt)/(2*a);
        cout << "Your roots are: " << i1 << " + " << i2 << "i and " << i1 << " - " << i2 << "i";
    }
    else {
        rt1 = (-b + sqrt(rt))/(2*a);
        rt2 = (-b - sqrt(rt))/(2*a);
        cout << "Your roots are: " << rt1 << " and " << rt2;
    }
    return 0;
}