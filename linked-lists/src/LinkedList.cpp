#include "LinkedList.h"
using namespace std;

string reverse(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        char original = str[i];
        str[i] = str[str.length() - (i + 1)];
        str[str.length() - (i + 1)] = original;
    }

    return str;
}

Node::Node()
{
    cargo = 0;
    next = nullptr;
}

Node::Node(int cargo)
{
    this->cargo = cargo;
    next = nullptr;
}

Node::Node(int cargo, Node* next)
{
    this->cargo = cargo;
    this->next = next;
}

string Node::to_string() const {

    if (!cargo) {
        return "0";
    }

    string str = "";
    int x = cargo;

    while (x) {
        str += (x % 10) + '0';
        x /= 10;
    }

    return reverse(str);

}

// LinkedList Stuff

LinkedList::LinkedList() {
    firstNode = nullptr;
}

string LinkedList::to_string() {
    if (firstNode == nullptr) {
        return "Empty list";
    }
    
    string out = "";

    out += firstNode->to_string();
    Node* nextNode = firstNode->next;
    
    while (nextNode) {
        out += " -> ";
        out += nextNode->to_string();
        nextNode = nextNode->next;
    }

    
}