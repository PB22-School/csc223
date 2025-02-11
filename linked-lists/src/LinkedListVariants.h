#include "LinkedList.h"

class OrderedList {
    Node* firstNode;

    public:

    OrderedList();

    string to_string() const;
    void insert(int x);
    Node* remove_at(int index);
};