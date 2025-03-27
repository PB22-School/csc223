#include "RGThings.h"
#include <iostream>
using namespace std;

bool valid_pair(RGTPair pair) {
    return (pair.thing1.color != pair.thing2.color) && (pair.thing1.color != Color::NONE && pair.thing2.color != Color::NONE);
}

bool RGThings::empty() {
    return size == 0;
}

void RGThings::insert(RGThing newThing) {
    for (int i = 0; i < size; i++) {
        RGTPair pair = queue[start + i];

        if (!valid_pair(pair)) {

            if (pair.thing1.color == Color::NONE) {
                pair.thing1.color = newThing.color;
                queue[start + i] = pair;
                size++;
                return;
            }
            else if (pair.thing1.color != newThing.color) {
                pair.thing2.color = newThing.color;
                queue[start + i] = pair;
                return;
            }
        } 
    }
}

RGTPair RGThings::remove() {
    for (int i = size - 1; i >= 0; i--) {
        RGTPair pair = queue[start + i];

        if (valid_pair(pair)) {
            queue[start + i] = RGTPair();
            size--;
            return pair;
        }
    }

    cout << "No Pair To Remove." << endl;
    return RGTPair();
}