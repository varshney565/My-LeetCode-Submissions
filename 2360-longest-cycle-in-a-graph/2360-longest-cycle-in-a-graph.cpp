class Solution {
public:
    void dfs(int u,vector<int>&edges,int time,vector<int> &visited,int &ans){
        visited[u] = time;
        int v = edges[u];
        if(v == -1){
            visited[u] = -1;
            return;
        }
        if(visited[v]){
            if(visited[v] > 0)
                ans = max(ans,time-visited[v]+1);
        }else{
            dfs(v,edges,time+1,visited,ans);
        }
        visited[u] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        int ans = 0;
        for(int i = 0 ; i  < n ; i++){
            if(!visited[i]){
                dfs(i,edges,1,visited,ans);
            }
        }
        return ((ans==0)?-1:ans);
    }
};