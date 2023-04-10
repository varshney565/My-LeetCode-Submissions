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
        vector<vector<int>> dp(n,vector<int>(26,0));
        function<bool(int)> dfs = [&](int src){
            visited[src] = 1;
            for(auto child : graph[src]){
                if(visited[child] == 0){
                    bool ans = dfs(child);
                    if(!ans) return ans;
                }else if(visited[child] == 1){
                    return false;
                }
                for(int j = 0 ; j < 26 ; j++){
                    dp[src][j] = max(dp[src][j],dp[child][j]);
                }
            }
            dp[src][colors[src]-'a']++;
            visited[src] = 2;
            return true;
        };
        
        for(int i = 0 ; i < n ; i++){
            if(indeg[i] == 0){
                bool res = dfs(i);
                if(!res) return -1;
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]) return -1;
            if(indeg[i] == 0){
                for(int j = 0 ; j < 26 ; j++){
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};