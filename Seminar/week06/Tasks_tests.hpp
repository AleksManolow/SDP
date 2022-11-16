#include <iostream>
#include "func_tree.hpp"

using namespace std;

void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}

TEST_CASE("Validate isContains") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    CHECK(isContains(test, 140) == true);
    CHECK(isContains(test, 25) == true);
    CHECK(isContains(test, 0) == false);
    CHECK(isContains(test, 150) == false);
    clean(test);
}

TEST_CASE("Validate getMin") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);

    CHECK(getMin(test)->key == 25);
    test->left->left->left = new Node(5);
    CHECK(getMin(test)->key == 5);

    clean(test);
}
TEST_CASE("Validate getMax") {

    Node* test = new Node(100);
    test->left = new Node(50);
    test->right = new Node(140);
    test->left->left = new Node(25);
    CHECK(getMax(test)->key == 140);
    test->right->right = new Node(180);
    CHECK(getMax(test)->key == 180);

    clean(test);
}
