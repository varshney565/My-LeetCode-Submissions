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
        PendingNodes.insert({0,k,-1,0});
        vector<int> visited(n,false);
        int ans = 0;
        while(!PendingNodes.empty()){
            auto front = *PendingNodes.begin();
            PendingNodes.erase(front);
            int wsf = front[0];
            int u = front[1];
            int p = front[2];
            int w = front[3];
            if(visited[u]){
                continue;
            }
            visited[u] = true;
            ans = max(ans,wsf);
            for(int i = 0 ; i < graph[u].size() ; i++){
                pair<int,int> v = graph[u][i];
                if(!visited[v.first]){
                    PendingNodes.insert({wsf+v.second,v.first,u,v.second});
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i])
                return -1;
        }
        return ans;
    }
};