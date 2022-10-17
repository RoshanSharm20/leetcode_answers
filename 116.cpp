/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    void connect1(Node *head)
    {
        if (head == NULL) // to check if root node is empty
            return;
        if (head->left)
            head->left->next = head->right;
        else
            return;
        connect1(head->left);
        if (head->next != NULL) // must exist
            head->right->next = head->next->left;
        connect1(head->right);
    }
    Node *connect(Node *root)
    {
        connect1(root);
        return root;
    }
};