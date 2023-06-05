class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if(k>=nums.size())
        {
            k=k%nums.size();
        }
        int rot = nums.size()-k;
        reverse(nums.begin(),nums.begin()+rot);
        reverse(nums.begin()+rot,nums.end());
        reverse(nums.begin(),nums.end());
    }
};