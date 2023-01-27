class Solution {
public:
    int partitionString(string s) 
    {
        // vector<string> nodes;
        int count=0;
        set<char> st;
        int start=0;
        for(int i=0;i<s.size();++i)
        {
            if(st.find(s[i])!=st.end())
            {
                // nodes.push_back(s.substr(start,i));
                count++;
                st.clear();
                st.insert(s[i]);
                start=i;
            }
            else
            {
                st.insert(s[i]);
            }
        }
        
        return count+1;
    }
};