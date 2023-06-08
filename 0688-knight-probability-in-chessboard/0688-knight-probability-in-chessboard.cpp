class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int dir[][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
        double dp[n+1][n+1][k+1];
        memset(dp,0.0,sizeof(dp));
        function<double(int,int,int)> go = [&](int x,int y,int k){
            if(k == 0) return dp[x][y][k] = 1.0;
            if(dp[x][y][k] != 0.0) return dp[x][y][k];
            for(int i = 0 ; i < 8 ; i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx >= 0 && newx < n && newy >= 0 && newy < n){
                    dp[x][y][k] += go(newx,newy,k-1);
                }
            }
            return dp[x][y][k] /= 8.0;
        };
        return go(row,column,k);
    }
};