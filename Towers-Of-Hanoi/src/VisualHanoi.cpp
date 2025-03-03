#include "VisualHanoi.h"
#include "ncursesw/ncurses.h"
#include <ncurses.h>

VisualHanoi::VisualHanoi(int n_disks) : towerEngine(n_disks) {
    reset(n_disks);
    moves = towerEngine.getMoves();
}

void VisualHanoi::reset(int n_disks) {
    towerEngine.initializeSourceStack(n_disks);
}

bool VisualHanoi::drawUpdate() {
    return false;
}