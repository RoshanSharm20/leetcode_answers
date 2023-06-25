//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool mycomp(Job a,Job b)
    {
        if(a.profit>b.profit)
            return true;
        else if(a.profit==b.profit)
        {
            if(a.dead<b.dead)
                return true;
            else
                return false;
        }
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,mycomp);
        int max_dead=0;
        for(int i=0;i<n;++i)
        {
            max_dead=max(max_dead,arr[i].dead);
        }
        vector<int> index(max_dead+1,-1);
        int count=0,prof=0;
        for(int i=0;i<n;++i)
        {
            if(index[arr[i].dead]==-1)
            {
                index[arr[i].dead]=arr[i].id;
                count++;
                prof+=arr[i].profit;
            }
            else
            {
                int j=arr[i].dead-1;
                while(j>=1)
                {
                    if(index[j]==-1)
                    {
                        index[j]=arr[i].id;
                        count++;
                        prof+=arr[i].profit;
                        break;
                    }
                    j--;
                }
            }
        }
        vector<int> ans={count,prof};
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends