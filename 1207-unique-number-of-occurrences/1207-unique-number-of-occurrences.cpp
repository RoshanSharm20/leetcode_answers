class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        set<int> values;
        
        int counter=1;
        for(int i=1;i<arr.size();++i)
        {
            if(arr[i]==arr[i-1])
                counter++;
            else
            {
                if(values.find(counter)!=values.end())
                    return false;
                else
                {
                    values.insert(counter);
                    counter=1;
                }
            }
        }
        
        if(values.find(counter)!=values.end())
            return false;
        
        return true;
    }
};