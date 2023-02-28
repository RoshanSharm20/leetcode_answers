class Solution {
public:
    int maximumSwap(int num) 
    {
        string nums = to_string(num);
        map<int,int> nodes;
        for(int i=0;i<nums.size();++i)
        {
            nodes[nums[i]-'0']=i;
        }
        
        for(int i=0;i<nums.size();++i)
        {
            int x = nums[i]-'0';
            bool flag = false;
            for(int j=9;j>x;--j)
            {
                if(nodes.find(j)!=nodes.end() && nodes[j]>i)
                {
                    swap(nums[i],nums[nodes[j]]);
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        return stoi(nums);
    }
};