class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int count1=0,count2=0;
        for(int i=0;i<(s.size()/2);++i)
        {
            char a=tolower(s[i]);
            char b=tolower(s[s.size()-1-i]);
            
            if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
                count1++;
            if(b=='a' || b=='e' || b=='i' || b=='o' || b=='u')
                count2++;
        }
        if(count1==count2)
            return true;
        else
            return false;
    }
};