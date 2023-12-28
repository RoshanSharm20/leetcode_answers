class Solution {
public:
    vector<int> solution(int n)
    {
        if(n==1)
            return {0,1};
        
        vector<int> ans;
        auto it = solution(n-1);
        ans=it;
        reverse(it.begin(),it.end());
        
        for(int i=0;i<it.size();++i)
        {
            int x = it[i]+(1<<(n-1));
            ans.push_back(x);
        }
        return ans;
    }
    vector<int> grayCode(int n) 
    {
        return solution(n);    
    }
};