class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int> dp[n];
        int max_val = 2;
        for(int i=0;i<n;++i)
        {
            unordered_map<int,int> temp;
            for(int j=0;j<i;++j)
            {
                int diff = nums[i]-nums[j];
                if(dp[j].find(diff)!=dp[j].end())
                {
                    temp[diff]=dp[j][diff]+1;
                    max_val = max(max_val,temp[diff]);
                }
                else
                {
                    temp[diff]=2;
                }
            }
            dp[i]=temp;
        }
        return max_val;
    }
};

// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& A) {
//         int n = A.size();
//         int result = 0;
//         vector<unordered_map<int, int>> dp(n);
        
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 int diff = A[i]-A[j];
//                 dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
//                 result = max(result, dp[i][diff]);
//             }
//         }
//         return result;
//     }
// };