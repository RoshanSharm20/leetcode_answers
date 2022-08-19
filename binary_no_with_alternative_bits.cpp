class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int setbit = (n & 1); // assign setbit, the last bit of number
        bool fact = true;
        n = n >> 1;
        while (n > 0)
        {
            int check = n & 1;
            if (check == setbit)
            {
                fact = false;
                break;
            }
            setbit = check;
            n = n >> 1;
        }
        return fact;
    }
};