class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> frequency(26,0);
        for(int i=0;i<s.size();++i)
        {
            frequency[s[i]-'a']++;
        }
        
        sort(frequency.begin(),frequency.end(),greater<int>());
        
        int max_frequency=frequency[0];
        int count=0;
        for(int i=0;i<frequency.size();++i)
        {
            if(frequency[i]>max_frequency)
            {
                if(max_frequency>0)
                    count+=(frequency[i]-max_frequency);
                else
                    count+=frequency[i];
            }
            max_frequency=min(max_frequency-1,frequency[i]-1);
        }
        return count;
    }
};