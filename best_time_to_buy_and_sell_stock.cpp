class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 1)
            return 0;
        int profit = prices[1] - prices[0]; // problem is actually finding the maximum difference (i<j)
        int minval = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            profit = max(profit, prices[i] - minval);
            minval = min(minval, prices[i]);
        }
        if (profit >= 0)
            return profit;
        else
            return 0;
    }
};