#include <string>
using namespace std;

struct Node {
    int cargo;
    Node* next;

    // constructors
    Node();
    Node(int);
    Node(int, Node*);

    string to_string() const;
};

class LinkedList {
    Node* firstNode;

    public:

    string to_string() const;
    void insert_in_front(int x);
};