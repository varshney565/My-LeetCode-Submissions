class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indeg(n,0);
        for(int i = 0 ; i < edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        vector<int> visited(n,0);
        int ans = -1;
        vector<vector<int>> dp(n,vector<int>(26,0));
        int nodes = 0;
        function<int(int)> dfs = [&](int src){
            visited[src] = 1;
            nodes++;
            for(auto child : graph[src]){
                if(visited[child] == 0){
                    int a = dfs(child);
                    if(a == -1) return a;
                }else if(visited[child] == 1){
                    return -1;
                }
                for(int j = 0 ; j < 26 ; j++){
                    dp[src][j] = max(dp[src][j],dp[child][j]);
                }
            }
            dp[src][colors[src]-'a']++;
            for(int j = 0 ; j < 26 ; j++){
                ans = max(ans,dp[src][j]);
            }
            visited[src] = 2;
            return ans;
        };
        
        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0){
                int res = dfs(i);
                if(res == -1) return -1;
            }
        }

        return nodes == n ? ans : -1;
    }
};