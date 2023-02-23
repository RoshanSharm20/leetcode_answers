class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        //two pointer approach
        int i=0,j=height.size()-1,max_val=0;
        while(i<j)
        {
            int width = j-i;
            int min_len = min(height[i],height[j]);
            max_val = max(max_val,width*min_len);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return max_val;
    }
};