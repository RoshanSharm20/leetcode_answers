class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> nodes;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!='*')
                nodes.push(s[i]);
            else
                nodes.pop();
        }
        
        string st="";
        while(!nodes.empty())
        {
            auto it = nodes.top();
            nodes.pop();
            st.push_back(it);
        }
        
        reverse(st.begin(),st.end());
        return st;
    }
};