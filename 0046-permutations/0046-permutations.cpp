class Solution {
public:
    vector<vector<int>> ans;
    void solution(vector<int>&nums,vector<int> &asf)
    {
        if(nums.size()==0)
        {
            ans.push_back(asf);
            return;
        }
        for(int i=0;i<nums.size();++i)
        {
            int ch = nums[i];
            asf.push_back(ch);
            nums.erase(nums.begin()+i);
            solution(nums,asf);
            asf.pop_back();
            nums.insert(nums.begin()+i,ch);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> asf;
        solution(nums,asf);
        return ans;
    }
};