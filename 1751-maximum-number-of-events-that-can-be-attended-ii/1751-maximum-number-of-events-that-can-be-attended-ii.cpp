class Solution {
public:
    int getindex(vector<vector<int>> &events,int index)
    {
        int low=index+1,high=events.size()-1;
        int ans=events.size();
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(events[mid][0]>events[index][1])
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    int solution(int index,int k,vector<vector<int>> &dp,vector<vector<int>> &events)
    {
        if(k==0) return 0;
        if(index==events.size())
            return 0;
        if(dp[index][k]!=-1)
            return dp[index][k];
        int ind=getindex(events,index);
        int pick = events[index][2]+solution(ind,k-1,dp,events);
        int notpick=solution(index+1,k,dp,events);
        return dp[index][k]=max(pick,notpick);
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solution(0,k,dp,events);
    }
};