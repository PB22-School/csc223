#include "LinkedList.h"

template <class T>
class OrderedList {
    Node<T>* firstNode;

    public:

    OrderedList();

    string to_string() const;
    void insert_item(T x)
    Node<T>* remove_at(int index);
};

template <class T>
struct DoubleNode {
    Node<T>* front;
    Node<T>* back;
};

template <class T>
class DoublyLinkedList {
    DoubleNode<T>* firstNode;

    public:

    DoublyLinkedList();

    string to_string() const;
    void 
};

template <class T>
class CircularList {
    Node* firstNode;

    public:

    string to_string() const;

}