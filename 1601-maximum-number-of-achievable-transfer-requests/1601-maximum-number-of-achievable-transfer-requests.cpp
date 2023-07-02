class Solution {
public:
    void solution(int start,int &end,vector<vector<int>> &requests,vector<int> &indegree,int &maxi,int count)
    {
        if(start==end)
        {
            for(int i=0;i<indegree.size();++i)
            {
                if(indegree[i]!=0)
                    return;
            }
            maxi=max(maxi,count);
            return;
        }
        
        //take case
        indegree[requests[start][0]]--;
        indegree[requests[start][1]]++;
        solution(start+1,end,requests,indegree,maxi,count+1);
        indegree[requests[start][0]]++;
        indegree[requests[start][1]]--;
        
        
        //nottake
        solution(start+1,end,requests,indegree,maxi,count);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        int x = requests.size();
        int maxi=0;
        vector<int> indegree(n,0);
        solution(0,x,requests,indegree,maxi,0);
        return maxi;
    }
};