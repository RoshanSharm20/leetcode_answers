class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int count1=0,count2=0,count3=0,count4=0;
        int top = tops[0],bottom=bottoms[0];
        for(int i=0;i<tops.size();++i)
        {
            if(count1!=INT_MAX)
            {
                if(tops[i]==top)
                {}
                else if(bottoms[i]==top)
                    count1++;
                else
                    count1=INT_MAX;
            }
            
            if(count2!=INT_MAX)
            {
                if(bottoms[i]==bottom)
                {}
                else if(tops[i]==bottom)
                    count2++;
                else
                    count2=INT_MAX;
            }
            
            if(count3!=INT_MAX)
            {
                if(bottoms[i]==top)
                {}
                else if(tops[i]==top)
                    count3++;
                else
                    count3=INT_MAX;
            }
            
            if(count4!=INT_MAX)
            {
                if(tops[i]==bottom)
                {}
                else if(bottoms[i]==bottom)
                    count4++;
                else
                    count4=INT_MAX;
            }
        }
        
        int ans =  min(count1,min(count2,min(count3,count4)));
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};