#include <iostream>
#include <vector>
using namespace std;

// http://poj.org/problem?id=1059

struct ChuteLadder {
    int start, end; // Start and end positions
};

struct Player {
    int pos; // Position on the board
    bool skip; // Skip next turn
};

int abs (int n); // Absolute value function

int main() {
    vector<int> throws; // Dice throws
    vector<int> winners; // List of winners from each game

    // Get the dice rolls
    bool done = false;
    while(!done) {
        int roll;
        cin >> roll;
        if (roll == 0) done = true;
        else throws.push_back(roll);
    }

    while (true) {
        vector<ChuteLadder> chtLd; // chutes and ladders
        vector<int> skpExt; // Skip/Extra turn positions
        int nPlayers;    // Number of players
        int turn = 0; // Current turn

        // Get the number of players
        cin >> nPlayers;

        // If we're given 0, then we're done
        if (nPlayers == 0) break;

        // Generate the player list
        Player *players = new Player[nPlayers]; // Allocate the array

        // Fill the array
        for(int  i = 0; i < nPlayers; i++) {
            Player ply;
            ply.pos = 0; // Players start at 0
            ply.skip = false;
            players[i] = ply;
        }

        // Get the positions of the chutes and ladders
        done = false;
        while(!done) {
            int start, end;
            cin >> start >> end;

            if(start == 0 && end == 0) {
                // If both the start and end are 0 then the list is done
                done = true;
            } else {
                ChuteLadder cl;
                cl.start = start;
                cl.end = end;
                chtLd.push_back(cl);
            }
        }

        // Get the position of the skip/extra turn places
        done = false;
        while(!done) {
            int pos;
            cin >> pos;

            if(pos == 0) {
                done = true;
            } else {
                skpExt.push_back(pos);
            }
        }

        // Simulate the game
        for(int i = 0; i < throws.size(); i++) {
            if (players[turn].skip) {
                players[turn].skip = false;
            } else if (players[turn].pos + throws[i] <= 100) {

                // Increase their position by the number they rolled
                players[turn].pos += throws[i];

                if (players[turn].pos == 100) {
                    // If someone reached place 100, then they won. End the simulation
                    break;
                }

                // Check if they landed on a chute or ladder
                for(int j = 0; j < chtLd.size(); j++) {
                    if(players[turn].pos == chtLd[j].start) {

                        // Move the player to the end of the chute/ladder
                        players[turn].pos = chtLd[j].end;
                        break;
                    }
                }

                // Check if they landed on a skip/extra turn
                for(int j = 0; j < skpExt.size(); j++) {
                    if(players[turn].pos == abs(skpExt[j])) {
                        if(skpExt[j] < 0) {
                            players[turn].skip = true; // Indicate that the player skips their next turn
                        } else {
                            turn--; // Give the player another turn
                        }                
                    }
                }
            }


            turn++; // Move to the next player
            if (turn >= nPlayers) {
                // Go back to the first player
                turn = 0;
            }
        }

        // Add the winner to our list of winners
        winners.push_back(turn + 1);
    }
    
    // Output the winners
    for (int i = 0; i < winners.size(); i++) {
        cout << winners[i] << endl;
    }

    return 0;
}

// Absolute value function
int abs (int n) {
    if (n < 0) return -n;
    return n;
}
