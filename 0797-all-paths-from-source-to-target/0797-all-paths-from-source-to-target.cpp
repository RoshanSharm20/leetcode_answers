class Solution {
public:
    vector<vector<int>> final_answer;
    void solution(vector<vector<int>>& graph,vector<bool>& visited,vector<int> nodes,vector<int>& answer)
    {
        if(nodes.size()==0)
            return;
        for(int i=0;i<nodes.size();++i)
        {
            if(!visited[nodes[i]])
            {
                answer.push_back(nodes[i]);
                visited[nodes[i]]=true;
                if(nodes[i]==graph.size()-1)
                    final_answer.push_back(answer);
                solution(graph,visited,graph[nodes[i]],answer);
                visited[nodes[i]]=false;
                answer.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<bool> visited(graph.size(),false);
        visited[0]=true;
        vector<int> answer;
        answer.push_back(0);
        solution(graph,visited,graph[0],answer);
        return final_answer;
    }
};