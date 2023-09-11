class Solution {
public:
    bool isVowel(char ch)
    {
        ch=tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    string sortVowels(string s) 
    {
        vector<char> vowels;
        for(int i=0;i<s.size();++i)
        {
            if(isVowel(s[i]))
            {
                vowels.push_back(s[i]);
            }
        }
        
        sort(vowels.begin(),vowels.end());
        // for(int i=0;i<vowels.size();++i)
        //     cout<<vowels[i]<<endl;
        int k=0;
        for(int i=0;i<s.size();++i)
        {
            if(isVowel(s[i]))
            {
                s[i]=vowels[k];
                k++;
            }
        }
        return s;
    }
};