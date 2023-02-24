class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int max_val = 0,chunk_count=0;
        int i=0;
        while(i<arr.size())
        {
            max_val = max(max_val,arr[i]);
            if(max_val==i)
                chunk_count++;
            i++;
        }
        return chunk_count;
    }
};