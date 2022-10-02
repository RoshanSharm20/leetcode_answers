class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int array[26];
        fill(array, array + 26, 0);
        vector<int> ans;
        int max_prev = 0;
        for (int i = 0; i < s.size(); ++i) // each characters maximimum index position is stored to find the limits of each partition
        {
            array[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.size();) // we run a loop for each character of the given string
        {
            int maxi = array[s[i] - 'a']; // check its maximum index limit
            int j;
            for (j = +1; j < maxi; ++j) // traverse from the next character and check if its limit is greater than defined before ->if yes then update it or else increase j till we reach some characters maximum limit,since we allowed the maxi value to changed if we reached some elements maximum index limit then all the elements below the index limit must have lied only within that range only
            {
                if (array[s[j] - 'a'] > maxi)
                {
                    maxi = array[s[j] - 'a'];
                }
            }
            ans.push_back(maxi + 1 - max_prev);
            max_prev = maxi + 1;
            i = maxi + 1;
        }
        return ans;
    }
};