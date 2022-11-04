class Solution {
public:
    int largestFit(vector<int>&v)
    {
        int n=v.size();
        int curr=0,res=0;
        stack<int> s;
        vector<int>left(n);
        vector<int>right(n,0);
        for(int i=0;i<n;i++){
            while(s.size() && v[s.top()]>=v[i]){
                s.pop();
            }
            if(s.size()!=0){
                left[i] = s.top()+1;
            }
            s.push(i);
        }
        while(s.size()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(s.size() && v[s.top()]>=v[i]){
                s.pop();
            }
            if(s.size()!=0){
                right[i] = s.top()-1;
            }
            else{
                right[i]  = n-1;
            }
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]+1)*v[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
       vector<int>v(matrix[0].size());
        int ans=0;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                if((matrix[i][j]-'0')==1)
                    v[j]++;
                else{
                    v[j] = 0;
                }
            }
            int x = largestFit(v);
            ans=max(x,ans);
        }
        return ans;
    }
};