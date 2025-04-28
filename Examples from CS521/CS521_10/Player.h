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
    int compareName(...) - comparison of two players' last names, breaks ties with first name
    double getHits() - returns the total sum of singles, doubles, triples, and home runs
    double getBatting() - returns batting average
    double getOBP() - returns the on base percentage
    double getSlugging() - returns the weighted slugging avergage
    double getOPS() - returns on-base plus slugging percentage
    void print(...) - prints player name, batting avg, and OPS to ostream

    bool operator<(...) - returns true if name comparison yields negative (earlier in alphabet)
    bool operator>(...) - returns true if name comparison yields positive (later in alphabet)

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
    string getName() const;
    int compareName(Player player) const;
    double getHits() const;
    double getBatting() const;
    double getOBP() const;
    double getSlugging() const;
    double getOPS() const;
    void print(ostream &os) const;

    bool operator<(const Player &p) const;
    bool operator>(const Player &p) const;
};
#endif