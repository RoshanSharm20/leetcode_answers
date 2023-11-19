class Solution {
public:
    static bool myComp(pair<int,int> &A,pair<int,int> &B)
    {
        if(A.first>B.first)
            return true;
        return false;
    }
    int reductionOperations(vector<int>& nums) 
    {
        int count=0;
        vector<pair<int,int>> nodes;
        sort(nums.begin(),nums.end());
        
        int element = nums[0],curr_count=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]==element)
            {
                curr_count++;
                continue;
            }
            else
            {
                nodes.push_back({element,curr_count});
                element = nums[i];
                curr_count=1;
            }
        }
        
        nodes.push_back({element,curr_count});
        
        sort(nodes.begin(),nodes.end(),myComp);
        // for(auto it:nodes)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int prefix = nodes[0].second;
        for(int i=1;i<nodes.size();++i)
        {
            count+=prefix;
            prefix+=nodes[i].second;
        }
        
        return count;
    }
};