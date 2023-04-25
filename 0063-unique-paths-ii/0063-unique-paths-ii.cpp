class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dir[][2] = {{-1,0},{0,-1}};
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        function<int(int,int)> go = [&](int x,int y){
            if(obstacleGrid[x][y] == 1) return dp[x][y] = 0;
            if(x == 0 && y == 0) return dp[x][y] = 1;
            if(dp[x][y] != -1) return dp[x][y];
            int ans = 0;
            for(int i = 0 ; i < 2 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newy >= 0){
                    ans += go(newx,newy);
                }
            }
            return dp[x][y] = ans;
        };
        return go(m-1,n-1);
    }
};