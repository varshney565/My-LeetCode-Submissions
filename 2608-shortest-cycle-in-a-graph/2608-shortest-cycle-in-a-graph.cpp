class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> graph(n);
        for(int i = 0 ; i < m ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        auto bfs = [&](int src){
            queue<int> PendingNodes;
            int level = 0;
            vector<int> visited(graph.size(),-1);
            PendingNodes.push(src);
            while(!PendingNodes.empty()){
                int size = PendingNodes.size();
                while(size-->0){
                    int front = PendingNodes.front();
                    PendingNodes.pop();
                    if(visited[front] > -1){
                        //cycle is there
                        if(visited[front] == level%2){
                            return level*2;
                            cout<<"even";
                        }
                        else{
                            return (level-1)*2+1;
                            cout<<"odd";
                        }
                    }
                    visited[front] = level%2;
                    for(auto child : graph[front]){
                        if(visited[child] == -1){
                            PendingNodes.push(child);
                        }
                    }
                }
                level++;
            }
            return INT_MAX;
        };
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            ans = min(ans,bfs(i));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};