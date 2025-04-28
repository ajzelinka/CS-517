/*
Name: Andrew Zelinka
File Name: CS521_05-1.cpp
Due Date: October 1, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows
Description: This program will prompt the user for a number n and use two
different methods to compute the nth number in the Fibonacci sequence. It
will compute using normal loop logic, and then it will compute using a
recursive function. With both responses, it will output the time it took
to compute the value.
*/

#include <iostream>
#include <chrono>
using namespace std;

// Fib(n) defines the recursive function solution to the Fibonacci problem.

long Fib(long n) {
    if (n <= 2)
        return (n - 1);
    else
        return (Fib(n-1) + Fib(n-2));
}

void main5() {
    int n;                                                          // Input from user
    long int ansLoop, ansFcn, current = 1, previous = 0;            // Two answers and two temp values for the loop logic
    int elapsedLoop, elapsedFcn;                                    // Two elapsed times
    std::chrono::time_point<std::chrono::steady_clock> bfrLoop;     // Before and after times for each method
    std::chrono::time_point<std::chrono::steady_clock> aftLoop;
    std::chrono::time_point<std::chrono::steady_clock> bfrFcn;
    std::chrono::time_point<std::chrono::steady_clock> aftFcn;


    cout << "Welcome to the Fibonacci finder-majig." << endl << "Please enter positive, non-zero integer: ";
    cin >> n;
    cout << "Great choice. Just a sec." << endl << endl;

    bfrLoop = std::chrono::steady_clock::now();

    if (n <=2)                              // Return n-1 if the input is 2 or less.
        ansLoop = n - 1;
    else {                                  // Otherwise, add previous two together.
        for (int i = 2; i < n; i++) {
            ansLoop = current + previous;
            previous = current;             // Update previous values.
            current = ansLoop;
        }
    }

    // Find loop time

    aftLoop = std::chrono::steady_clock::now();
    elapsedLoop = std::chrono::duration_cast<std::chrono::microseconds> (aftLoop - bfrLoop).count();

    // Now with the recursive function

    bfrFcn = std::chrono::steady_clock::now();

    ansFcn = Fib(n);

    // Find function time

    aftFcn = std::chrono::steady_clock::now();
    elapsedFcn = std::chrono::duration_cast<std::chrono::microseconds> (aftFcn - bfrFcn).count();

    // Return values and time elapsed

    cout << "The " << n << "th number in the Fibonacci sequence is " << ansLoop << "." << endl;
    cout << "The elapsed time to compute using the loop method is " << elapsedLoop << " microseconds." << endl << endl;
    cout << "The " << n << "th number in the Fibonacci sequence is " << ansFcn << "." << endl;
    cout << "The elapsed time to compute using the loop method is " << elapsedFcn << " microseconds." << endl;
}