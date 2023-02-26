class Solution {
public:
    bool isVowel(string& s,int index)
    {
        vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        if(std::find(vowels.begin(), vowels.end(), s[index]) != vowels.end())
            return true;
        return false;
    }
    string reverseVowels(string s) 
    {
        int left = 0,right=s.size()-1;
        while(left<right)
        {
            while(left<right && !isVowel(s,left))
                left++;
            while(left<right && !isVowel(s,right))
                right--;
            
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
        
    }
};