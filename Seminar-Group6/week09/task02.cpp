#include<iostream>
#include<vector>
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int _key, Node* _left = nullptr, Node* _right = nullptr):key(_key), left(_left), right(_right){}
};
Node* buildFromRec(const std::vector<int>& v, int start, int end)
{
    if (end < start)
    {
        return nullptr;
    }
    
    int mid = (end - start) / 2 + start;
    
    return new Node(v[mid], buildFromRec(v, start, mid - 1), buildFromRec(v, mid + 1, end));
}
Node* buildFrom(const std::vector<int>& v)
{
    return buildFromRec(v, 0, v.size() - 1);
}
void clean(Node*& n) {
    if (n == nullptr) return;
    clean(n->left);
    clean(n->right);
    delete n;
}
void print(Node* n)
{
    if (n == nullptr)
    {
        return;
    }
    
    std::cout << n->key << " ";
    print(n->left);
    print(n->right);

}
int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    Node* test = buildFrom(v);
    
    print(test);

    clean(test); 

    return 0;
}