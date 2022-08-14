class Solution {
public:
    
    bool dfs(string source,vector<string> &ans , map<string,vector<string>> &graph,int total){
        ans.push_back(source);
        if(ans.size() == total+1)
            return true;
        if(graph.find(source) == graph.end()){
            ans.pop_back();
            return false;
        }
        for(int i = 0 ; i < graph[source].size() ; i++){
            string child = graph[source][i];
            graph[source].erase(graph[source].begin()+i);
            if(dfs(child,ans,graph,total))
                return true;
            graph[source].insert(graph[source].begin()+i,child);
            // graph[source].push_back(child);
        }
        ans.pop_back();
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>> graph;
        for(int i = 0 ; i < tickets.size() ; i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        int n = tickets.size();
        for(auto &[a,x] : graph){
            cout<<a<<" : ";
            sort(x.begin(),x.end());
            for(auto t : x){
                cout<<t<<" ";
            }
            cout<<"\n";
        }
        vector<string> ans;
        dfs("JFK",ans,graph,n);
        return ans;
    }
};