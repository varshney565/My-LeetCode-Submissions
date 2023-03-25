class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(graph.size(),-1);
        auto bfs = [&](int src){
            queue<int> PendingNodes;
            int level = 0;
            PendingNodes.push(src);
            while(!PendingNodes.empty()){
                int size = PendingNodes.size();
                while(size-->0){
                    int front = PendingNodes.front();
                    PendingNodes.pop();
                    if(visited[front] > -1){
                        //cycle is there, check the color
                        if(visited[front] == level%2)
                            continue;     //even length cycle
                        else
                            return false; //odd length cycle
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
            return true;
        };
        
        bool ans = true;
        for(int i = 0 ; i < n ; i++){
            if(visited[i] == -1)
                ans = ans && bfs(i);
        }
        return ans;
    }
};