// File PlayerNode.cpp

#include "PlayerNode.h"

/*
---------------------------------------------------------------------------------------------------
Implementation File - Class: PlayerNode
---------------------------------------------------------------------------------------------------
*/

    // Default constructor used when no data is provided
    PlayerNode::PlayerNode() {player = Player(); left = NULL; right = NULL; }

    // Constructor with passed parameters.
    PlayerNode::PlayerNode(const Player &newplayer) {
        player = newplayer; left = NULL; right = NULL;
    }