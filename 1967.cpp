class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;
        for (int i = 0; i < patterns.size(); ++i)
        {
            if (word.find(patterns[i]) != string::npos) // to check if the substring is present in the string
                // if substring is not found it returns -1 value which is the value stored in npos variable which is defined in string object of std library
                count++;
        }
        return count;
    }
};