class Solution {
public:
    bool solution(int index,int prev_jump,vector<int> &stones,vector<vector<int>> &dp)
    {
        if(index==stones.size()-1)
            return true;
        
        
        if(dp[index][prev_jump]!=-1)
            return dp[index][prev_jump];
        bool isPossible=false;
        
        if(index==0)
        {
            if(stones[1]-stones[0]==1)
                isPossible=isPossible|solution(1,1,stones,dp);
        }
        else
        {    
            for(int i=index+1;i<stones.size();++i)
            {
                if(stones[i]-stones[index]>prev_jump+1)
                    break;

                if(stones[i]-stones[index]==prev_jump-1)
                    isPossible=isPossible|solution(i,prev_jump-1,stones,dp);
                else if(stones[i]-stones[index]==prev_jump)
                    isPossible=isPossible|solution(i,prev_jump,stones,dp);
                else if(stones[i]-stones[index]==prev_jump+1)
                    isPossible=isPossible|solution(i,prev_jump+1,stones,dp);
            }
        }
        return dp[index][prev_jump]=isPossible;
    }
    bool canCross(vector<int>& stones) 
    {
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        return solution(0,1,stones,dp);
    }
};