//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseList(struct Node* head)
    {
        Node *prev=NULL,*curr=head,*nxt=NULL;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second);
        Node *dummy=new Node(-1);
        Node *ptr=dummy;
        int sum=0,carry=0;
        while(first && second)
        {
            sum=first->data+second->data+carry;
            int val = sum%10;
            carry=sum/10;
            Node *newnode=new Node(val);
            ptr->next=newnode;
            ptr=ptr->next;
            first=first->next;
            second=second->next;
        }
        
        while(first)
        {
            sum=first->data+carry;;
            int val = sum%10;
            carry=sum/10;
            Node *newnode = new Node(val);
            ptr->next = newnode;
            ptr=ptr->next;
            first=first->next;
        }
        
        while(second)
        {
            sum=second->data+carry;;
            int val = sum%10;
            carry=sum/10;
            Node *newnode = new Node(val);
            ptr->next = newnode;
            ptr=ptr->next;
            second=second->next;
        }
        
        if(carry>0)
        {
            Node *newnode = new Node(carry);
            ptr->next=newnode;
            ptr=ptr->next;
        }
        
        return reverseList(dummy->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends