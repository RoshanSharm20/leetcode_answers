class Solution {
public:
    bool allCaps(string word)
    {
        
        for(int i=0;i<word.size();++i)
        {
            if(word[i]!=toupper(word[i]))
                return false;
        }
        return true;
    }
    bool allSmall(string word)
    {
        for(int i=0;i<word.size();++i)
        {
            if(word[i]!=tolower(word[i]))
                return false;
        }
        return true;
    }
    bool onlyFirst(string word)
    {
        if(word.size()==1)
            return word[0]==toupper(word[0]);
        if(word[0]!=toupper(word[0]))
            return false;
        for(int i=1;i<word.size();++i)
        {
            if(word[i]==toupper(word[i]))
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) 
    {
         return (allCaps(word) || allSmall(word) || onlyFirst(word));
    }
};