class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> pq(piles.begin(),piles.end());
        int sum = accumulate(piles.begin(),piles.end(),0);
        while(k>0)
        {
            int a = pq.top();
            pq.pop();
            pq.push(a - a/2);
            sum-=a/2;
            k--;
        }
        return sum;
    }
    // int minStoneSum(vector<int>& A, int k) {
    //     priority_queue<int> pq(A.begin(), A.end());
    //     int res = accumulate(A.begin(), A.end(), 0);
    //     while (k--) {
    //         int a = pq.top();
    //         pq.pop();
    //         pq.push(a - a / 2);
    //         res -= a / 2;
    //     }
    //     return res;
    // }
};