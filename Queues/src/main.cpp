#include "PriorityQueue.h"
#include <iostream>
using namespace std;

int main() {
    PriorityQueue<int> prioqueue;

    prioqueue.insert(100);
    prioqueue.insert(20);
    prioqueue.insert(66);
    prioqueue.insert(123);
    prioqueue.insert(12);
    prioqueue.insert(500);

    int start_size = prioqueue.get_size();

    for (int i = 0; i < start_size; i++) {
        cout << "index {" << start_size - i << "} : " << prioqueue.pop() << endl;
    }
}