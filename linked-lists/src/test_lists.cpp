#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "LinkedList.h"
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