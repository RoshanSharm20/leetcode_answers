class Solution
{
public:
    bool isprime(int n) // fuction to check if the count of setbits is prime or not
    {
        if (n == 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if ((n % 2 == 0) || (n % 3 == 0))
            return false;
        for (int i = 5; i * i <= n; i = i + 6)
        {
            if ((n % i) == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right)
    {
        int count = 0;
        for (int i = left; i <= right; i++) // count the setbits of numbers in the range
        {
            int n1 = i;
            int count1 = 0;
            while (n1 > 0)
            {
                n1 = n1 & (n1 - 1); // brian-kirningam method
                count1++;
            }
            if (isprime(count1)) // check if setbits are prime or not
                count++;
        }
        return count;
    }
};