class Solution {
public:
    int robber(vector<int>& nums) 
    {
        int prev = nums[0],prev2=0,curr;
        
        for(int i=1;i<nums.size();++i)
        {
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int nottake=prev;
            curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        
        return prev;
    }
    int rob(vector<int>& num) 
    {
        if(num.size()==1)
            return num[0];
        int n=num.size();
        vector<int> temp1(num.begin(),num.end()-1);
        vector<int> temp2(num.begin()+1,num.end());
        return max(robber(temp1),robber(temp2));
    }
};