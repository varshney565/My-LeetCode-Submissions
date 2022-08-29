class Solution {
public:
    
    double go(int u,int p,int t,vector<vector<int>>&graph,int &target){
        //i have reached a node which is depth t
        if(t == 0){
            if(u == target)
                return 1;
            return 0;
        }
        //i reached a leaf and we know we can't move from that node anywhere,
        if(graph[u].size() == 0 || ((graph[u].size() == 1) && (p == graph[u][0]))){
            if(u == target){
                return 1;
            }
            return 0;
        }

        for(int i = 0 ; i < graph[u].size() ; i++){
            if(graph[u][i] == p)
                continue;
            double output = go(graph[u][i],u,t-1,graph,target);
            if(output){
                if(p != -1)
                    output /= (graph[u].size()-1);
                else
                    output /= graph[u].size();
                return output;
            }
        }
        return 0;
    };
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        target--;
        //what i have to do?
        //i have to do till the depth t and find if target i there at depth t or not?
        //if yes return 1 else return 0
        
        return go(0,-1,t,graph,target);
    }
};