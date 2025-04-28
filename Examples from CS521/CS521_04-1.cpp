/*
Name: Andrew Zelinka
File Name: CS521_04-1.cpp
Due Date: September 22, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows
Description: This program will read a text file containing DNA fragments.
Then, this program will calculate the GCRatio of each fragment and
determine whether or not that falls into the 35-65% range. Fragments less
than thirty characters will be ignored. It will then write an output file
showing relevant information for each fragment.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void main4() {

    string inFileName, outFileName;
    string newLine, comment;
    int G, C, T, A;
    double GCRatio;
    int numFrag = 0, numShort = 0;
    ifstream inFile;
    ofstream outFile;

    // Get input and output file names and open

    cout << "Welcome to the DNA Fragment Program!\nPlease enter the name of the input data file: ";
    cin >> inFileName;
    cout << "\nWell done. Now please enter the name of the output data file: ";
    cin >> outFileName;
    cout << "\nPerfect. Just a moment.";

    inFile.open(inFileName);
    outFile.open(outFileName);

    outFile << "REPORT ON INPUT FILE:   " << inFileName << endl << endl;
    outFile << "---------------------------------------------------------------------------------------------" << endl;
    outFile << "Fragment                                          | GC-Ratio | Comments" << endl;
    outFile << "--------------------------------------------------|----------|-------------------------------" << endl;

    while (inFile.good() && !inFile.eof()) {
        A = 0;                                                          // Reset variable counters
        C = 0;
        G = 0;
        T = 0;
                
        getline(inFile, newLine);                                       // Read new line and print to output
        numFrag++;
        for (int i = 0; i < newLine.size(); i++)
            outFile << char(toupper(newLine[i]));
        outFile << setw(52 - newLine.size()) << "| ";

        if (newLine.size() < 30) {                                      // If too short, print error message
            numShort++;
            outFile << "N/A      | Fragment too short to process." << endl;
        }
        else {                                                          // Cycle through line and count each letter
            for (int i = 0; i < newLine.size(); i++) {
                if (newLine[i] == 'A' || newLine[i] == 'a')
                    A++;
                else if (newLine[i] == 'C' || newLine[i] == 'c')
                    C++;
                else if (newLine[i] == 'G' || newLine[i] == 'g')
                    G++;
                else if (newLine[i] == 'T' || newLine[i] == 't')
                    T++;
            }

            GCRatio = (G + C) / double(G + C + A + T);                  // Calculate GCRatio

            if (GCRatio > 0.65 || GCRatio < 0.35)                       // Determine appropriate comment
                comment = "     |";
            else comment = "     | Fragment within 35%-65% range.";

            outFile << fixed << setprecision(2) << GCRatio << comment << endl; // Print GCRatio and comment to output file
        }
    }
    inFile.close();                                                     // Close input file and print summary info to output file
    outFile << "-------------------------------------------SUMMARY-------------------------------------------" << endl;
    outFile << "There were " << numFrag << " fragment(s) found." << endl;
    outFile << numShort << " fragment(s) were not long enough to process.";

    outFile.close();                                                    // Close output file

    cout << "\n\nYour report is stored in the local file: " << outFileName << "\nEnd Program - Bye for now!";
}