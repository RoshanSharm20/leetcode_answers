/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* iter=head,*front=head;
        while(front)
        {
            front=iter->next;
            Node *copy = new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        while(iter)
        {
            if(iter->random!=NULL)
                iter->next->random=iter->random->next;
            iter=iter->next->next;
        }
        Node *dummy=new Node(-1);
        Node *ptr=dummy;
        iter=head;
        while(iter)
        {
            front=iter->next->next;
            ptr->next=iter->next;
            ptr=ptr->next;
            iter->next=front;
            iter=iter->next;
        }
        return dummy->next;
    }
};