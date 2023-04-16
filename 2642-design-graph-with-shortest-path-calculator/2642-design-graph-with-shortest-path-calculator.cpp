class Graph {
public:
    
     class Edge{
        public:
            int v,w;
            Edge(int v,int w){
                this->v = v;
                this->w = w;
            }
    };

    
    vector<vector<Edge>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(auto &x : edges){
            int u = x[0];
            int v = x[1];
            int w = x[2];
            graph[u].push_back(Edge(v,w));
        }
    }
    
    void addEdge(vector<int> x) {
        int u = x[0];
        int v = x[1];
        int w = x[2];
        graph[u].push_back(Edge(v,w));
    }
    
    int shortestPath(int src, int dest) {
        int n = graph.size();
        set<pair<int,int>> pq;
        pq.insert({0,src});
        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        while(!pq.empty()){
            //pop the element with minimum wsf
            auto t = *pq.begin();
            pq.erase(t);
            int wsf = t.first;
            int u = t.second;
            if(dis[u] < wsf) continue;
            if(dest == u) return dis[dest];
            //go to all the unvisited neibhours of src and relex them.
            for(auto child : graph[u]){
                if(wsf+child.w < dis[child.v]){
                    pq.erase({dis[child.v],child.v});
                    dis[child.v] = wsf+child.w;
                    pq.insert({dis[child.v],child.v});
                }
            }
        }
        return dis[dest] == INT_MAX ? -1 : dis[dest];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */