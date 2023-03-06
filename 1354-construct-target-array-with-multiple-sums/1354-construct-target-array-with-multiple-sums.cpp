class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        long long int sum = 0;
        priority_queue<long long int> nodes;
        for(int i=0;i<target.size();++i)
        {
            nodes.push(target[i]);
            sum+=target[i];
        }
        
        while(nodes.top()!=1)
        {
            long long int max_val = nodes.top();
            nodes.pop();
            sum = sum-max_val;
            if(sum<=0 || sum>=max_val)
                return false;
            max_val = max_val%sum;
            // nodes.push(max_val);
            sum+=max_val;
            nodes.push(max_val>0?max_val:sum);
        }
        return true;
    }
};