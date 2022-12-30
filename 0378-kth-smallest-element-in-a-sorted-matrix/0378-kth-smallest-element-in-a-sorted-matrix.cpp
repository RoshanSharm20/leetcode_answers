class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int> nums;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix.size();++j)
                nums.push_back(matrix[i][j]);
        }
        
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int i=1;
        while(i<k)
        {
            pq.pop();
            i++;
        }
        return pq.top();
    }
};