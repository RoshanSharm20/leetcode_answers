class Solution {
public:
    void findcombi(int index,vector<int>& c,int target,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(target==0)
            ans.push_back(ds);
        
        for(int i=index;i<c.size();++i)
        {
            if(i>index && c[i]==c[i-1])
                continue;
            if(c[i]>target)
                break;
            ds.push_back(c[i]);
            findcombi(i+1,c,target-c[i],ds,ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) 
    {
        //first need to sort the array
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        
        //vector to keep track of answer so far
        vector<int> ds;
        findcombi(0,c,target,ds,ans);
        return ans;
    }
};