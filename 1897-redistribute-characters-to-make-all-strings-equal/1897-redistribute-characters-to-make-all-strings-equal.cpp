class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        int n=words.size();
        vector<int> characters(26,0);
        for(int i=0;i<n;++i)
        {
            auto it = words[i];
            for(int j=0;j<it.size();++j)
            {
                characters[it[j]-'a']++;
            }
        }
        
        for(int i=0;i<26;++i)
        {
            if(characters[i]%n!=0)
                return false;
        }
        
        return true;
    }
};