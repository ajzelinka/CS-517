// File Player.cpp

#include "Player.h"

/*
---------------------------------------------------------------------------------------------------
Implementation File - Class: Player
---------------------------------------------------------------------------------------------------
*/

    // Default constructor used when no data is provided
    Player::Player() {mFirst = "Unknown"; mLast = "Unknown";
        for (int i = 0; i < 8; i++)
            mStats[i] = 0;
    }
    // Constructor with passed parameters.
    Player::Player(string first, string last, int stats[]) {
        mFirst = first;
        mLast = last;
        for (int i = 0; i < 8; i++)
            mStats[i] = stats[i];
    }

    // Read input stream - single line, assumed valid or blank
    bool Player::readInput(istream &input) {       
        // Get string from istream
        string nextLine;
        getline(input, nextLine);

        // Return false if line is blank
        if (nextLine.size() <= 0)
            return false;
        // If line isn't blank, read names from an sstream of the line
        else {
            stringstream ss(nextLine);
            ss >> mFirst;
            ss >> mLast;
            // Iterate through array to assign values
            for (int i = 0; i < 8; i++)
                ss >> mStats[i];
            // Return true to show successful addition of another player
            return true;
        }
    }

    // Compare last names, use first names in event of a tie
    int Player::compareName(Player player) {
        if (mLast.compare(player.mLast) == 0)
            return mFirst.compare(player.mFirst);
        else return mLast.compare(player.mLast);
    }

    // Return Last, First name of the player
    string Player::getName() { return mLast + ", " + mFirst; }

    // Sum all singles, doubles, triples, and home runs
    double Player::getHits() { return double(mStats[2] + mStats[3] + mStats[4] + mStats[5]); }
    // Divide all hits by at bats
    double Player::getBatting() { return getHits() / (mStats[1]); }
    // Add walks and hits by pitch to the total hits, and divide by plate appearances
    double Player::getOBP() { return (getHits() + mStats[6] + mStats[7]) / mStats[0]; }
    // Calculate weighted average, then divide by at bats
    double Player::getSlugging() {
        double weighted = mStats[2] + (2 * mStats[3]) + (3 * mStats[4]) + (4 * mStats[5]);
        return weighted / mStats[1];
    }

    // Add OBP and slugging average together
    double Player::getOPS() { return getOBP() + getSlugging(); }

    // Compare name shortcuts
    bool Player::operator<(const Player &p) {
        return compareName(p) < 0;
    }
    bool Player::operator>(const Player &p) {
        return compareName(p) > 0;
    }