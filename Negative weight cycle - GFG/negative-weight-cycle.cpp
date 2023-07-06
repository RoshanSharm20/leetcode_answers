//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> distance(n,1e9);
	    for(int i=0;i<n-1;++i)
	    {
	        for(int i=0;i<edges.size();++i)
	        {
	            int u=edges[i][0];
	            int v=edges[i][1];
	            int cost=edges[i][2];
	            if(distance[u]+cost<distance[v])
	            {
	                distance[v]=distance[u]+cost;
	            }
	        }
	    }
	    
	    for(int i=0;i<edges.size();++i)
	    {
	       int u=edges[i][0];
            int v=edges[i][1];
            int cost=edges[i][2];
            if(distance[u]+cost<distance[v])
            {
                return 1;
            } 
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends