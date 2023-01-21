class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        reverse(s.begin(),s.end());
        int first = -1;
        int i;
        for(i=0;i<s.size();++i)
        {   
            if(first==-1 && s[i]!=' ')
                first=i;
            if(first!=-1 && s[i]==' ')
                return i-first;
        }
        if(first!=-1)
            return i-first;
        return 0;
    }
};