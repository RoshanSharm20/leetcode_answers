class Solution
{
public:
    // bool static mycmp(pair<int,int> p1,pair<int,int> p2)
    // {
    //     if(p1.first<p2.first)
    //         return true;
    //     if(p1.first==p2.first)
    //     {
    //         if(p1.second<p2.second)
    //             return true;
    //     }
    //     return false;
    // }
    int getKth(int lo, int hi, int k)
    {
        vector<pair<int, int>> v; // create a pair to maintain a relaionship between power and number
        int ans = 0;
        for (int i = lo; i <= hi; ++i)
        {
            int n1 = i;
            int count = 0;
            while (n1 != 1)
            {
                if (n1 % 2 == 0)
                {
                    n1 = n1 / 2;
                    count++;
                }
                else
                {
                    n1 = (n1 * 3) + 1;
                    count++;
                }
            }
            v.push_back({count, i});
        }
        sort(v.begin(), v.end()); // sort them acccording to their power,power is same then according to their value
        int i = 1;
        for (auto it : v)
        {
            if (i == k)
            {
                ans = it.second;
                break;
            }
            else
                i++;
        }
        return ans;
    }
};