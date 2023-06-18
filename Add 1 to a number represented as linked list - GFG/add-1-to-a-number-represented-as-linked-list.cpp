//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int adding(Node *head)
    {
        if(!head->next)
        {
            int val = (head->data+1)%10;
            int carry = (head->data+1)/10;
            head->data = val;
            return carry;
        }
        int res = adding(head->next);
        int val = (head->data+res)%10;
        int carry = (head->data+res)/10;
        head->data=val;
        return carry;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        int res = adding(head);
        if(res>0)
        {
            Node *newnode = new Node(res);
            newnode->next=head;
            head=newnode;
            return head;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends