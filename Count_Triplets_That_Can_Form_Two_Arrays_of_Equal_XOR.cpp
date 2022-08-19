class Solution
{
public:
    int countTriplets(vector<int> &A)
    {
        A.insert(A.begin(), 0); // define a prefix vector with first value indicating zero sum
        int n = A.size(), res = 0;
        for (int i = 1; i < n; ++i) // find the xor values
            A[i] ^= A[i - 1];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (A[i] == A[j])
                    res += j - i - 1;
        return res;
    }
};