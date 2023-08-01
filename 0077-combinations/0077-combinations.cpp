class Solution {
public:
vector<vector<int>> ans;
    void solution(int index,int& k,int& n,vector<int>& asf)
    {
        if(asf.size()==k)
        {
            ans.push_back(asf);
            return;
        }
        if(index>n)
        {
            return;
        }
        solution(index+1,k,n,asf);
        asf.push_back(index);
        solution(index+1,k,n,asf);
        asf.pop_back();
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> asf;
        solution(1,k,n,asf);
        return ans;    
    }
};