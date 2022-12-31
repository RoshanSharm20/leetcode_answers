class Solution {
public:
    bool static myCmp(pair<int,string> a,pair<int,string> b)
    {
        if(a.first > b.first)
            return true;
        if(b.first==a.first)
            if(a.second<b.second)
                return true;
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string,int> m;
        for(int i=0;i<words.size();++i)
            m[words[i]]+=1;
        vector<pair<int,string>> answer;
        for(auto it: m)
            answer.push_back({it.second,it.first});
        sort(answer.begin(),answer.end(),myCmp);
        vector<string> ans;
        for(int i=0;i<k;++i)
        {
            ans.push_back(answer[i].second);
        }
        return ans;
    }
};