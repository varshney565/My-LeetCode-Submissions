class dsu{
public:
    vector<int> p;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
    }

    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }

    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2){
            return false;
        }
        p[p1] = p2;
        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> Edges;
        int n = points.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int w = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                Edges.push_back({i,j,w});
            }
        }
        sort(Edges.begin(),Edges.end(),[](const vector<int>&a,const vector<int>&b){
            return a[2] < b[2];
        });
        dsu D(n);
        int dist = 0;
        for(int i = 0 ; i < Edges.size() ; i++){
            if(D.unite(Edges[i][0],Edges[i][1])){
                dist += Edges[i][2];
            }
        }
        return dist;
    }
};