#include "VisualHanoi.h"
#include "ncursesw/ncurses.h"
#include <ncurses.h>

VisualHanoi::VisualHanoi(int n_disks) : towerEngine(n_disks) {
    this->n_disks = n_disks;
    moves = towerEngine.getMoves();
    reset(n_disks);

    init_pair(WHITE, COLOR_BLACK, COLOR_WHITE);
    init_pair(RED, COLOR_BLACK, COLOR_RED);
    init_pair(YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair(GREEN, COLOR_BLACK, COLOR_GREEN);
    init_pair(CYAN, COLOR_BLACK, COLOR_CYAN);
    init_pair(BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair(MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
}

void VisualHanoi::reset(int n_disks) {
    this->n_disks = n_disks;
    towerEngine.initializeSourceStack(n_disks);
    towerEngine.solve();

    for (int i = 0; i < 3; i++) {
        columns.push_back(vector<int>());
    }

    for (int i = 0; i < n_disks; i++) {
        columns[0].push_back(n_disks - i);
    }
}

void VisualHanoi::drawUpdate(int width, int height) {

    int sizeOfTower = ((n_disks + 1) * 2) + 1;

    int xSep = width / 4;
    int yOffset = (height / 2) + (n_disks / 2);

    //  xSep       xSep       xSep       xSep
    // ------  |  ------  |  ------  |  ------
    //       tower 1    tower 2    tower 3

    for (int i = 0; i < columns.size(); i++) {

        int towerCenter = xSep * (i + 1);

        color_set(WHITE, nullptr);
        mvhline(yOffset, towerCenter - (n_disks + 1), ' ', sizeOfTower);
        mvvline(yOffset - (n_disks + 1), towerCenter, ' ', n_disks + 1);

        for (int j = 0; j < columns[i].size(); j++) {

            //   - towerCenter
            //   |
            //  x|x         x|x
            // xx|xx  x|x  xx|xx
            // ----- ----- -----

            color_set((columns[i][j] % 6) + RED, nullptr);

            mvhline(yOffset - (j + 1), towerCenter - columns[i][j], ' ', (columns[i][j] * 2) + 1);
        }
    }

    if (moveIndex >= moves->size()) {
        return;
    }

    Move curMove = moves->at(moveIndex);
    int thingToMove = columns[curMove.from][columns[curMove.from].size() - 1];
    columns[curMove.from].pop_back();
    columns[curMove.to].push_back(thingToMove);
    moveIndex++;
    
}