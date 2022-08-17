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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        dsu Alice(n+1),Bob(n+1);
        int m = edges.size();
        sort(edges.begin(),edges.end(),[](const vector<int>&a,const vector<int> &b){
            return a[0] > b[0];
        });
        
        for(int i = 0 ; i < m ; i++){
            if(edges[i][0] == 1){
                if(!Alice.unite(edges[i][1],edges[i][2]))
                    ans++;
            }else if(edges[i][0] == 2){
                if(!Bob.unite(edges[i][1],edges[i][2]))
                    ans++;
            }else{
                bool ok1 = Alice.unite(edges[i][1],edges[i][2]);
                bool ok2 = Bob.unite(edges[i][1],edges[i][2]);
                
                if(!ok1 && !ok2) ans++;
            }
        }
        int cntAlice = 0;
        int cntBob = 0;
        for(int i = 1 ; i <= n ; i++){
            if(Alice.p[i] == i){
                cntAlice++;
            }
            if(Bob.p[i] == i){
                cntBob++;
            }
            if(cntAlice > 1 || cntBob > 1)
                return -1;
        }
        return ans;
    }
};