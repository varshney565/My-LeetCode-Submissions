class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> disc(n,0);
        vector<int> low(n,0);
        vector<bool> visited(n,false);
        vector<vector<int>> ans;
        
        function<void(int,int,int&)> dfs = [&](int source,int parent,int &time){
            visited[source] = true;
            disc[source] = low[source] = time++;
            for(auto child : graph[source]){
                if(child == parent)
                    continue;
                if(!visited[child]){
                    dfs(child,source,time);
                    low[source] = min(low[source],low[child]);
                    if(disc[source] < low[child]){
                        ans.push_back({source,child});
                    }
                }else{
                    low[source] = min(low[source],disc[child]);
                }
            }
        };
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int time = 1;
                dfs(i,-1,time);
            }
        }
        return ans;
    }
};