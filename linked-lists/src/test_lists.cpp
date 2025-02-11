#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "LinkedListVariants.h"
using namespace std;

string render_list(Node* node) {

    string str = "";

    while (node->next != nullptr) {
        str += node->to_string() + ", ";
        node = node->next;
    }

    str += node->to_string();
    return str;

}

string render_list_backward(Node* node) {

    string str = "";
    vector<string> cargos;

    while (node->next != nullptr) {
        cargos.push_back(node->to_string());
        node = node->next;
    }

    cargos.push_back(node->to_string());

    for (int i = cargos.size() - 1; i > 0; i--) {
        str += cargos[i] + ", ";
    }

    return str + cargos[0];

}

string render_pretty(Node* node, string func(Node*)) {
    string output = func(node);
    return '(' + output + ')';
}

Node* remove_second(Node* node) {
    
    Node* node2 = node->next;

    node->next = node2->next;
    node2->next = nullptr;
    return node2;
}

TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
}

TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
    Node* node2 = new Node(42);
    CHECK(node2->cargo == 42);
    CHECK(node1->to_string() == "0");
    CHECK(node2->to_string() == "42");
}

TEST_CASE("Test can link nodes together") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    CHECK(node2->next == node1);
    CHECK(node3->next == node2);
    CHECK(node3->next->next == node1);
}

TEST_CASE("Test can display linked nodes") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    CHECK(render_list(node3) == "3, 2, 1");
}

TEST_CASE("Test can display linked nodes backwards") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(render_list(node4) == "4, 3, 2, 1");
    CHECK(render_list_backward(node4) == "1, 2, 3, 4");
}

TEST_CASE("Test can display linked nodes with parenthesis") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(render_pretty(node4, &render_list) == "(4, 3, 2, 1)");
    CHECK(render_pretty(node4, &render_list_backward) == "(1, 2, 3, 4)");
}

TEST_CASE("Test can remove second node in linked list") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    
    Node* node2_extraPointer = remove_second(node3);
    CHECK(node2_extraPointer->to_string() == node2->to_string());
    CHECK(node3->next == node1);
    CHECK(render_pretty(node3, &render_list) == "(3, 1)");
}

TEST_CASE("Test can create empty linked list") {
    LinkedList list;
    CHECK(list.to_string() == "Empty list");
    list.insert_in_front(5);
    CHECK(list.to_string() == "5");
    list.insert_in_front(42);
    CHECK(list.to_string() == "42 -> 5");
    list.insert_in_front(9);
    CHECK(list.to_string() == "9 -> 42 -> 5");
}

TEST_CASE("Test can remove first element from linked list") {
    LinkedList list;
    list.insert_in_front(10);
    list.insert_in_front(5);
    CHECK(list.to_string() == "5 -> 10");
    list.remove_from_front();
    CHECK(list.to_string() == "10");
    list.remove_from_front();
    CHECK(list.to_string() == "Empty list");
}

TEST_CASE("Test Ordered Linked Lists") {
    OrderedList orderedList;
    orderedList.insert(10);
    orderedList.insert(14);
    orderedList.insert(5);
    orderedList.insert(2);
    orderedList.insert(21);
    orderedList.insert(2000);
    orderedList.insert(0);

    CHECK(orderedList.to_string() == "2000 -> 21 -> 14 -> 10 -> 5 -> 2 -> 0");

    Node* removedNode = orderedList.remove_at(2);

    CHECK(removedNode->to_string() == "14");

}