class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        priority_queue<int> nodes;
        int min_val=INT_MAX;
        for(auto it:nums)
        {
            if(it%2!=0)
                it*=2;
            nodes.push(it);
            min_val = min(min_val,it);
        }
        int min_deviation = INT_MAX;
        while(!nodes.empty())
        {
            int top = nodes.top();
            nodes.pop();
            min_deviation = min(min_deviation,top-min_val);
            if(top%2!=0)
                break;
            top/=2;
            min_val = min(min_val,top);
            nodes.push(top);
        }
        return min_deviation;
    }
};