class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()==1)
            return 0;
        int profit = prices[1]-prices[0];
        int min_val = prices[0];
        for(int i=0;i<prices.size();++i)
        {
            profit = max(profit,prices[i]-min_val);
            min_val = min(min_val,prices[i]);
        }
        return profit;
    }
};