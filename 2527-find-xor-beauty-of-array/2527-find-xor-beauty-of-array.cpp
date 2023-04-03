class Solution {
public:
    int xorBeauty(vector<int>& nums) 
    {
        int value = 0;
        for(auto it : nums)
            value^=it;
        return value;
    }
};