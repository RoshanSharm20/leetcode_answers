class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans;
        unordered_set<int> num1,num2;
        for(int i=0;i<nums1.size();++i)
            num1.insert(nums1[i]);
        for(int i=0;i<nums2.size();++i)
            num2.insert(nums2[i]);
        
        vector<int> temp1,temp2;
        for(auto it:num1)
            if(num2.find(it)==num2.end())
                temp1.push_back(it);
        for(auto it:num2)
            if(num1.find(it)==num1.end())
                temp2.push_back(it);
        ans.push_back(temp1);
        ans.push_back(temp2);
        
        return ans;
    }
};