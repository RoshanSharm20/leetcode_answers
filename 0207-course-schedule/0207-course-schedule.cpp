class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) 
    {
        //khans algorithm
        //creating the adjacency list
        vector<vector<int>> adjacency(numCourses);
        for(int i=0;i<pre.size();++i)
            adjacency[pre[i][1]].push_back(pre[i][0]);
        //finding the indegree of all the nodes;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<adjacency.size();++i)
        {
            for(auto it:adjacency[i])
                indegree[it]++;
        }
        queue<int> nodes;
        for(int i=0;i<indegree.size();++i)
        {
            if(indegree[i]==0)
                nodes.push(i);
        }
        vector<int> ans;
        while(!nodes.empty())
        {
            auto index = nodes.front();
            nodes.pop();
            ans.push_back(index);
            for(auto it:adjacency[index])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    nodes.push(it);
            }
        }
        if(ans.size()==numCourses)
            return true;
        return false;    
    }
};