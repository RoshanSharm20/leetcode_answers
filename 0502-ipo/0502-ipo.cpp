class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        vector<pair<int,int>> capital_pair;
        for(int i=0;i<n;++i)
        {
            capital_pair.push_back({capital[i],i});
        }
        
        sort(capital_pair.begin(),capital_pair.end());
        priority_queue<pair<int,int>> pq;
        int i=0;
        while(k--)
        {
            while(i<n && capital_pair[i].first<=w)
            {
               pq.push({profits[capital_pair[i].second],capital_pair[i].second});
                i++;
            }
            if(pq.size()!=0)
            {
                int capital_gain_index = pq.top().second;
            w+=profits[capital_gain_index];
            pq.pop();
            }
        }
        return w;
    }
};