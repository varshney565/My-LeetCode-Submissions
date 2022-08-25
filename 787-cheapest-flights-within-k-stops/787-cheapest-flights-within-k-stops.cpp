class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        int E = flights.size();
        vector<int> dis(V,INT_MAX);
        dis[src] = 0;
        for(int i = 1 ; i <= k ; i++){
            vector<int> disU(V,INT_MAX);
            for(int i = 0 ; i < V ; i++){
                disU[i] = dis[i];
            }
            bool ok = false;
            for(int j = 0 ; j < E ; j++){
                int u = flights[j][0],v = flights[j][1],w = flights[j][2];
                if(dis[u] == INT_MAX)
                    continue;
                int cost = dis[u]+w;
                if(cost < disU[v]){
                    disU[v] = cost;
                    ok = true;
                }
            }
            swap(disU,dis);
            if(!ok)
                break;
        }
        return (dis[dst]==INT_MAX)?-1:dis[dst];
    }
};