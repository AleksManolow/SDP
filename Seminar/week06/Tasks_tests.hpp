#include <iostream>
#include "func_tree.hpp"

using namespace std;

void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
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
