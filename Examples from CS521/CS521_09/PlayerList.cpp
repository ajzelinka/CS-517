// File PlayerList.cpp

#include "PlayerList.h"

/*
---------------------------------------------------------------------------------------------------
Implementation File - Class: PlayerList
---------------------------------------------------------------------------------------------------
*/

    // Default constructor used when no data is provided
    PlayerList::PlayerList() {
        mLength = 0;
        pFirst = NULL;
        pLast = NULL;
        pCurrent = NULL;
    }
    // Destructor
    PlayerList::~PlayerList() { clear(); }

    // Return true only if mLength is zero
    bool PlayerList::isEmpty() { return mLength == 0; }
    // Return mLength value
	int PlayerList::getLength() { return mLength; }
    // Return pCurrent to start
    void PlayerList::start() { pCurrent = pFirst; }
    // Return pCurrent to end
    void PlayerList::end() { pCurrent = pLast; }
    // Return true if pCurrent exists
    bool PlayerList::hasNext() { return pCurrent != NULL; }
    bool  PlayerList::hasPrev() { return pCurrent != NULL; }
    // Get next item and overwrite passed reference
    void PlayerList::getNext(Player &player) {
        player = pCurrent->player;
        pCurrent = pCurrent->next; } 
    // Get previous item and overwrite passed reference
    void PlayerList::getPrev(Player &player) {
        player = pCurrent->player;
        pCurrent = pCurrent->prev;
    }

    // Declare temporary Player and use loop logic to add players from istream line by line
    void PlayerList::readInput(istream &is) {
        Player newPlayer = Player();

        while(is.good() && !is.eof()) {
            newPlayer.readInput(is);
            add(newPlayer);
        }
    }

    // Add player
	bool PlayerList::add(const Player &player) {
        // Declare new player node and iterator pointers
        PlayerNode *pNewPlayer;
        PlayerNode *p, *q;
        pNewPlayer = new PlayerNode(player);
        p = pFirst; q = NULL;

        // p finds spot where new player should be added
        while (p != NULL && pNewPlayer->player > p->player) {
            q = p;
            p = p->next;
        }

        // if new element isn't last, set the next element's prev pointer to new element
        if (p) p->prev = pNewPlayer;
        // if new element is last, set pLast to new element
        else pLast = pNewPlayer;

        // if new element isn't first, set prev element's next pointer to new element
        if (q) q->next = pNewPlayer;
        // if new element is first, set pFirst to new element
        else pFirst = pNewPlayer;

        // set new element's next and prev pointers to p and q iterators respectively
        pNewPlayer->prev = q; pNewPlayer->next = p;
    
        // increment length and return true for success
        mLength++;
        return true;
    }

	bool PlayerList::remove(const Player &player) {
        // declare player node iterator pointers for element to be removed and its neighbors
        PlayerNode *p, *q, *r;
        p = pFirst; q = NULL; r = p->next;

        // iterate until p points to player with same name as passed player or reaches end of list
        while (p != NULL && p->player.compareName(player) != 0) {
            q = p; p = r; r = r->next;
        }

        // if p reaches end of list, return false for failure
        if (p == NULL) {return false;}

        // if neighbors exist, set prev and next pointers to each other to bypass removed element 
        if (q)  q->next = r; 
        if (r) r->prev = q;

        // if removed element is first or last, change first and last pointers to relevant neighbor
        if (pFirst == p) pFirst = r;
        if (pLast == p) pLast = q;

        // delete list element, decrement list, and return true for success
        delete p;
        mLength--;
        return true;
    }
    
	void PlayerList::clear() {
        PlayerNode *p; // Define temporary pointer p and set as first
        p = pFirst;

        while (p != NULL) { // While first node exists, move p and delete first
            p = pFirst->next;
            delete pFirst;
            pFirst = p; // Reset first pointer
        }
        mLength = 0; // Reset length
        pFirst = pLast = NULL; // Delete pointers
    }

    bool PlayerList::printForward(ostream &os) { start(); // restart iterator & declare temp player
        Player playerCurrent;
        // if list is empty, return false for failure
        if (isEmpty()) return false;
        // print header information
        os << setw(30) << "PLAYER NAME :" << setw(16) << "AVERAGE" << setw(13) << "OPS" <<endl;
        os << "------------------------------------------------------------" << endl;

        // while there are elements to get, write player info into temp player and iterate forward
        while (hasNext()) {
            getNext(playerCurrent);
            // print temp player's name, batting average, and OPS
            os << setw(28) << playerCurrent.getName() << " :";
            os << setw(15) << fixed << setprecision(3) << playerCurrent.getBatting();
            os << setw(15) << playerCurrent.getOPS() << endl;
        }
        // return true for success
        return true;
    }

    bool PlayerList::printBackward(ostream &os) { end(); // end iterator & declare temp player
        Player playerCurrent;
        // if list is empty, return false for failure
        if (isEmpty()) return false;
        // print header information
        os << setw(30) << "PLAYER NAME :" << setw(16) << "AVERAGE" << setw(13) << "OPS" <<endl;
        os << "------------------------------------------------------------" << endl;
        
        // while there are elements to get, write player info into temp player and iterate backward
        while (hasPrev()) {
            getPrev(playerCurrent);
            // print temp player's name, batting average, and OPS
            os << setw(28) << playerCurrent.getName() << " :";
            os << setw(15) << fixed << setprecision(3) << playerCurrent.getBatting();
            os << setw(15) << playerCurrent.getOPS() << endl;
        }
        // return true for success
        return true;
    }

    double PlayerList::getBattingAvg() {
        // create sum tracking variable and temp iterator
        double battingSum = 0;
        PlayerNode *p;
        p = pFirst;

        // move through list, adding batting average to sum as you go
        while (p != NULL) {
            battingSum += p->player.getBatting();
            p = p->next;
        }

        // divide sum by number of players and return value
        return battingSum / mLength;
    }