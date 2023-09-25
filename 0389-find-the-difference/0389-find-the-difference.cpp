class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int n=0;
     for(int i=0;i<s.size();i++)
     {
       n=n^s[i]^t[i];  
     }
        n=n^t[t.size()-1];
        return n;
    }
};