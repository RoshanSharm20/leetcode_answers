class Solution {
public:
    int solution(int index,vector<int>& arr,int& k,vector<int>& dp)
    {
        if(index==arr.size())
            return 0;
        int n = arr.size();
        if(dp[index]!=-1)
            return dp[index];
        int max_ans=-1e9,max_val=0,len=0;
        for(int i=index;i<min(n,index+k);++i)
        {
            len++;
            max_val=max(max_val,arr[i]);
            int ans=(max_val*len)+solution(i+1,arr,k,dp);
            max_ans=max(max_ans,ans);
        }
        return dp[index]=max_ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        vector<int> dp(arr.size(),-1);
        return solution(0,arr,k,dp);
    }
};