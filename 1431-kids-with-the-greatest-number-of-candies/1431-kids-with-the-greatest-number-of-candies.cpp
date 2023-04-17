class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> v;
        int count;
     for(int i=0;i<candies.size();i++)
     {
         count=candies[i]+extraCandies;
         int test=1;
         for(int j=0;j<candies.size();j++)
         {
             
             if(count<candies[j])
                 test=0;
         }
         v.push_back(test);
         
     }
        return v;
    }
};