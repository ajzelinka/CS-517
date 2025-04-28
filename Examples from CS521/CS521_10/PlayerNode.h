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

A PlayerNode has a Player and two pointers to left and right nodes.

Default Player and pointers are NULL.

Public methods are:
    PlayerNode() - default constructor
    PlayerNode(...) - constructor with passed Player element
---------------------------------------------------------------------------------------------------
*/

class PlayerNode{
    Player player;
    PlayerNode *left;
    PlayerNode *right;
    friend class PlayerTree;

    PlayerNode();
    PlayerNode(const Player &newplayer);
};
#endif