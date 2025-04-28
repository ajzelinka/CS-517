// File PlayerNode.h
#ifndef ANDREW_ZELINKA_PLAYERNODE_H
#define ANDREW_ZELINKA_PLAYERNODE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

#include "Player.h"

/*
---------------------------------------------------------------------------------------------------
Class PlayerNode

A PlayerNode has a Player and two pointers to previous and next nodes.

Default Player and pointers are NULL.

Public methods are:
    PlayerNode() - default constructor
    PlayerNode(...) - constructor with passed Player element
---------------------------------------------------------------------------------------------------
*/

class PlayerNode{
    Player player;
    PlayerNode *next;
    PlayerNode *prev;
    friend class PlayerList;
    friend class PlayerListIterator;

    PlayerNode();
    PlayerNode(const Player &newplayer);
};
#endif