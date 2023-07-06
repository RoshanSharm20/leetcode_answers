//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
	    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> nodes;
	    nodes.push({0,{k[0],k[1]}});
	    visited[k[0]][k[1]]=true;
	    while(!nodes.empty())
	    {
	        auto it = nodes.top();
	        nodes.pop();
	        int steps=it.first;
	        int row=it.second.first;
	        int col=it.second.second;
	        if(row==t[0] && col==t[1])
	            return steps;
	        vector<int> delrow={-1,-2,-2,-1,1,2,2,1};
	        vector<int> delcol={-2,-1,1,2,2,1,-1,-2};
	        for(int i=0;i<8;++i)
	        {
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            
	            if(nrow>=1 && nrow<=N && ncol>=1 && ncol<=N && !visited[nrow][ncol])
	            {
	                visited[nrow][ncol]=true;
	                nodes.push({steps+1,{nrow,ncol}});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends