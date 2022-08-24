class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0],v = times[i][1],w = times[i][2];
            u--;v--;
            graph[u].push_back({v,w});
        }
        k--;
        set<vector<int>> PendingNodes;
        PendingNodes.insert({0,k});
        vector<int> dis(n,INT_MAX);
        vector<int> visited(n,false);
        vector<int> parent(n,-1);
        dis[k] = 0;
        while(!PendingNodes.empty()){
            auto front = *PendingNodes.begin();
            PendingNodes.erase(front);
            int wsf = front[0];
            int src = front[1];
            if(visited[src])
                continue;
            visited[src] = true;
            for(auto child : graph[src]){
                if(!visited[child.first] && dis[src]+child.second < dis[child.first]){
                    dis[child.first] = dis[src]+child.second;
                    PendingNodes.insert({dis[child.first],child.first});
                    parent[child.first] = src;
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};