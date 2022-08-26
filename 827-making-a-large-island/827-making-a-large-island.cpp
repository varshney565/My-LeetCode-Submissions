class dsu{
    public:
    vector<int> p;
    vector<int> s;
    dsu(int n){
        p.resize(n);
        iota(p.begin(),p.end(),0);
        s.resize(n,1);
    }
    int get(int n){
        if(p[n] == n) return n;
        return p[n] = get(p[n]);
    }
    bool unite(int a,int b){
        int p1 = get(a);
        int p2 = get(b);
        if(p1 == p2) return false;
        p[p2] = p1;
        s[p1] += s[p2];
        return true;
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        dsu d(n*m);
        int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    for(int k = 0 ; k < 4 ; k++){
                        int newX = i+dir[k][0];
                        int newY = j+dir[k][1];
                        if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY]){
                            d.unite(i*m+j,newX*m+newY);
                        }
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    int size = d.s[d.get(i*m+j)];
                    ans = max(ans,size);
                }else{
                    int t = 1;
                    set<int> FoundParents;
                    for(int k = 0 ; k < 4 ; k++){
                        int newX = i+dir[k][0];
                        int newY = j+dir[k][1];
                        if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY]){
                            int p = d.get(newX*m+newY);
                            if(FoundParents.find(p) == FoundParents.end()){
                                t += d.s[p];
                                FoundParents.insert(p);
                            }
                        }
                    }
                    ans = max(ans,t);
                }
            }
        }
        return ans;
    }
};