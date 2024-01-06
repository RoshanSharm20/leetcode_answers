class Solution {
public:
    int solution(int index,vector<int>& startTime,vector<pair<pair<int,int>,int>>& nodes,vector<int> &dp)
    {
        if(index>=startTime.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        
        int i = lower_bound(startTime.begin(),startTime.end(),nodes[index].first.second)-startTime.begin();
        
        int pick = nodes[index].second + solution(i,startTime,nodes,dp);
        int notpick = solution(index+1,startTime,nodes,dp);
        
        return dp[index]=max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<pair<pair<int,int>,int>> nodes;
        for(int i=0;i<startTime.size();++i)
        {
            nodes.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        vector<int> dp(startTime.size(),-1);        
        sort(nodes.begin(),nodes.end());
        sort(startTime.begin(),startTime.end());
        return solution(0,startTime,nodes,dp);
    }
};