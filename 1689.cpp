class Solution
{
public:
    int minPartitions(string n) // the maximum number of deci-binary numbers that add to form the given number(in string format) is simply equal to the maximum digit value in the number
    {
        int count = 0;
        for (int i = 0; i < n.size(); ++i)
            count = max(count, n[i] - '0');
        return count;
    }
};