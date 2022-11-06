class Solution {
public:
    string makeGood(string s) 
    {
        stack<char> ans;
        for(int i=0;i<s.size();++i)
        {
            if(!ans.empty() && ((ans.top()-97)==(s[i]-65) || (ans.top()-65)==(s[i]-97)))
                  ans.pop();
            else
                ans.push(s[i]);  
        }
        string st="";
        while(!ans.empty())
        {
            st+=ans.top();
            ans.pop();
        }
        reverse(st.begin(),st.end());
        return st;
    }
};