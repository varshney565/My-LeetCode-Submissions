class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        function<void(int,int,int&)> dfs = [&](int x,int y,int &val){
            if(grid1[x][y] == 0){
                val = -1;
            }
            grid2[x][y] = 0;
            for(int i = 0 ; i < 4 ; i++){
                int newX = x+dir[i][0];
                int newY = y+dir[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid2[newX][newY] == 1){
                    dfs(newX,newY,val);
                }
            }
        };
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1){
                    int t = 0;
                    dfs(i,j,t);
                    if(t == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};