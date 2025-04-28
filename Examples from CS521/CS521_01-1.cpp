/*
Name: Andrew Zelinka
Due Date: August 30, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows
Description: This program computes the volume of a sphere. It will request a radius value (in cm) from the user, and it will output the volume of a sphere with that radius.
    The output will include volume in cm^3 as well as in^3.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main1(){
    double r_cm, r_in, v_cm, v_in;
    const double PI = 2 * acos(0.0);

    cout << "Welcome to the volume calculator!\n\nEnter the radius of your sphere in cm: ";
    cin >> r_cm;
    
    r_in = r_cm / 2.54;

    v_in = 4 * PI * pow(r_in,3) / 3;
    v_cm = 4 * PI * pow(r_cm,3) / 3;

    cout << "\nFor a sphere with a radius of " << fixed << setprecision(3) << r_cm << " cm," << endl;
    cout << "The volume is: " << v_cm << " cm-cubed,\nor " << v_in << " inches-cubed." << "\n\nEnd Program.\n";
    
    return 0;
}