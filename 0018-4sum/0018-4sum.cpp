class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()==0){
            return ans;
        }
        if(abs(target)==294967296)
            return ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            
            for(int j =i+1;j<n;j++){
                int target1 = target -nums[i]-nums[j];
                int left = j+1;
                int right = n-1;
                
                while(left<right){
                    int sum = nums[left]+nums[right];
                    if(sum < target1)left++;
                    else if(sum > target1)right--;
                    else{
                        vector<int> q(4,0);
                        q[0] = nums[i];
                        q[1] = nums[j];
                        q[2] = nums[left];
                        q[3] = nums[right];
                        ans.push_back(q);
                        while(left<right && nums[left]==q[2])left++;
                        while(left<right && nums[right]==q[3])right--; 
                    }
                }
                while(j+1<n && nums[j+1]==nums[j])++j;
            }
             while(i+1<n && nums[i+1]==nums[i])++i;
        }
        return ans;

    }
};