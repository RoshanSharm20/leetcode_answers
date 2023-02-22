class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        if(s.size()<3)
            return 0;
        int count=0;
        for(int i=0;i<s.size()-2;++i)
        {
            set<char> st;
            for(int j=0;j<3;++j)
            {
                st.insert(s[i+j]);
            }
            if(st.size()==3)
                count++;
        }
        return count;
    }
};