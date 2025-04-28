// File Player.h
#ifndef ANDREW_ZELINKA_PLAYER_H
#define ANDREW_ZELINKA_PLAYER_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

/*
---------------------------------------------------------------------------------------------------
Class Player

A Player has a first name, a last name, and an array containing the following baseball stats:
Plate appearances, At bats, Singles, Doubles, Triples, Home runs, Walks, and Hits by pitch

Default names are "Unknown", and default stats are 0.

Public methods are:
    Player() - default constructor
    Player(...) - constructor with starting values

    bool readInput(...) - reads input from an istream of a single line
    string getName() - returns name formatted as "Last, First"
    double getHits() - returns the total sum of singles, doubles, triples, and home runs
    double getBatting() - returns batting average
    double getOBP() - returns the on base percentage
    double getSlugging() - returns the weighted slugging avergage
    double getOPS() - returns on-base plus slugging percentage

---------------------------------------------------------------------------------------------------
*/

class Player{
    string mFirst;
    string mLast;
    int mStats[8];

public:
    Player();
    Player(string, string, int[]);

    bool readInput(istream &input);
    string getName();
    double getHits();
    double getBatting();
    double getOBP();
    double getSlugging();
    double getOPS();
};
#endif