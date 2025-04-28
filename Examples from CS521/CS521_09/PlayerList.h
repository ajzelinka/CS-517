// File PlayerList.h
#ifndef ANDREW_ZELINKA_PLAYERLIST_H
#define ANDREW_ZELINKA_PLAYERLIST_H

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

    void start() - sets the iterator to point to the first element
    void end() - sets the iterator to point to the last element

    bool hasNext() - returns true if the iterator points to a valid element
    bool hasPrev() - returns true if the iterator points to a valid element
    void getNext(...) - writes the next Player element into the passed variable
    void getPrev(...) - writes the previous Player element into the passed variable

    void readInput(...) - reads an input stream of player info and adds new players for each line
    bool add(...) - adds player to list in alphabetical order by last name, returns true if success
    bool remove(...) - removes player from list, returns false if not found and true if success
    void clear(...) -  removes all players from list and sets length to zero

    bool printForward() - prints all players and relevant data in list from first to last
    bool printBackward() - prints all players and relevant data in list from last to first

    double getBattingAverage() - returns average of all players' batting averages

---------------------------------------------------------------------------------------------------
*/

class PlayerList{
    int mLength;
    class PlayerNode *pFirst;
    class PlayerNode *pLast;
    class PlayerNode *pCurrent;
    friend class PlayerListIterator;

public:
    PlayerList();
    ~PlayerList();

    bool isEmpty();
	int getLength();

    void start();
    void end();

    bool hasNext();
    bool hasPrev();
    void getNext(Player &player);
    void getPrev(Player &player);

    void readInput(istream &is);
	bool add(const Player &player);
	bool remove(const Player &player);
	void clear();

    bool printForward(ostream &os);
    bool printBackward(ostream &os);

    double getBattingAvg();
};
#endif