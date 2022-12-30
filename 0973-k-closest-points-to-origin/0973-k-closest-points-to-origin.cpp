class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        for(int i=0;i<points.size();i++)
        {
            int x = pow(points[i][0]-0,2)+pow(points[i][1]-0,2);
            pq.push({x,points[i]});
        }
        vector<vector<int>> answer;
        for(int i=0;i<k;++i)
        {
            auto it = pq.top();
            pq.pop();
            auto x = it.second;
            answer.push_back(x);
        }
        return answer;
    }
};