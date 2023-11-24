class Solution {
public:
    int maxCoins(vector<int>& piles)
    {
        sort(piles.begin(),piles.end(),greater<int>());
        int max=0;
        for(int i=1;i<2*((piles.size())/3);i=i+2)
        {
            max+=piles[i];
        }
        return max;
    }
};