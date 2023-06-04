class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;
        string st = to_string(x);
        for(int i=0;i<st.size()/2;++i)
            if(st[i]!=st[st.size()-1-i])
                return false;
        return true;
    }
};