class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<pair<int,int>> ranks;
        for(int i=0;i<score.size();++i)
        {
            ranks.push_back({score[i],i});
        }
        
        sort(ranks.begin(),ranks.end());
        reverse(ranks.begin(),ranks.end());
        for(int i=0;i<ranks.size();++i)
        {
            cout<<ranks[i].first<<" "<<ranks[i].second<<endl;
        }
        map<int,int> ranks2;
        for(int i=0;i<ranks.size();++i)
        {
            ranks2[ranks[i].second]=i;
        }
        vector<string> ans;
        for(int i=0;i<ranks.size();++i)
        {
            string val="";
            if(ranks2[i]==0)
                val="Gold Medal";
            else if(ranks2[i]==1)
                val="Silver Medal";
            else if(ranks2[i]==2)
                val="Bronze Medal";
            else
                val=to_string(ranks2[i]+1);
            
            ans.push_back(val);
        }
        return ans;
    }
};