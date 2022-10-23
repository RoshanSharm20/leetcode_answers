class Solution {
public:
    int trap(vector<int>& height) 
    {
        vector<int> lArray(height.size(),0);
        vector<int> rArray(height.size(),0);
        int lmax=height[0];
        lArray[0]=lmax;
        int rmax=height[height.size()-1];
        rArray[height.size()-1]=rmax;
        for(int i=1;i<height.size();++i)
        {
            lArray[i]=max(lArray[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;--i)
        {
            rArray[i]=max(rArray[i+1],height[i]);
        }
        int count=0;
        for(int i=0;i<height.size();++i)
        {
            count+=(min(lArray[i],rArray[i]))-height[i];
        }
        return count;
    }
};