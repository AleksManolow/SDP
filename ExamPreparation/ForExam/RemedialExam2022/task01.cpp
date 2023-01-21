#include <iostream>
 
using namespace std;
 
// class to represent the
// node of a linked list

struct Node
{
    int data;
    Node *next;
 
    Node(int data): data(data), next(NULL) {}
};
 
Node* insert_at_head(Node *head, int data)
{
    // base case
    if(head == NULL)
    {
        head = new Node(data);
        return head;
    }
 
    // otherwise
    Node *temp = head;
    head = new Node(data);
    head->next = temp;
 
    return head;
}
 
Node* merge(Node* a, Node* b)
{
    // base case
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
 
    // recursive case
    // take a head pointer
    Node* c;
 
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
 
    return c;
}
 
Node* mid_point(Node* head)
{
    // base case
    if(head == NULL || head->next == NULL)
        return head;
 
    // recursive case
    Node* fast = head;
    Node* slow = head;
 
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
 
        if(fast->next == NULL)
            break;
 
        fast = fast->next;
        slow = slow->next;
    }
 
    return slow;
}
 
Node* merge_sort(Node* head)
{
    // base case
    if(head == NULL || head->next == NULL)
        return head;
 
    // recursive case
    // Step 1: divide the linked list into
    // two equal linked lists
    Node* mid = mid_point(head);
    Node* a = head;
    Node* b = mid->next;
 
    mid->next = NULL;
 
    // Step 2: recursively sort the smaller
    // linked lists
    a = merge_sort(a);
    b = merge_sort(b);
 
    // Step 3: merge the sorted linked lists
    Node* c = merge(a, b);
 
    return c;
}
 
void print_linked_list(Node* head)
{
    cout << "Head <- ";
 
    while(head != NULL)
    {
        cout << head->data << " <-- ";
        head = head->next;
    }
    cout << "Tail" << endl;
 
    return;
}
 
int main()
{
    cout << "Enter the elements of the linked list, press -1 to stop" << endl;
    Node *head = NULL;
 
    while(true)
    {
        int ele;
        cin >> ele;
 
        if(ele == -1)
        {
            break;
        }
 
        head = insert_at_head(head, ele);
    }
 
    cout << "The original linked list is:" << endl;
    print_linked_list(head);
 
    cout << "Linked list after sorting is:" << endl;
    head = merge_sort(head);
    print_linked_list(head);
 
    return 0;
}