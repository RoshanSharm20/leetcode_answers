class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int i=-1;
        int j=nums.size();
        while(true)
        {
            do
            {
                i++;
            }while((nums[i]%2)==0 && (i+1)!=nums.size());
            do
            {
                j--;
            }while((nums[j]%2)!=0 && (j-1)!=-1);
            if(i>=j)
                break;
            else
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};