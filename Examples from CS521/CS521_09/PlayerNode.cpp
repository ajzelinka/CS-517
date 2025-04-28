// File PlayerNode.cpp

#include "PlayerNode.h"

/*
---------------------------------------------------------------------------------------------------
Implementation File - Class: PlayerNode
---------------------------------------------------------------------------------------------------
*/

    // Default constructor used when no data is provided
    PlayerNode::PlayerNode() {player = Player(); next = NULL; prev = NULL; }

    // Constructor with passed parameters.
    PlayerNode::PlayerNode(const Player &newplayer) {
        player = newplayer; next = NULL; prev = NULL;
    }