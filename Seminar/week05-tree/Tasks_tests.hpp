#include <iostream>
#include "func_tree.hpp"

using namespace std;

void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}

TEST_CASE("Validate countElements") {
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);

    CHECK(countElements(nullptr) == 0);
    CHECK(countElements(test) == 4);
    test->left->left->right = new Node(18);
    CHECK(countElements(test) == 5);
    clean(test);
}

TEST_CASE("Validate countLeafs") {
    Node* test = new Node(5);
    test->left = new Node(7);
    test->right = new Node(7);
    test->left->left = new Node(14);
    CHECK(countLeafs(nullptr) == 0);
    CHECK(countLeafs(test) == 2);
    test->left->left->right = new Node(18);
    test->left->left->left = new Node(20);
    CHECK(countLeafs(test) == 3);
    clean(test);
}