class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int count=0;
        while(target>1 && maxDoubles>0)
        {
            if(target%2!=0)
            {
                target-=1;
                count++;
            }
            target/=2;
            maxDoubles--;
            count++;
        }
        
        if(target==1)
            return count;
        return count+(target-1);
    }
};