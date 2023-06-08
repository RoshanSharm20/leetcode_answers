//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) 
{
    int sum=0,start=-1,end=-1;
    for(int i=0;i<n-1;++i)
    {
        if(price[i+1]-price[i]>0)
        {
            sum+=(price[i+1]-price[i]);
            if(start==-1)
            {
                start=i;
            }
        }
        else if(start!=-1)
        {
            cout<<"("<<start<<" "<<i<<") ";
            start=-1;
        }
    }
    if(start>-1)
        cout<<"("<<start<<" "<<n-1<<")";
    if(sum==0)
        cout<<"No Profit";
    cout<<"\n";
}