class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) 
    {
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        int m = nums.size();
        for(int i=1;i<m-1;++i)
        {
            if(nums[i]==0 && nums[i-1]==0 && nums[i+1]==0)
            {
                if(n==0)
                    break;
                n--;
                nums[i]=1;
            }
        }
        // for(int i=1;i<m;++i)
        // {
        //     if(i==0 && nums[i]==0 && nums[i+1]==0)
        //     {
        //         n--;
        //         nums[i]=1;
        //     }
        //     else if(i==m-1 && nums[i-1]==0 && nums[i]==0)
        //     {
        //         n--;
        //         nums[i]=1;
        //     }
        //     else if(nums[i]==0 && nums[i-1]==0 && nums[i+1]==0)
        //     {
        //         n--;
        //         nums[i]=1;
        //     }
        // }
        
        if(n==0)
            return true;
        return false;
    }
};