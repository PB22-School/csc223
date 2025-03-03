#include "VisualHanoi.h"
#include <vector>
#include <unistd.h>
#include "ncursesw/ncurses.h"
using namespace std;

int main() {

    int n_disks = 8;

    VisualHanoi visual(n_disks);

    bool isRunning = true;

    while (isRunning) {

        if (visual.drawUpdate()) {

            int ch = getch();

            while (ch != ERR) {
                ch = getch();
            }

            n_disks++;
            visual.reset(n_disks);
            continue;

        }

        usleep(375);
    }

}