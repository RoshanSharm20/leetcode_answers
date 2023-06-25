//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool mycomp(pair<double,Item> a,pair<double,Item> b)
    {
        if(a.first>b.first)
            return true;
        else if(a.first==b.first)
        {
            if(a.second.weight<=b.second.weight)
                return true;
            else
                return false;
        }
        return false;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>> nodes;
        for(int i=0;i<n;++i)
        {
            double vpw=(double)arr[i].value/arr[i].weight;
            nodes.push_back({vpw,arr[i]});
        }
        sort(nodes.begin(),nodes.end(),mycomp);
        int allowed=W,i=0;
        double profit=0;
        while(allowed>0 && i<n)
        {
            if(nodes[i].second.weight<=allowed)
            {
                profit+=nodes[i].second.value;
                allowed-=nodes[i].second.weight;
                i++;
            }
            else
            {
                profit+=(allowed*nodes[i].first);
                allowed=0;
                break;
            }
        }
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends