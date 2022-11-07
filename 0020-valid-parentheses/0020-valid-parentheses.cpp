class Solution {
public:
    bool callCheck(char top,char ele)
    {
        return((top=='(' && ele==')')  || (top=='[' && ele==']') || (top=='{' && ele =='}'));
           
    }
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(!st.empty() && callCheck(st.top(),s[i]))
                st.pop();
            else
                return false;
        }
        if(!st.empty())
            return false;
        return true;
    }
};