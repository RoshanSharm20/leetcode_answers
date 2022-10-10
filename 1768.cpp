class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, j = 0; // merge sort algorithm is used i.e only the merge function
        string str = "";
        while ((i < word1.size()) && (j < word2.size()))
        {
            str += word1[i];
            str += word2[j];
            ++i;
            ++j;
        }
        while (i < word1.size())
        {
            str += word1[i];
            ++i;
        }
        while (j < word2.size())
        {
            str += word2[j];
            ++j;
        }
        return str;
    }
};