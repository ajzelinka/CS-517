/*
Name: Andrew Zelinka
File Name: Problem2.cpp
Due Date: April 29, 2025
Course: CS 517 - Computing Theory
Environment: VSCode Windows

Description: This program will ask for input parameters, including two
sorted arrays, and it will return a single combined sorted array. The
requested input parameters will be as follows:
 - size of array A* and array B, separated by a space
 - contents of array A, each separated by a space
 - contents of array B, each separated by a space

*Note that the size of array A needs to include a buffer at the end
that can hold the contents of array B.
*/

#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string arraySizesString, arrayAString, arrayBString;
    int arrayASize, arrayBSize, temp, j;

    // Get string values for all inputs: sizes, A contents, B contents
    std::cout << "Please input program parameters:\n";
    std::cin  >> arrayASize;
    std::cin  >> arrayBSize;
    int arrayA[arrayASize];

    // Read array A and array B into a single array
    for (int i=0; i<arrayASize; i++) {
        std::cin >> arrayA[i];
    }

    std::cout << "The result of the merge operation is:\n";

    // Use insertion sort to insert array B elements earlier into array A
    for (int i=arrayASize-arrayBSize; i<arrayASize; i++) {
        temp = arrayA[i]; j = i - 1;
        while (j >= 0 && arrayA[j] > temp) {
            arrayA[j+1] = arrayA[j];
            j--;
        }
        arrayA[j+1] = temp;
    }

    for (int i=0; i<arrayASize; i++) {
        std::cout << arrayA[i] << " ";
    }
    
    std::cout << std::endl;
}