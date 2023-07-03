class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(goal.size()!=s.size())
            return false;
        vector<int> st;
        // vector<int> gt;
        map<int,int> mp;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!=goal[i])
            {
                st.push_back(i);
                // gt.insert(goal[i]);
            }
            mp[s[i]]++;

        }
        
        if(st.size()==0)
        {
            for(auto it:mp)
            {
                if(it.second>=2)
                    return true;
            }
            return false;
        }
        else if(st.size()==1)
            return false;
        else if(st.size()==2)
        {
            char a1=s[st[0]];
            char a2=goal[st[0]];
            char b1=s[st[1]];
            char b2=goal[st[1]];
            return(a1==b2 && a2==b1);
        }
        else
            return false;
    }
};