class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        function<bool(int,int)> dfs = [&](int x,int y){
            grid[x][y] = 1;
            bool ans = true;
            if(x == n-1 || y == m-1 || x == 0 || y == 0)
                ans = false;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0){
                    ans = (dfs(newX,newY) && ans);
                }
            }
            return ans;
        };
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    bool ok = dfs(i,j);
                    if(ok){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};