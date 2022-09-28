class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> arr = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> ans;
        for (auto it : words)
        {
            string str = "";
            for (int i = 0; i < it.size(); ++i)
            {
                str += arr[it[i] - 'a'];
            }
            ans.insert(str);
        }
        return ans.size();
    }
};