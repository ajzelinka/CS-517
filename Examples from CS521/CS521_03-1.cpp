/* File: CS521_03-1.cpp
Name: Andrew Zelinka
Due Date: August 30, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows
 This program modifies example 03-3 to include a histogram tracking letter grade values.
 For each test read in, this program will track what letter grade it is and increment a tracker for the appropriate grade.
 When all tests are read, the program will output a histogram of asterisks for each letter grade.
*/
#include <iostream>
#include <iomanip>
using namespace std;

void main3() {

    int count;          // a counter keeping track of how many tests we have read in
    const int MAXTESTS = 100;  // maximum number of tests we can store
    int testList[MAXTESTS];    // the list storing up to 100 test grades entered
    int nextTest;       // next test read in, to prime the pump

    int testSum;        // sum of all the tests entered
    double average;     // average of all the test grades

    int As = 0, Bs = 0, Cs = 0, Ds = 0, Fs = 0; //number of tests belonging to each letter grade

    // initialize our loop control counter to 0. This reflects the fact that we have read in 0 tests so far
    // initialize the testSum to 0 so we can add individual tests to it
    // This version of the loop "primes the pump" by requesting the first test grade
    // then start the loop to read in tests until the user enters a negative number

    count = 0;

    cout << "Please enter a test grade (-1 to quit): ";
    cin >> nextTest;  // get the next value
    while (nextTest >= 0 && count < MAXTESTS) // why is this extra check needed?
    {
        testList[count] = nextTest;  // save the last test in the array
        count++;                     // count the good test
        
        if (nextTest >= 90) {       // Increment As by one if above 90
            As++;
        }
        else if (nextTest >= 80) {  // Else increment Bs by one if above 80
            Bs++;
        }
        else if (nextTest >= 70) {  // Else increment Cs by one if above 70
            Cs++;
        }
        else if (nextTest >= 60) {  // Else increment Ds by one if above 60
            Ds++;
        }
        else                        // Else increment Fs by one
            Fs++;

        // continue the pump
        if (count < MAXTESTS) // WHY??????
        {
            cout << "Please enter a test grade (-1 to quit): ";
            cin >> nextTest;  // get the next value
        }
    }

    // when we get here, testCount reflects how many tests were read in
    // now lets write a for loop to sum the tests and compute the average
    testSum = 0;
    for (int i = 0; i < count; i++)  // why not 100?
        testSum += testList[i];      // visit each test stored and add it to the sum

        average = double(testSum) / count;
        cout << "\nThe average of your " << count << " tests is " << setprecision(2) << fixed;
        cout << average << endl;

    cout << "A:";
    for (int i = 0; i < As; i++) // Loop as many times as the value of As, print one asterisk each loop
        cout << "*";
    cout << "\nB:";
    for (int i = 0; i < Bs; i++) // Loop as many times as the value of Bs, print one asterisk each loop
        cout << "*";
    cout << "\nC:";
    for (int i = 0; i < Cs; i++) // Loop as many times as the value of Cs, print one asterisk each loop
        cout << "*";
    cout << "\nD:";
    for (int i = 0; i < Ds; i++) // Loop as many times as the value of Ds, print one asterisk each loop
        cout << "*";
    cout << "\nF:";
    for (int i = 0; i < Fs; i++) // Loop as many times as the value of Fs, print one asterisk each loop
        cout << "*";
        
        //*** WHAT HAPPENS IF THE USER ENTERS A NEGATIVE NUMBER TO START? ***//
        cout << "\nEnd Program - Goodbye." << endl;
}