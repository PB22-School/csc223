#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// This is Marin's Code (Thanks Marin)
// I altered it a bit though

struct Move {
    int from;
    int to;
    Move(int f, int t) {
        from = f;
        to = t;
    }
};

class TowersOfHanoi {
private:

    enum {
        SOURCE,
        AUXILARY,
        DESTINATION
    };
    
    stack<int> stacks[3];       // Source, Aux, Destination
    vector<Move> moves;       // Stores the sequence of moves
    
    // Private helper function to move a disk
    void moveDisk(Move move) {
        int disk = stacks[move.from].top();
        stacks[move.from].pop();
        stacks[move.to].push(disk);
        
        moves.push_back(move);
    }
    
    // Private recursive function to solve the Towers of Hanoi problem
    void hanoi(int n, int source, int auxiliary, int destination) {
        if (n == 1) {
            moveDisk(Move(source, destination));
            return;
        }
        
        hanoi(n - 1, source, destination, auxiliary);
        moveDisk(Move(source, destination));
        hanoi(n - 1, auxiliary, source, destination);
    }
    
    public:

    // Constructor to initialize the source stack with disks
    TowersOfHanoi(int n) {
        initializeSourceStack(n);
    }

    // Initialize the source stack with disks
    void initializeSourceStack(int n) {
        for (int i = n; i >= 1; --i) {
            stacks[SOURCE].push(i);
        }
    }

    // Solve the Towers of Hanoi problem
    void solve() {
        hanoi(stacks[SOURCE].size(), SOURCE, AUXILARY, DESTINATION);
    }

    vector<Move>* getMoves() {
        return &moves;
    }
};