/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    vector<int> v; // to store the values of list nodes
    void getNext(Node *head)
    {
        if (!head)
            return;
        v.push_back(head->val);
        getNext(head->next);
    }
    void insertValue(Node *head)
    {
        if (head == NULL)
            return;
        v.push_back(head->val);
        if (head->child) // if child node exist,move on next node
            insertValue(head->child);
        else
            insertValue(head->next); // otherwise move on the next node
        // now we need to traverse from the node where it branched off to child node
        if (head->child) // if at the child node existed then we process the next list node
            getNext(head->next);
    }
    Node *flatten(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        insertValue(head);
        Node *ptr = new Node();
        ptr = head;
        for (int i = 0; i < v.size(); ++i)
        {
            Node *temp = new Node(v[i]);
            temp->child = NULL;
            ptr->next = temp;
            temp->prev = ptr;
            ptr = ptr->next;
        }
        Node *node = head->next;
        node->prev = nullptr;
        return node;
    }
};