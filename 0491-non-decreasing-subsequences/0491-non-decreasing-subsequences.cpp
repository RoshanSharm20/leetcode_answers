class Solution {
public:
    set<vector<int>> ans;
    void solution(int index,vector<int>& nums,vector<int> asf)
    {
        if(index==nums.size())
        {
            ans.insert(asf);
            return;
        }
        solution(index+1,nums,asf);
        asf.push_back(nums[index]);
        solution(index+1,nums,asf);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();++i)
        {
            vector<int> temp;
            solution(i,nums,temp);
        }
        
        vector<vector<int>> final_ans;
        for(auto it:ans)
        {
            bool flag=true;
            for(int j=1;j<it.size();++j)
            {
                if(it[j]<it[j-1])
                {
                    flag=false;
                    break;
                }
            }
            if(flag && it.size()>=2)
                final_ans.push_back(it);
        }
        return final_ans;
    }
};