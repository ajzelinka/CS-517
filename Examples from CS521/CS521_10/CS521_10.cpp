/*
Name: Andrew Zelinka
File Name: CS521_09.cpp
Due Date: October 20, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows

FILL OUT LATER
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "PlayerTree.h"

int main() {
    ifstream iFile;
    ofstream oFile;
    string iFileName, oFileName;
    Player newPlayer;
    int stats[8];

    PlayerTree playerTree = PlayerTree();

    // Prompt for input file
    cout << "Thank you for coming to the player stats program!" << endl;
    cout << endl << "Enter the name of your input file: ";
    cin >> iFileName;

    // Add .txt if not already in the file name.
    if (iFileName[iFileName.size() - 4] != '.') iFileName += ".txt";

    // Prompt for output file
    cout << "Enter the name of your output file: ";
    cin >> oFileName;

    // Add .txt if not already in the file name.
    if (oFileName[oFileName.size() - 4] != '.') oFileName += ".txt";

    cout << endl << "Reading data from: " << iFileName << endl;

    // Read input file stream
    iFile.open(iFileName);
    playerTree.readInput(iFile);
    iFile.close();

    // Format and write to output file
    oFile.open(oFileName);
    oFile << "------------------- BASEBALL TEAM REPORT -------------------" << endl << endl;
    oFile << playerTree.getLength() << " PLAYERS FOUND IN FILE" << endl;
    oFile << "OVERALL BATTING AVERAGE IS " << fixed << setprecision(3) << playerTree.getBattingAvg() << endl << endl;
    playerTree.printTree(oFile, true);
    oFile << "------------------------------------------------------------" << endl << "In reverse order:" << endl;
    playerTree.printTree(oFile, false);
    oFile << "------------------------------------------------------------";
    oFile.close();
    
    playerTree.clear();
    cout << "The data has been written to: " << oFileName << endl << endl << "End of program - bye for now!";
}