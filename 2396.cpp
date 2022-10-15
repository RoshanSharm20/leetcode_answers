class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i <= n - 2; ++i)
        {
            int x = n;
            string str = "";
            while (x != 0)
            {
                if (x % i != 0)
                    str += (x % i) + '0'; // add the remainder value to string if not divisible
                else
                    str += '0'; // else append 0 meaning divisible
                x /= i;
            }
            // cout << str << endl;
            string strr = str;
            reverse(strr.begin(), strr.end());
            if (strr != str)
                return false;
        }
        return true;
    }
};