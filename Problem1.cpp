/*
Name: Andrew Zelinka
File Name: Problem1.cpp
Due Date: April 29, 2025
Course: CS 517 - Computing Theory
Environment: VSCode Windows

Description: This program will prompt the user to input the name of a
text file to read from. This text file should be in the same directory
that the program is called from and should contain a series of arrays
-- one per line -- with sorted, space-separated integer values. The
program will read the input text file and output one line per array,
which will either be the integer value of the "magic index" of that
array or "None" if no magic index was found.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    int i = 0;
    int j = 0;
    int temporaryValue;
    
    bool found = false;
    std::string temporaryString;
    std::string inFileString;
    std::ifstream inFile;
    std::string arrayAString;

    std::cout << "Input file name: ";
    std::cin >> inFileString;
    std::cout << "Thank you. The magic indices in the file provided are as follows:\n";

    if (inFileString[inFileString.size() - 4] != '.') inFileString += ".txt";

    inFile.open(inFileString);

    while (inFile.good() && !inFile.eof()) {
        
        // Read next line and initialize stringstream for it
        std::getline(inFile, arrayAString);
        std::stringstream ss(arrayAString);    

        // Iterate over stringstream to find magic index
        while (ss >> temporaryValue) {
            // If magic index found, flag it, print it, and break loop
            if (temporaryValue == j) {
                found = true; std::cout << j; break;
            }
            j++;
        }

        // Print 'none' if none found
        if (!found) { std::cout << "None"; }
        std::cout << std::endl;

        found = false;
        i = 0;
        j = 0;
        
    }

    inFile.close();
}