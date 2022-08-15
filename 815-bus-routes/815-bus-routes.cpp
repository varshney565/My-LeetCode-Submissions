class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        queue<int> PendingBusStops;
        map<int,set<int>> Buses;
        for(int i = 0 ; i < routes.size() ; i++){
            for(int j = 0 ; j < routes[i].size() ; j++){
                Buses[routes[i][j]].insert(i);
            }
        }
        vector<bool> visited(routes.size(),false);
        PendingBusStops.push(source);
        int TotalNumberOfBuses = 0;
        while(!PendingBusStops.empty()){
            int size = PendingBusStops.size();
            while(size-->0){
                int CurrentStop = PendingBusStops.front();
                if(CurrentStop == target)
                    return TotalNumberOfBuses;
                PendingBusStops.pop();
                while(Buses[CurrentStop].size() > 0){
                    int index = *Buses[CurrentStop].begin();
                    Buses[CurrentStop].erase(index);
                    if(visited[index])
                        continue;
                    for(int i = 0 ; i < routes[index].size() ; i++){
                        PendingBusStops.push(routes[index][i]);
                    }
                    visited[index] = true;
                }
            }
            TotalNumberOfBuses++;
        }
        return -1;
    }
};