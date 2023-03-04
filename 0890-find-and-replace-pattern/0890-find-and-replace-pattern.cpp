class Solution {
public:
    bool isMatching(string& word,string& pattern)
    {
        map<char,char> nodes;
        set<char> chars;
        for(int i=0;i<pattern.size();++i)
        {
            if(nodes.find(pattern[i])==nodes.end())
            {
                if(chars.find(word[i])!=chars.end())
                    return false;
                nodes[pattern[i]]=word[i];
                chars.insert(word[i]);
            }
            else
            {
                if(nodes[pattern[i]]!=word[i])
                    return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        for(auto it:words)
        {
            if(isMatching(it,pattern))
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};