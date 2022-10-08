class Solution
{
public:
    int minSteps(string s, string t)
    {
        int count = 0;
        array<int, 26> check = {0}; // array to keep track of frequency of each character
        for (int i = 0; i < s.size(); ++i)
        {
            check[s[i] - 'a']++; // if character is present in string s add 1 to it's count
            check[t[i] - 'a']--; // if character is present in string t subtract 1 from it's count
        }
        for (int i = 0; i < 26; ++i)
        {
            int val = abs(check[i]); // either there would have characters that were totally same in both strings,that would make their count 0.There are chances that characters are only present in t string making their counts negative therefor we take their absolute values indicating their frequecy of occurences
            count += val;
        }
        return (count / 2);
    }
};