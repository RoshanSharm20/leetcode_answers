class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> ans;
        vector<int> s={1,2,3,4,5,6,7,8,9};
        for(int i=0;i<10;++i)
        {
            int x = 0;
            for(int j=i+1;j<10;++j)
            {
                x=x*10+j;
                if(x>=low && x<=high)
                    ans.push_back(x);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};