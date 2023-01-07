class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total_gas= accumulate(gas.begin(),gas.end(),0);
        int total_cost = accumulate(cost.begin(),cost.end(),0);
        if(total_gas-total_cost>=0)
        {
            int index=0;
            int tank=0;
            for(int i=0;i<gas.size();++i)
            {
                tank+=gas[i]-cost[i];
                if(tank<0)
                {
                    index=i+1;
                    tank=0;
                }
            }
            return index;
        }
        return -1;
    }
};