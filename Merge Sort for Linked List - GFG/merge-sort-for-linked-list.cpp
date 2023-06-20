//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* findMid(Node *head)
    {
        Node *slow=head,*fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node *left,Node *right)
    {
        if(!left)
            return right;
        if(!right)
            return left;
        Node *ans=new Node(-1);
        Node *ptr=ans;
        while(left && right)
        {
            if(left->data<=right->data)
            {
                ptr->next=left;
                ptr=ptr->next;
                left=left->next;
            }
            else
            {
                ptr->next=right;
                ptr=ptr->next;
                right=right->next;
            }
        }
        while(left)
        {
            ptr->next=left;
            ptr=ptr->next;
            left=left->next;
        }
        while(right)
        {
            ptr->next=right;
            ptr=ptr->next;
            right=right->next;
        }
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        if(!head || !head->next)
            return head;
        Node *mid = findMid(head);
        Node *left=head,*right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        return merge(left,right);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends