class Solution {
public:
    int dp[10005];
    static bool myComp(pair<int,int> &A,pair<int,int> &B)
    {
        if(A.first==B.first)
            return A.second>B.second;
        return A.first<B.first;
    }
    
    int solution(int index,int last,int &n,vector<pair<int,int>> &vect)
    {
        if(vect[index].first>last)
            return 1e9;
        if(last>=n || index==n)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        int ans = 1e9;
        last=max(last,vect[index].second);
        if(last>=n) return 1;
        for(int i=index+1;i<n;++i)
        {
            if(vect[i].first>last)
                break;
            ans=min(ans,1+solution(i,last,n,vect));
        }
        
        return dp[index]=ans;
    }
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<pair<int,int>> vect;
        for(int i=0;i<ranges.size();++i)
        {
            vect.push_back({max(0,i-ranges[i]),i+ranges[i]});
        }
        
        sort(vect.begin(),vect.end(),myComp);
        memset(dp,-1,sizeof(dp));
        
        int ans=n+10;
        ans=min(ans,solution(0,0,n,vect));
        if(ans>n) return -1;
        return ans;
    }
};