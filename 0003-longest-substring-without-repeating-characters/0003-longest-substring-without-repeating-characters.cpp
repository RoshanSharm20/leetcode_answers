class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len=0;
        vector<int> m(256,-1);
        int left=0,right=0;
        while(right<s.size())
        {
            if(m[s[right]!=-1])
                left=max(m[s[right]]+1,left);
            m[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};