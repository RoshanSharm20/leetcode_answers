class Solution
{
public:
    string sortString(string s)
    {
        string ans = "";
        map<char, int> m; // map to store the characters and their frequency
        for (auto i : s)
        {
            m[i]++;
        }
        int flag = 0;
        while (1)
        {
            int count = 0;
            string mid = "";
            for (auto i : m)
            {
                if (i.second) // if value is not zero the add the character and reduce the count
                {
                    mid += i.first;
                    m[i.first]--;
                    count++;
                }
            }
            if (count == 0) // if count is zero it indicates that no element is left to add then break
            {
                break;
            }
            if (flag == 0) // for every odd traversal
            {
                flag = 1;
                ans += mid;
            }
            else
            {
                flag = 0;
                reverse(mid.begin(), mid.end()); // for every even traversal reverse it and add it to the string
                ans += mid;
            }
        }
        return ans;
    }
};