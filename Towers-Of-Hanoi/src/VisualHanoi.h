#include "hanoi.h"
#include <vector>
using namespace std;

// My wrapper class with visualizations in ncurses

class VisualHanoi {
    TowersOfHanoi towerEngine;
    vector<int> columns[3];
    vector<Move>* moves;
    
    public:

    VisualHanoi(int n_disks);
    void reset(int n_disks);
    bool drawUpdate();
};