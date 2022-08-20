class Solution
{
public:
    double myPow(double x, int n)
    {

        if (n < 0)
        {
            x = 1 / x; // if we have to calculate for negative powers better to reciprocal x itself
        }

        long num = labs(n); // find the absolute value of power

        double pow = 1;

        while (num)
        {                // equivalent to while(num != 0)
            if (num & 1) // check if bit is set only then multiply with result variable
            {            // equivalent to if((num & 1) != 0)
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};