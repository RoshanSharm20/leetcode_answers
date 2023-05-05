class Solution {
public:
    unordered_set<char> vowels = {'a','e','i','o','u'};
    int maxVowels(string s, int k) 
    {
        int count=0,max_val=0;
        // vector<bool> checks(s.size(),false);
        for(int i=0;i<k;++i)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                // checks[i]=true;
                count++;
                max_val=max(max_val,count);
            }
        }
        
        for(int i=k;i<s.size();++i)
        {
            if(vowels.find(s[i-k])!=vowels.end())
            {
                count--;
            }
            if(vowels.find(s[i])!=vowels.end())
            {
                // checks[i]=true;
                count++;
                max_val=max(max_val,count);
            }
        }
        return max_val;
    }
};