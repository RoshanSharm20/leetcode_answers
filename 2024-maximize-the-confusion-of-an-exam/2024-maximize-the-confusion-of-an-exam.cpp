class Solution {
public:
    bool isPossible(string answerKey,int k,int size)
    {
        int countTrue=0,countFalse=0;
        for(int i=0;i<size;++i)
        {
            if(answerKey[i]=='T')
                countTrue++;
            else
                countFalse++;
        }
        if(countTrue<=k || countFalse<=k)
        {
            return true;
        }
        for(int i=size;i<answerKey.size();++i)
        {
            if(answerKey[i-size]=='T')
                countTrue--;
            else
                countFalse--;
            if(answerKey[i]=='T')
                countTrue++;
            else
                countFalse++;
            
            if(countTrue<=k || countFalse<=k)
                return true;
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int low=1,high=answerKey.size();
        int ans=1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(answerKey,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};