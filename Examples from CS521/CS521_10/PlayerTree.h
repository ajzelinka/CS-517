// File PlayerList.h
#ifndef ANDREW_ZELINKA_PlayerList_H
#define ANDREW_ZELINKA_PlayerList_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

#include "PlayerNode.h"

/*
---------------------------------------------------------------------------------------------------
Class PlayerList

PlayerList has a length, pointers to the first and last elements, and a pointer internal iterator.

Default length is zero, default pointers are NULL

Public methods are:
    PlayerList() - default constructor
    ~PlayerList() - destructor

    bool isEmpty() - returns true if length is zero
    int getLength() - returns the length of the array

    void readInput(...) - reads an input stream of player info and adds new players for each line
    bool add(...) - adds player to list in alphabetical order by last name, returns true if success
    bool remove(...) - removes player from list, returns false if not found and true if success
    void clear(...) -  removes all players from list and sets length to zero

    bool printTree(...) - prints tree to ostream either forward or backward

    double getBattingAverage() - returns average of all players' batting averages

Private methods are:
    int countNodes(...) - iterative method to sum nodes are navigable from the root
    double sumBattingAverages(...) - iterative method to sum all players' batting averages
    bool insert(...) - iterative method to create and insert a node in the tree in order
    void printForward(...) - iterative method to cycle through players in order and print
    void printBackward(...) - iterative method to cycel through players in reverse order and print
    void deleteNodes(...) - iterative method to delete all nodes from memory
---------------------------------------------------------------------------------------------------
*/

class PlayerTree{
    class PlayerNode *root;

public:
    PlayerTree();
    ~PlayerTree();

    bool isEmpty() const;
	int getLength() const;

    void readInput(istream &is);
	bool add(const Player &player);
	bool remove(const Player &player);
	void clear();

    void printTree(ostream &os, bool forward) const;

    double getBattingAvg() const;
    
private:
    int countNodes(PlayerNode *R) const;
    double sumBattingAverages(PlayerNode *R) const;
    bool insert(const Player &player, PlayerNode* &R);
    void printForward(ostream &os, PlayerNode *R) const;
    void printBackward(ostream &os, PlayerNode *R) const;
    void deleteNodes(PlayerNode *R);
};
#endif