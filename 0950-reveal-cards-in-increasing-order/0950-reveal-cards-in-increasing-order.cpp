class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(),deck.end());
        vector<int> ans(deck.size());
        //using deque datastructure
        
        deque<int> nodes;
        for(int i=0;i<deck.size();++i)
            nodes.push_back(i);
        int chance=0;
        int flip=0;
        while(!nodes.empty())
        {
            if(flip==0)
            {
                ans[nodes.front()]=deck[chance++];
                nodes.pop_front();
            }
            else
            {
                nodes.push_back(nodes.front());
                nodes.pop_front();
            }
            flip^=1;
        }
        return ans;
    }
};