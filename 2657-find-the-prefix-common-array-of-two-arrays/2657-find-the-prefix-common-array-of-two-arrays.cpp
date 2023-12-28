class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n= A.size();
        vector<int> nums(n+1,0),ans;
        int count=0;
        for(int i=0;i<n;++i)
        {
            nums[A[i]]++;
            nums[B[i]]++;
            
            if(A[i]!=B[i])
            {
                if(nums[A[i]]==2)
                    count++;
                if(nums[B[i]]==2)
                    count++;
                ans.push_back(count);
            }
            else
            {
                if(nums[A[i]]==2)
                    count++;
                ans.push_back(count);
            }
        }
        return ans;
    }
};