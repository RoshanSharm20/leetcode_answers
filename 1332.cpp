class Solution
{
public:
    int removePalindromeSub(string s)
    {
        string str = s;
        reverse(str.begin(), str.end()); // eitner the whole string is a palindrome
        if (str == s)
            return 1;
        else
            return 2; // or to remove palindromic subsequences,remove all character 'a' subsequences and then all character 'b' subsequences i.e total 2 moves
    }
};