#include "VisualHanoi.h"
#include "ncursesw/ncurses.h"
#include <vector>
#include <unistd.h>
#include <locale.h>
#include <iostream>
using namespace std;

double getCurrentMs() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

int main() {

    // TowersOfHanoi towers(8);
    // towers.solve();

    // vector<Move> *moves = towers.getMoves();

    // cout << "had " << moves->size() << " moves.\n";

    // for (int i = 0; i < 10; i++) {
    //     cout << "Moved " << moves->at(i).from << " To " << moves->at(i).to << ".\n";
    // }

    // return 0;

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();
    timeout(0);
    curs_set(0);
    keypad(stdscr, TRUE);

    int n_disks = 8;

    VisualHanoi visual(n_disks);

    bool isRunning = true;

    // in ms
    const double drawTime = 1000;
    double lastTime = getCurrentMs();
    double drawIter = 1000;

    int lastScreenWidth;
    int lastScreenHeight;

    int screenWidth;
    int screenHeight;

    while (isRunning) {

        lastScreenHeight = screenHeight ? screenHeight : -1;
        lastScreenWidth = screenWidth ? screenWidth : -1;

        getmaxyx(stdscr, screenHeight, screenWidth);

        int towerSize = ((n_disks + 1) * 2) + 1;
        int spaceLeft = screenWidth - (towerSize * 3);

        if ((lastScreenHeight != screenHeight && lastScreenWidth != screenWidth)
             && (screenHeight < n_disks || spaceLeft < 0)) {
            
            // if the visualization didn't have enough size

            clear();

            string errorMessage = "Size Too Small. Resize Terminal!";

            int messageX = (screenWidth / 2) - errorMessage.length();

            if (messageX < 0) {
                messageX = 0;
            }

            mvaddstr(screenHeight / 2, messageX, errorMessage.c_str());

            refresh();
            continue;

        }
        // else if (screenHeight < n_disks || spaceLeft < 0) {
        //     continue;
        // }

        drawIter += getCurrentMs() - lastTime;
        lastTime = getCurrentMs();

        // if enough time has passed to re-draw
        if (drawIter > drawTime) {

            drawIter = 0;

            // not really necessary, but the hanoi visualization will resize with this.
            getmaxyx(stdscr, screenHeight, screenWidth);

            clear();

            visual.drawUpdate(screenWidth, screenHeight);

            refresh();
        }
    }

    endwin();

}