// File PlayerTree.cpp

#include "PlayerTree.h"

/*
---------------------------------------------------------------------------------------------------
Implementation File - Class: PlayerTree
---------------------------------------------------------------------------------------------------
*/

    // Default constructor used when no data is provided
    PlayerTree::PlayerTree() {
        root = NULL;
    }
    // Destructor
    PlayerTree::~PlayerTree() { clear(); }

    // Return true if length is zero
    bool PlayerTree::isEmpty() const { return getLength() == 0; }

    // Call countNodes() method and pass root member variable
	int PlayerTree::getLength() const { return countNodes(root); }

    // Read input from passed istream and add to tree
    void PlayerTree::readInput(istream &is) {
        // create temp player variable
        Player newPlayer = Player();
        // cycle through istream, read new lines, and call add() method for temp player
        while (is.good() && !is.eof()) {
            newPlayer.readInput(is);
            add(newPlayer);
        }
    }

    // Call insert() and pass player and root member variable
	bool PlayerTree::add(const Player &player) { return insert(player, root); }

    // Maybe some day
	bool PlayerTree::remove(const Player &player) { return false; }

    // Call deleteNodes() method
	void PlayerTree::clear() { deleteNodes(root); }

    // Call printForward() or printBackward() method based on forward parameter value
    void PlayerTree::printTree(ostream &os, bool forward) const {
        if (forward) printForward(os, root);
        else printBackward(os, root);
    }

    // Sum all batting averages and divide by total number of players
    double PlayerTree::getBattingAvg() const {
        double battingSum = 0.0;                    // initialize
        // call countNodes() method to get number of players
        int count = countNodes(root);
        // call sumBattingAverages() method to get sum of batting averages
        battingSum = sumBattingAverages(root);
        // return sum / number
        return battingSum / count;
    }

    // Recursive function to count
    int PlayerTree::countNodes(PlayerNode *R) const {
        // if node is empty, don't count
        if (R == NULL) return 0;
        // otherwise, count and call countNodes() method on both left and right nodes
        else return 1 + countNodes(R->left) + countNodes(R->right);
    }

    // Recursive function to sum batting averages
    double PlayerTree::sumBattingAverages(PlayerNode *R) const {
        // if node is empty, don't sum
        if (R == NULL) return 0;
        // otherwise, add to sum and call sumBattingAverages() method on left and right
        else return R->player.getBatting() + sumBattingAverages(R->left) + sumBattingAverages(R->right);
    }

    // Recursive function to find a place to insert
    bool PlayerTree::insert(const Player &player, PlayerNode* &R) {
        // if node is empty, create new node and insert
        if (R == NULL) { R = new PlayerNode(player); return true; }
        // if node exists and matches new player's name, don't add and return false
        else if (player.compareName(R->player) == 0) return false;
        // if node exists and comes after new player's name, call insert() method on left
        else if (player < R->player) return insert(player, R->left);
        // else call insert() method on right
        else return insert(player, R->right);
    }

    // Recursive function to print left child, then parent, then right child
    void PlayerTree::printForward(ostream &os, PlayerNode *R) const {
        if (R != NULL) {
            printForward(os, R->left);
            R->player.print(os);
            printForward(os, R->right);
        }
    }

    // Recursive function to print right child, then parent, then left child
    void PlayerTree::printBackward(ostream &os, PlayerNode *R) const {
        if (R != NULL) {
            printBackward(os, R->right);
            R->player.print(os);
            printBackward(os, R->left);
        }
    }
    
    // Recursive function to remove all child nodes and then the parent
    void PlayerTree::deleteNodes(PlayerNode *R) {
        if (R != NULL) {
            delete(R->left);
            delete(R->right);
            delete R;
        }
    }