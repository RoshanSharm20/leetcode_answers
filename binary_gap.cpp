class Solution
{
public:
    int binaryGap(int n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n % 2 == 0) // skip the trailing zeroes so to be able to start with 1
                n = n >> 1;
            if (n % 2 != 0)
            {
                int count_max = 0;
                n = n >> 1; // move 1 bit to start after the first 1 bit
                if (n > 0)  // important to check if still n>0 eg for 1000
                {
                    while (n % 2 == 0)
                    {
                        count_max++;
                        n = n >> 1;
                    }
                    count_max++;
                }
                if (count_max > count)
                    count = count_max;
            }
        }
        return count;
    }
};