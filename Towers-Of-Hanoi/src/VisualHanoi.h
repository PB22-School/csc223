#include "hanoi.h"
#include "ncursesw/ncurses.h"
#include <vector>
using namespace std;

// My wrapper class with visualizations in ncurses

enum {
    WHITE = 50,
    RED,
    YELLOW,
    GREEN,
    CYAN,
    BLUE,
    MAGENTA
};

class VisualHanoi {
    TowersOfHanoi towerEngine;
    vector< vector<int> > columns;
    vector<Move>* moves;
    int moveIndex = 0;
    int n_disks;
    
    public:
    
    VisualHanoi(int n_disks);
    void reset(int n_disks);
    void drawUpdate(int width, int height);
};