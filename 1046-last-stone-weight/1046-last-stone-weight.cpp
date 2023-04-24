class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> nodes;
        for(int i=0;i<stones.size();++i)
            nodes.push(stones[i]);
        while(nodes.size()>=2)
        {
            int val1=nodes.top();
            nodes.pop();
            int val2=nodes.top();
            nodes.pop();
            if(val1==val2)
                continue;
            else
                nodes.push(abs(val1-val2));
        }
        
        if(nodes.size()==0)
            return 0;
        return nodes.top();
    }
};