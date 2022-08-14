class Solution {
public:
    void dfs(string source,vector<string> &ans,map<string,vector<string>> &graph){
        while(graph[source].size() > 0){
            string child = graph[source].back();
            graph[source].pop_back();
            dfs(child,ans,graph);
        }
        ans.push_back(source);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>> graph;
        int n = tickets.size();
        for(int i = 0 ; i < n ; i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto &[a,x] : graph){
            sort(x.begin(),x.end(),greater<string>());
        }
        vector<string> ans;
        dfs("JFK",ans,graph);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};