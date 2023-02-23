class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n);
        int i=0,j=n-1,index=n-1;
        while(i<=j)
        {
            int x = nums[i]*nums[i];
            int y = nums[j]*nums[j];
            ans[index] = max(x,y);
            index--;
            if(x>y)
                i++;
            else
                j--;
        }
        return ans;
    }
};