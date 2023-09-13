class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int> candies(n,1);
        
        for(int i=1;i<n;++i)
        {
            //if the current child rating in higher than previous and also check if previous child has higher candies than the current only then give extra candies to the current
            if(ratings[i]>ratings[i-1] && candies[i-1]>=candies[i])
                candies[i]=candies[i-1]+1;
        }
        
        for(int i=n-2;i>=0;--i)
        {
            //if the current child rating in higher than previous and also check if previous child has higher candies than the current only then give extra candies to the current
            //the additional cases help to elimate increasing candies of a child who have high rating than both it's neighbors
            if(ratings[i]>ratings[i+1] && candies[i+1]>=candies[i])
                candies[i]=candies[i+1]+1;
        }
        
        int ans = accumulate(candies.begin(),candies.end(),0);
        return ans;
    }
};