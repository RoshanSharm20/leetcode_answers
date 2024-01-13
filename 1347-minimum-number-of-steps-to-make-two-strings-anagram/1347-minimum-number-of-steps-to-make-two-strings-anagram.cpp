class Solution {
public:
    int minSteps(string s, string t) 
    {
        int count=0;
        array <int,26> check={0};
        for(int i=0;i<s.size();++i)
        {
            check[s[i]-'a']++;
            check[t[i]-'a']--;
        }
        for(int i=0;i<26;++i)
        {
            int val = abs(check[i]);
            count+=val;
        }
        return (count/2);
    }
};