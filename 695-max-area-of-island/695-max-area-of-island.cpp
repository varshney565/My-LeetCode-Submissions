class Solution {
public:
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
          if(p1 == p2){
              return false;
          }
          p[p1] = p2;
          s[p2] += s[p1];
          return true;
      }
    };
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dsu D(n*m);
        bool ok = false;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!grid[i][j]) continue;
                ok = true;
                for(int k = 0 ; k < 4 ; k++){
                    int newI = i+dir[k][0];
                    int newJ = j+dir[k][1];
                    if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 1){
                        D.unite(i*m+j,newI*m+newJ);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n*m ; i++){
            if(D.p[i] == i){
                ans = max(ans,D.s[i]);
            }
        }
        if(!ok) return 0;
        return ans;
    }
};