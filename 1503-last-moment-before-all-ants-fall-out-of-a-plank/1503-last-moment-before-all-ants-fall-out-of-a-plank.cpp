class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int max_val=0;
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        
        if(left.size()>0)
            max_val = max(max_val,left[left.size()-1]);
        if(right.size()>0)
            max_val = max(max_val,n-right[0]);
        
        
        return max_val;
    }
};