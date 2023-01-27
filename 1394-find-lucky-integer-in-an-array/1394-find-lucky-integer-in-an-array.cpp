class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        map<int,int> frequency;
        for(auto it:arr)
            frequency[it]++;
        int count=-1;
        for(auto it:frequency)
            if(it.second==it.first)
                count=it.first;
        return count;
    }
};