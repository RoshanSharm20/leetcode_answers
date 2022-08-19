class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int sum = 0;
        int i = 1;
        if (n == 0) // if n is 0 the return 1
            return 1;
        while (n > 0)
        {
            if ((n & 1) == 0) // check if last bit is 0 then make it one
            {
                sum = sum + i;
            }
            n = n >> 1;
            i = i * 2;
        }
        return sum;
    }
};