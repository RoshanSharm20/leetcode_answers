class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!='#')
                s1.push(s[i]);
            else
                if(!s1.empty())
                    s1.pop();
        }
        for(int i=0;i<t.size();++i)
        {
            if(t[i]!='#')
                s2.push(t[i]);
            else
                if(!s2.empty())
                    s2.pop();
        }
        string first="",second="";
        while(!s1.empty())
        {
            first+=s1.top();
            s1.pop();
        }
        while(!s2.empty())
        {
            second+=s2.top();
            s2.pop();
        }
        return first==second;
    }
};