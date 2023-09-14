class Solution {
private:
    unordered_map<string,vector<string>> airports;
    vector<string> itinerary;
public:
    
    void solution(string curr_airport)
    {
        vector<string> &it = airports[curr_airport];
        while(!it.empty())
        {
            auto next = it.back();
            it.pop_back();
            solution(next);
        }
        
        itinerary.push_back(curr_airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for(auto it:tickets)
        {
            airports[it[0]].push_back(it[1]);
        }
        
        for(auto &it : airports)
        {
            sort(it.second.rbegin(),it.second.rend());
        }
        
        
        solution("JFK");
        
        reverse(itinerary.begin(),itinerary.end());
        return itinerary;
    }
};