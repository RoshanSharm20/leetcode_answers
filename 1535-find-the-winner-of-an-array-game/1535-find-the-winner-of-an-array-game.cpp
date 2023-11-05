class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        if(k>=arr.size())
        {
            return *max_element(arr.begin(),arr.end());
        }
        
        queue<pair<int,int>> nodes;
        for(int i=0;i<arr.size();++i)
        {
            nodes.push({arr[i],0});
        }
        
        while(true)
        {
            auto it = nodes.front();
            if(it.second==k)
                return it.first;
            nodes.pop();
            auto it2 = nodes.front();
            if(it2.second==k)
                return it2.first;
            
            if(it.first>it2.first)
            {
                nodes.push({it2.first,0});
                nodes.front().first = it.first;
                nodes.front().second = it.second+1;
            }
            else
            {
                nodes.push({it.first,0});
                nodes.front().second = nodes.front().second+1;
            }
        }
        
        return -1;
    }
};