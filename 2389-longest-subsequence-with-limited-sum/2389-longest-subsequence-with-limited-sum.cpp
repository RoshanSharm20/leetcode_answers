class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        sort(nums.begin(),nums.end());
        vector<int> answer;
        for(int i=0;i<queries.size();++i)
        {
            int sum=0;
            int j=0;
            while(j<nums.size())
            {
                sum+=nums[j];
                if(sum<=queries[i])
                    j++;
                else
                    break;
            }
            answer.push_back(j);
        }
        return answer;
    }
};