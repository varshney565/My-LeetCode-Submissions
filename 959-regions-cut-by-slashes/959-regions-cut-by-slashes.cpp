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
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = m+1;
        dsu d(n*n);
        for(int i = 0 ; i < n ; i++){
            d.unite(0,i);
            d.unite((n-1)*n+i,0);
            d.unite(i*n,0);
            d.unite(i*n+n-1,0);
        }
        int ans = 1;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '/'){
                    if(!d.unite(i*n+j+1,(i+1)*n+j))
                        ans++;
                }else if(grid[i][j] == '\\'){
                    if(!d.unite(i*n+j,(i+1)*n+j+1))
                        ans++;
                }
            }
        }
        return ans;
    }
};