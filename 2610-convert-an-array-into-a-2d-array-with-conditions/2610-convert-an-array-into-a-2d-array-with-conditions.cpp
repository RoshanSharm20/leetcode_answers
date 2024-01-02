class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        map<int,int> nodes;
        for(int i=0;i<nums.size();++i)
        {
            nodes[nums[i]]+=1;
        }
        
        vector<vector<int>> ans;
        bool flag = true;
        while(flag)
        {
            vector<int> vec;
            for(auto it:nodes)
            {
                if(it.second!=0)
                {
                    vec.push_back(it.first);
                    nodes[it.first]-=1;
                }
            }
            if(vec.size()!=0)
            {
                ans.push_back(vec);
            }
            else
            {
                flag=false;
            }
        }
        return ans;
    }
};