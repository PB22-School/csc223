#pragma once
#include <string>
using namespace std;

template <class T>
struct Node {
    T cargo;
    Node* next;

    // constructors
    Node();
    Node(T);
    Node(T, Node*);

    string to_string() const;
};

template <class T>
class LinkedList {
    Node<T>* firstNode;

    public:

    LinkedList();

    string to_string() const;
    void insert_in_front(T x);
    void remove_from_front();
};