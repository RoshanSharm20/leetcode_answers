class Solution {
public:
    bool isPossible(string &s,string st)
    {
        if(s.size()%st.size()!=0)
            return false;
        
        string check="";
        for(int i=0;i<s.size();++i)
        {
            check+=s[i];
            if(check.size()==st.size())
            {
                if(st!=check)
                    return false;
                else
                    check="";
            }
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) 
    {
        string st="";
        for(int i=0;i<s.size()/2;++i)
        {
            st+=s[i];
            if(isPossible(s,st))
            {
                return true;
            }
        }
        return false;
    }
};