/*
Name: Andrew Zelinka
File Name: CS521_05-1.cpp
Due Date: October 13, 2024
Course: CS 521 - Intro to Programming
Environment: VSCode Windows

Description: This program will prompt the user for input and output .txt files.
The input file should contain a list of baseball player stats, including: 
First Name, Last Name, Plate Appearances, At Bats, Singles, Doubles, Triples,
Home Runs, Walks, and Hits by Pitch - separated by white space.
The program will read the input file line by line, creating new Player objects
for each one. Then the program will call various Player methods to calculate
baseball stats before printing an output file with each player's name, batting
average, and OPS. The output file will also contain a total sum of players read
in and an average batting average for all players.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "Player.h"

int main() {
    ifstream iFile;
    ofstream oFile;
    string iFileName, oFileName;
    string newLine;
    Player players[100];
    int countPlayers = 0;
    double battingSum = 0;

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

    cout << "Reading data from: " << iFileName << endl;
    iFile.open(iFileName);
    
    // While no errors and not end of file, pass reference to readInput method
    while(iFile.good() && !iFile.eof()) {
        // Read input files and store player instances in the players[] array
        bool readSuccess = players[countPlayers].readInput(iFile);
        // Only count if the line was successfully read in
        if (readSuccess)
            countPlayers++;
    }
    iFile.close();
    
    // Open output file and begin writing.
    oFile.open(oFileName);
    oFile << setw(30) << "PLAYER NAME :" << setw(16) << "AVERAGE" << setw(13) << "OPS" <<endl;
    oFile << "------------------------------------------------------------" << endl;

    // Cycle through the players we've added to our array.
    for (int i = 0; i < countPlayers; i++) {
        // Sum batting averages to return average batting average (average, average, average)
        battingSum += players[i].getBatting();
        // Print name, batting average, and OPS for each player
        oFile << setw(28) << players[i].getName() << " :"
        << setw(15) << fixed << setprecision(3) << players[i].getBatting()
        << setw(15) << players[i].getOPS() << endl;
    } 

    // Finish formatting and return total player count and average batting average (AVERAGE!)
    oFile << "------------------------------------------------------------" ;
    oFile << endl << "BASEBALL TEAM REPORT:     " << countPlayers << " players found in file" << endl;
    oFile << "OVERALL BATTING AVERAGE:  " << battingSum / countPlayers;

    // Close output file and sign off
    oFile.close();

    cout << "The output file is in: " << oFileName << endl << endl << "Thank you. Bye now.";
}