class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& v, int k) {
        if(n == 1) {
            return 1;
        }
        
        vector<long long> values;
        for(int i = 0 ; i < n ; i++) {
            values.push_back(v[i]);
        }
        vector<vector<int>> adj(n,vector<int>());
        vector<int> deg(n,0);
        for(int i = 0 ; i < n - 1 ; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        
        int cnt = n;
        queue<int> PendingNodes;
        vector<int> visited(n,false);
        for(int i = 0 ; i < n ; i++) {
            if(deg[i] == 1) {
                PendingNodes.push(i);
                visited[i] = true;
                cnt--;
            }
        }
        
        int ans = 0;
        while(!PendingNodes.empty()) {
            int front = PendingNodes.front();
            PendingNodes.pop();
            for(auto child : adj[front]) {
                if(visited[child]) {
                    continue;
                }
                deg[child]--;
                if(values[front] % k != 0) {
                    values[child] += values[front];
                }
                if(deg[child] == 1) {
                    PendingNodes.push(child);
                    if(cnt > 1)
                        visited[child] = true;
                    cnt--;
                }
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(values[i]%k == 0) {
                ans++;
            }
        }
        return ans;
    }
};
