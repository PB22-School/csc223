#include <stdexcept>
#include <iostream>
using namespace std;

typedef unsigned char u8;
const int MAX_SIZE = 50;

// class using a C array for data storage

template <class T>
struct Node {
    T cargo;
    Node* next;
};


// Highest priority items are at the end (so it's easy to pop)
// 0 1 2 3 4 5 6 7 8
// size 9

template <class T>
class PriorityQueue {
    T data[MAX_SIZE];
    u8 size;

    public:

    PriorityQueue() { size = 0; }

    void insert(T cargo) {

        if (size >= MAX_SIZE) {
            throw runtime_error("MAX SIZE ACHIEVED WITH QUEUE.");
        }

        for (int i = 0; i < size; i++) {

            // if cargo > data[i], put it after

            if (cargo <= data[i]) {

                // if cargo <= data[i],
                // put it at the current index

                for (int j = size - 1; j >= i; j--) {

                    cout << "shifted " << j << " to " << j + 1 << endl;

                    T idx_val = data[j];
                    data[j + 1] = idx_val;
                }

                cout << cargo << " to (shift-insert) " << i << endl;

                data[i] = cargo;
                size++;
                return;

            }
        }

        cout << cargo << " to (size) " << int(size) << endl;

        // if it's empty or if cargo is higher priority than everything else
        data[size] = cargo;
        size++;

    }

    T pop() {
        if (is_empty()) {
            throw runtime_error("TRYING TO POP FROM AN EMPTY QUEUE.");
        }
    
        size--;
        T popVal = data[size];
        return popVal;
    }

    u8 get_size() { return size; };

    bool is_empty() { return size == 0; };
    
};