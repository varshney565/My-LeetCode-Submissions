class Solution {
public:
    class Edge{
      public:
        int v,w;
        Edge(int v,int w){
            this->v = v;
            this->w = w;
        }
    };
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<Edge>> graph(n);
        for(int i = 0 ; i < roads.size() ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            graph[u].push_back(Edge(v,w));
            graph[v].push_back(Edge(u,w));
        }
        
        const int mod = 1e9+7;
        vector<long> dis(n,LLONG_MAX);
        vector<int> cnt(n,0);
        set<pair<long,int>> PendingNodes;
        PendingNodes.insert({0,0});
        cnt[0] = 1;
        while(!PendingNodes.empty()){
            auto front = *PendingNodes.begin();
            PendingNodes.erase(front);
            long currentWSF = front.first;
            int currentNode = front.second;
            if(dis[currentNode] < currentWSF) continue;
            for(auto child : graph[currentNode]){
                if(dis[child.v] > currentWSF + child.w){
                    PendingNodes.erase({dis[child.v],child.v});
                    dis[child.v] = currentWSF + child.w;
                    cnt[child.v] = cnt[currentNode];
                    PendingNodes.insert({dis[child.v],child.v});
                }else if(dis[child.v] == currentWSF + child.w){
                    cnt[child.v] = (cnt[child.v] + cnt[currentNode])%mod;
                }
            }
        }
        return cnt[n-1];
    }
};