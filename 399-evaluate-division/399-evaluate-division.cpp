class Solution {
public:
    
    double dfs(string u,string v,map<string,vector<pair<string,double>>> &graph,set<string>&visited){
        if(u == v){
            return 1;
        }
        visited.insert(u);
        for(auto child : graph[u]){
            if(visited.find(child.first) == visited.end()){
                double ans = dfs(child.first,v,graph,visited);
                if(ans >= 0){
                    return ans*child.second;
                }
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> graph;
        int i = 0;
        for(auto equation : equations){
            string u = equation[0];
            string v = equation[1];
            double w = values[i];
            graph[u].push_back({v,w});
            graph[v].push_back({u,1.0/w});
            i++;
        }
        vector<double> ans;
        for(auto query : queries){
            string u = query[0];
            string v = query[1];
            set<string> visited;
            if(graph.find(v) == graph.end()){
                ans.push_back(-1);
            }else{
                ans.push_back(dfs(u,v,graph,visited));
            }
        }
        return ans;
    }
};