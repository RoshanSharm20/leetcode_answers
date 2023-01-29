class UndergroundSystem {
public:
    map<int,pair<string,int>> nodes;
    map<pair<string,string>,vector<int>> intervals;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        nodes[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        string start_place = nodes[id].first;
        int start_time = nodes[id].second;
        int time_gap = t-start_time;
        intervals[{start_place,stationName}].push_back(time_gap);    
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        double x = 0;
        for(auto it:intervals[{startStation,endStation}])
        {
            x+=it;
        }
        int n=intervals[{startStation,endStation}].size();
        return double(x/n);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */