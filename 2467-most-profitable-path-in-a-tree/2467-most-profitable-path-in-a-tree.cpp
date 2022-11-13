class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n,vector<int>());
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> bobTime(n,INT_MAX);
        function<int(int,int)> dfs = [&](int u,int p){
            if(u == bob)
                return bobTime[u] = 0;
            for(auto child : adj[u]){
                if(child == p){
                    continue;
                }
                int result = dfs(child,u);
                if(result >= 0){
                    bobTime[u] = result+1;
                    return result+1;
                }
            }
            return -1;
        };
        dfs(0,-1);
        
        function<int(int,int,int)> go = [&](int u,int p,int time){
            int ans = 0;
            if(time < bobTime[u])
                ans += amount[u];
            else if(time == bobTime[u])
                ans += amount[u]/2;
            if(adj[u].size() == 1 && u) return ans;
            int smallAns = INT_MIN;
            for(auto child : adj[u]){
                if(child == p)
                    continue;
                smallAns = max(smallAns,go(child,u,time+1));
            }
            return ans+smallAns;
        };
        return go(0,-1,0);
    }
};
