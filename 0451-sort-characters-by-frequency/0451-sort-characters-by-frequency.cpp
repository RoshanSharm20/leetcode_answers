class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int> m;
        for(int i=0;i<s.size();++i)
        {
            m[s[i]]+=1;
        }
        vector<pair<int,char>> ans;
        for(auto it: m)
        {
            ans.push_back({it.second,it.first});
        }
        string st="";
        sort(ans.begin(),ans.end(),greater<pair<int,char>>());
        for(int i=0;i<ans.size();++i)
        {
            for(int j=ans[i].first;j>0;--j)
            {
                st+=ans[i].second;
            }
        }
        return st;
    }
};