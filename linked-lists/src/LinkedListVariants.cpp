#include "LinkedListVariants.h"

OrderedList::OrderedList() {
    firstNode = nullptr;
}

string OrderedList::to_string() const {
    if (firstNode == nullptr) {
        return "Empty list";
    }

    string str = "";

    str += firstNode->to_string();
    Node* nextNode = firstNode->next;

    while (nextNode) {
        str += " -> ";
        str += nextNode->to_string();
        nextNode = nextNode->next;
    }

    return str;
}

void OrderedList::insert(int x) {

    Node* node = new Node(x);

    if (firstNode == nullptr) {
        firstNode = node;
        return;
    }

    Node* lastNode = nullptr;
    Node* nextNode = firstNode;

    while (nextNode) {
        if (nextNode->cargo > node->cargo) {
            lastNode = nextNode;
            nextNode = nextNode->next;
        }
        else {
            // nextNode->cargo <= x
            // so we insert
            node->next = nextNode;

            if (lastNode) {
                lastNode->next = node;
                return;
            }
            
            firstNode = node;
            return;
        }
    }

    lastNode->next = node;
}

Node* OrderedList::remove_at(int index) {

    index--;
    
    Node* lastNode = firstNode;
    Node* nextNode = firstNode;
    while (index >= 0) {
        lastNode = nextNode;
        nextNode = nextNode->next;
        index--;
    }

    lastNode->next = nextNode->next;
    return nextNode;
}